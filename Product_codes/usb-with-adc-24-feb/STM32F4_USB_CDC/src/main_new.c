#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "stm32f4xx_conf.h"
#include "stm32f4xx.h"
#include "/home/manish/Product_codes/Verified-Codes/my-usb_friday/STM32F4_USB_CDC/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_adc.h"
#include "main.h"


#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

#include <arm_math.h>
#include <math_helper.h>


#include "usbd_cdc_core.h"
#include "usbd_usr.h"
#include "usbd_desc.h"
#include "usbd_cdc_vcp.h"

// Private variables
volatile uint32_t time_var1, time_var2;
__ALIGN_BEGIN USB_OTG_CORE_HANDLE  USB_OTG_dev __ALIGN_END;



/*! Macros realated to array size   */
#define MAX_COUNT 3
#define DEFAULT_WINDOW_SIZE 100 
#define SIZE 1000
#define TEST_LENGTH_SAMPLES 320 /*! Final output array size */
#define BLOCK_SIZE 32 
#define NUM_TAPS 29 

xTimerHandle xTimer; 

float tempadcdata[SIZE]={0.0};  /*! stores adc data */
float adcValue[SIZE] = {0.0};
float moving_avg[SIZE]={0.0};
float avg_arr[TEST_LENGTH_SAMPLES]={0.0};    /*! stores average of input samples which is input to the filter */
static float filterOutput[TEST_LENGTH_SAMPLES];  /*! Declare Test output buffer */
static float firStateF32[BLOCK_SIZE + NUM_TAPS - 1];  /*! Declare State buffer of size (numTaps + blockSize - 1) */

/* ---------------------------------------------------------------------- 
** FIR Coefficients buffer generated using fir1() MATLAB function. 
** fir1(28, 6/24)
** ------------------------------------------------------------------- */ 
 
const float firCoeffs32[NUM_TAPS] = { 
-0.0018225230f, -0.0015879294f, +0.0000000000f, +0.0036977508f, +0.0080754303f, +0.0085302217f, -0.0000000000f, -0.0173976984f, 
-0.0341458607f, -0.0333591565f, +0.0000000000f, +0.0676308395f, +0.1522061835f, +0.2229246956f, +0.2504960933f, +0.2229246956f, 
+0.1522061835f, +0.0676308395f, +0.0000000000f, -0.0333591565f, -0.0341458607f, -0.0173976984f, -0.0000000000f, +0.0085302217f, 
+0.0080754303f, +0.0036977508f, +0.0000000000f, -0.0015879294f, -0.0018225230f 
}; 
uint32_t blockSize = BLOCK_SIZE; /*! Global variable for FIR LPF Example */ 
uint32_t numBlocks = TEST_LENGTH_SAMPLES/BLOCK_SIZE;/*! Global variable for FIR LPF Example */  
 
uint32_t count = 0;

uint32_t ADCx = ADC1;
uint32_t USARTx = USART1;



// Private function prototypes
void Delay(volatile uint32_t nCount);
void init();
void calculation_test();

static void AdcTask(void *pvParameters){

	ADC_SoftwareStartConv(ADCx);
   	ADC_ITConfig(ADCx,ADC_IT_EOC,ENABLE);
	while(1){

		ADC_GetFlagStatus(ADCx,ADC_FLAG_EOC);		

		/*! Wait Until Transmit Finishes */
	        while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);
		USART_SendData(USARTx,adcValue[count++]);
	}
}

void initx(){

    adcInit();
    usartInit();

}

int get_sum(int arr[], int size, int from_index, int to_index)
{
	uint32_t sum = 0;
	uint32_t i;
	
	for(i = from_index; size>i && to_index>i; ++i)
		sum += arr[i];

	return sum;
}/*! end of get_average() */

