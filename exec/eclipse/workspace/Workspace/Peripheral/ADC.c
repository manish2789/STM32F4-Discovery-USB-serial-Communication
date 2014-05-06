#include "ADC.h"<?xml version="1.0" encoding="ISO-8859-1"?>
 /*! Here is a snapshot of my new application:
   *  \image html ADC.png
   *  \image latex application.eps "My application" width=10cm
 */


<?xml version="1.0" encoding="ISO-8859-1"?> ADC ( ) {
	<?xml version="1.0" encoding="ISO-8859-1"?>
		
		
	static void AdcTask(void *pvParameters){

    	ADC_SoftwareStartConv(ADCx);
       	ADC_ITConfig(ADCx,ADC_IT_EOC,ENABLE);
   	
    	while(1){

        		ADC_GetFlagStatus(ADCx,ADC_FLAG_EOC);		

       	        while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);
    			USART_SendData(USARTx,);
    			
    	}
    }
	
		   
    
    int main(void){

          initx();
	
    	xTaskCreate(AdcTask, (signed char*)"AdcTask", 128, NULL, tskIDLE_PRIORITY+1, NULL);
    
	    vTaskStartScheduler();
	
	}
    
	
}
}