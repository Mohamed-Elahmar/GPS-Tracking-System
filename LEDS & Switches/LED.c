#include "LED.h"
#include "bit_utilies.h"
#include "TM4C123.h"
#include "Initialization.h"










unsigned char GPIO_GetSwitchesValues(unsigned char sw)
{
	switch(sw)
	{
		case GPIO_sw2 :return GET_BIT(GPIO_PORTF_DATA_R ,0);
		break;
		case GPIO_sw1 :return	GET_BIT(GPIO_PORTF_DATA_R ,4);
		break;
		default: return 0;
	}
}



void GPIO_SetLedValues(unsigned char LedColor,unsigned char LedState)
{
	switch(LedColor)
		{
		case LED_RED :{
			switch(LedState)
					{
				case LED_OFF :CLR_BIT(GPIO_PORTF_DATA_R ,1);break;
				case LED_ON  :SET_BIT(GPIO_PORTF_DATA_R ,1);break;	
					}
		};break;
		/**/
		case LED_BLUE :{
				switch(LedState)
					{
				case LED_OFF :CLR_BIT(GPIO_PORTF_DATA_R ,2);break;
				case LED_ON  :SET_BIT(GPIO_PORTF_DATA_R ,2);break;	
					}
				};break;
		/**/
		case LED_GREEN :{
				switch(LedState)
					{
				case LED_OFF :CLR_BIT(GPIO_PORTF_DATA_R ,3);break;
				case LED_ON  :SET_BIT(GPIO_PORTF_DATA_R ,3);break;	
					}
				};break;		
		}
}



 void LED_TurnOff()
{
	CLR_BIT(GPIO_PORTF_DATA_R ,1);
	CLR_BIT(GPIO_PORTF_DATA_R ,2);
	CLR_BIT(GPIO_PORTF_DATA_R ,3);
}


