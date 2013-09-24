
/*! USART Source File */
#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*! USART initialization */
usartInit(){
	/*! Structure With Data For USART Configuration */
	USART_InitTypeDef USART_InitStructure;
	
        /*! Structure for GPIO(Perpherals) configuration */
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*! Setup USART2 TX Pin As Alternate Function */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(GPIOA, &GPIO_InitStructure);

	/*! Enable GPIO Clocks For USART2 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	/*! Enable Clocks for USART2 */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

	/*! USART Parameters */
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
        USART_InitStructure.USART_StopBits = USART_StopBits_1;
        USART_InitStructure.USART_Parity = USART_Parity_No ;
        USART_InitStructure.USART_Mode = USART_Mode_Tx;
        USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

	/*! Configuring And Enabling USART2 */
	USART_Init(USART1,&USART_InitStructure);
        USART_Cmd(USART1, ENABLE);
}
