/*! ADC source File */
#include "stm32f4xx.h"
#include "/home/manish/Product_codes/usb_saturday/STM32F4_USB_CDC/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_adc.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*! ADC Initialazion function */
adcInit(){
     
    	/*! Intialsizing structure to set ADC Configuration */
    	ADC_InitTypeDef ADC_InitStructure;
    	
	/*! Intialsizing structure to set GPIO  Configuration */
	GPIO_InitTypeDef GPIO_InitStructure;

    	/*! Intialsizing structure to set ADC  Common Configuration */
	ADC_CommonInitTypeDef ADC_CommonInitStructure;
	
	
       	/*! Enable ADC1 Interface Clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

	/*! Enable the ADC1 GPIO Clock	*/
      	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 

	/*! Initializing GPIO for ADC */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

	/*! Configuring  ADC GPIO pins in analog mode */

	GPIO_Init(GPIOC, &GPIO_InitStructure);

	/*! ADC Common Init */

	/*! Use Independent mode */
	ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
	ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
	
	/*! 
	 *  Initializes the ADCx peripheral according 
	 *  to the specified ADC parameters in the ADC_CommonInitStruct
	 */

	ADC_CommonInit(&ADC_CommonInitStructure);

	/*! ADC1 Init */
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfConversion = 1;
	
	/*!
	 *  Initializes the ADCx peripheral according 
	 *   to the specified ADC parameters in the ADC_InitStruct. 
         */
	ADC_Init(ADC1, &ADC_InitStructure);
	
	/*! Enabling Temperature sensor */
	ADC_TempSensorVrefintCmd(ENABLE);

	/*! ADC1 regular channel16 configuration */
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_3Cycles);

	/*! Enable(Activate ) ADC1 Peripherals */
	ADC_Cmd(ADC1, ENABLE);

	
    	/*! Intialsizing structure For NVIC Configuration */
	NVIC_InitTypeDef NVIC_InitStructure;
        
	/*! set parameters of NVIC_InitTypeDef structure */
	NVIC_InitStructure.NVIC_IRQChannel = ADC_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	
	/*!
	 * Initializes the NVIC peripheral according
	 *  to the specified parameters in the NVIC_InitStruct
	 */
	NVIC_Init(&NVIC_InitStructure);

}
