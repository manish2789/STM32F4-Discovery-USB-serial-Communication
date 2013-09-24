#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "stm32f4xx_conf.h"
#include "stm32f4xx.h"
#include "main.h"

#include "/home/manish/Product_codes/usb-with-adc-24-feb/STM32F4_USB_CDC/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_adc.h"

#include "usbd_cdc_core.h"
#include "usbd_usr.h"
#include "usbd_desc.h"
#include "usbd_cdc_vcp.h"


#define MAX_COUNT 3 
#define SIZE 1000

float adcValue[SIZE];
//uint32_t i;
uint32_t count = 0;

uint32_t ADCx = ADC1;
//uint32_t USARTx = USART1;

// Private variables
volatile uint32_t time_var1, time_var2;
__ALIGN_BEGIN USB_OTG_CORE_HANDLE  USB_OTG_dev __ALIGN_END;

// Private function prototypes
void AdcTask();
void initx();
void Delay(volatile uint32_t nCount);
void init();
void calculation_test();


void AdcTask(){

	ADC_SoftwareStartConv(ADCx);
   	ADC_ITConfig(ADCx,ADC_IT_EOC,ENABLE);
}


void initx(){

    adcInit();

}

	double val =0.0;
void ADC_IRQHandler(void){
 
      val= (float)ADC_GetConversionValue(ADCx);
	
}



int main(void) {
	init();
        initx();

	/*
	 * Disable STDOUT buffering. Otherwise nothing will be printed
	 * before a newline character or when the buffer is flushed.
	 */
	setbuf(stdout, NULL);
        AdcTask();
	calculation_test();
	
	
	for(;;) {
		GPIO_SetBits(GPIOD, GPIO_Pin_12);
		Delay(10);
		GPIO_ResetBits(GPIOD, GPIO_Pin_12);
		Delay(10);
	}

	return 0;
}

void calculation_test() {
	float a = 1.001;
	int iteration = 0;
	for(;;)
	{

	
		GPIO_SetBits(GPIOD, GPIO_Pin_12);
		Delay(10);
		GPIO_ResetBits(GPIOD, GPIO_Pin_12);
		Delay(10);

		time_var2 = 0;

                int j=0;
		printf("ADC Data:  %lf\n",val);
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


