#include "LED.h"
#include "bit_utilies.h"
#include "Switch.h"
#include "Initialization.h"
#include "TM4C123.h"

 


int main(void)
{
	unsigned char button1;
	LED_Init();
										 /*initialization for LED*/

	SW1_Init();
										 /*initialization for Switch 1*/

	
	while(1){
		
		button1 = SW1_Input();
		SW1_Pressed();
		
		}
}