void filterADC(xTimerHandle xTimer ){
	
	uint32_t i=0;/*! index for data array */
	uint32_t j = 0; /*! index for avg_arr */
	uint32_t k;
        uint32_t basic_avg = 0; 
        static uint32_t from_index = 0;
	static uint32_t to_index= 0 ;
        arm_fir_instance_f32 S;
        float32_t  *inputF32, *outputF32; 
        inputF32 = &avg_arr[0];/*! Initialize input and output buffer pointers */	 
        outputF32 = &filterOutput[0]; 

	
       do
       	{
		tempadcdata[i++] = adcValue[i++];
		i++;
	}while(i<count);
        count=0;
        while(from_index < SIZE)
	{
		avg_arr[j++] = (get_sum(tempadcdata, SIZE, from_index, to_index + DEFAULT_WINDOW_SIZE ) / DEFAULT_WINDOW_SIZE ) ;
		to_index += DEFAULT_WINDOW_SIZE;
		from_index += DEFAULT_WINDOW_SIZE;
	}

       /*! Call FIR init function to initialize the instance structure. */
       arm_fir_init_f32(&S, NUM_TAPS, (float32_t *)&firCoeffs32[0], &firStateF32[0], blockSize); 

       for(k=0; k < numBlocks; k++)  
       {	 
         arm_fir_f32(&S, inputF32 + (k * blockSize), outputF32 + (k * blockSize), blockSize);  
       } 
 
	while(from_index < TEST_LENGTH_SAMPLES)
	{
	basic_avg = (get_sum(outputF32, TEST_LENGTH_SAMPLES, from_index, to_index + DEFAULT_WINDOW_SIZE ) / DEFAULT_WINDOW_SIZE)  ;
		 moving_avg[0]=basic_avg ;
		for(i=1;i< TEST_LENGTH_SAMPLES;i++)
		{
		   moving_avg[i]=( moving_avg[i-1] + filterOutput[i+DEFAULT_WINDOW_SIZE]) /2;
	       }
   }
}
/*void ADC_IRQHandler(void){

	if ( count >= 1000)
		return;	
	adcValue[count++] = (float)ADC_GetConversionValue(ADCx);
         
}*/



int main(void) {
	init();
         
       initx();
	
	/*
	 * Disable STDOUT buffering. Otherwise nothing will be printed
	 * before a newline character or when the buffer is flushed.
	 */

        setbuf(stdout, NULL);
        xTimer = xTimerCreate("Timer",100,pdTRUE,( void * ) 0,filterADC);
	xTimerStart( xTimer,0);

	xTaskCreate(AdcTask, (signed char*)"AdcTask", 128, NULL, tskIDLE_PRIORITY+1, NULL);
	
	calculation_test();


	vTaskStartScheduler();
	for(;;) {
		GPIO_SetBits(GPIOD, GPIO_Pin_12);
		Delay(500);
		GPIO_ResetBits(GPIOD, GPIO_Pin_12);
		Delay(500);
	}

	return 0;
}

void calculation_test() {
	float a = 1.001;
	int iteration = 0;

	for(;;) {
		GPIO_SetBits(GPIOD, GPIO_Pin_12);
		Delay(500);
		GPIO_ResetBits(GPIOD, GPIO_Pin_12);
		Delay(500);

		time_var2 = 0;
		for (int i = 0;i < 1000000;i++) {
			a += 0.01 * sqrtf(a);
		}
              printf("ADC Data:........");
            for (int adc_var=0; adc_var < SIZE ; adc_var++)
               {
               
               printf("ADC Data %f\n\r",adcValue[adc_var]);    
		printf("Time:      %lu ms\n\r", time_var2);
		printf("Iteration: %i\n\r", iteration);
		printf("Value:     %.5f\n\n\r", a);
                }
		iteration++;
	}
}

void init() {
	GPIO_InitTypeDef  GPIO_InitStructure;

	// ---------- SysTick timer -------- //
	if (SysTick_Config(SystemCoreClock / 1000)) {
		// Capture error
		while (1){};
	}

	// ---------- GPIO -------- //
	// GPIOD Periph clock enable
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	// Configure PD12, PD13, PD14 and PD15 in output pushpull mode
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	// ------------- USB -------------- //
	USBD_Init(&USB_OTG_dev,
	            USB_OTG_FS_CORE_ID,
	            &USR_desc,
	            &USBD_CDC_cb,
	            &USR_cb);
}



void ADC_IRQHandler(void){

	if ( count >= 1000)
		return;	
	adcValue[count++] = (float)ADC_GetConversionValue(ADCx);
         
}


/*
 * Called from systick handler
 */
void timing_handler() {
	if (time_var1) {
		time_var1--;
	}

	time_var2++;
}






/*
 * Delay a number of systick cycles (1ms)
 */
void Delay(volatile uint32_t nCount) {
	time_var1 = nCount;
	while(time_var1){};
}


