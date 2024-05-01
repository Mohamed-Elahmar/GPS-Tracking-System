#include "Switch.h"
#include "LED.h"
#include "bit_utilies.h"
#include "TM4C123.h"
#include "Initialization.h"








unsigned char SW1_Input(void){    
return GPIO_PORTF_DATA_R & PF0_mask;
}




/*Coordinates Saved in EPROM*/

void SW1_Pressed(void)            
{
	unsigned char Button1=SW1_Input();
	if(Button1)
		{
			LED_TurnOff();
			GPIO_SetLedValues(LED_GREEN	,LED_ON	);
		}
}

