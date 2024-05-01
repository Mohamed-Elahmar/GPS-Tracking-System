#ifndef LED
#define LED

#define LED_RED  	 				1
#define LED_BLUE 					2
#define LED_GREEN	        3


#define LED_OFF           0
#define LED_ON						1


void LED_initPortF(void);
												/*Initialization For Port F To Turn LEDs On and Off*/
												
void LED_TurnOff(void);
												/*To Turn the LEDs Off*/
												
unsigned char GPIO_GetSwitchesValues(unsigned char sw);
												/*Get Values of Switches*/
	
void GPIO_SetLedValues(unsigned char LedColor,unsigned char LedState);
												/*Set Values of LEDs On and Off*/






/********************************** THIS SECTION IS UNDER TERMINATED  **********************************/
#define GPIO_LOCK_KEY 0x4C4F434B // Unlocks the GPIO_CR register

#define GPIO_sw1				1
#define	GPIO_sw2				2	









#endif