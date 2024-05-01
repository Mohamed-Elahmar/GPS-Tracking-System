#include "tm4c123gh6pm.h" 
#include "TM4C123.h"
#include "Initialization.h"



void PORTB_init(void){
SYSCTL_RCGCGPIO_R 	|= PB_mask;
while((SYSCTL_PRGPIO_R & PB_mask) == 0);	
GPIO_PORTB_LOCK_R 	= GPIO_LOCK_KEY ;
GPIO_PORTB_CR_R 		|= PB_PINS_mask;
GPIO_PORTB_AMSEL_R  &= ~PB_PINS_mask;
GPIO_PORTB_AFSEL_R  &= ~PB_PINS_mask;	
GPIO_PORTB_PCTL_R   &= ~0xFFFFFFFF;		// if we will use all pins 
GPIO_PORTB_DEN_R 		|= PB_PINS_mask;
GPIO_PORTB_DIR_R 		|= PB_PINS_mask;
GPIO_PORTB_DATA_R 	&= ~PB_PINS_mask;
}

// LEDs --> Port F pins 1,2,3
 void LED_Init(void){
 SYSCTL_RCGCGPIO_R |= PF_mask; // enable clock for port F
 while((SYSCTL_PRGPIO_R & PF_mask)==0); // check that clock is enabled for port F
 GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY; // unlock port F using value 0x4C4F434B from datasheet
 GPIO_PORTF_CR_R |= PF123_mask; // allow changes to pins 1,2,3 in port F
 GPIO_PORTF_AMSEL_R &= ~ PF123_mask; // disable analog
GPIO_PORTF_AFSEL_R &= ~ PF123_mask; // disable alternate function
GPIO_PORTF_PCTL_R &= ~ 0x0000FFF0; // clear bits in PCTL
 GPIO_PORTF_DIR_R |= PF123_mask; // enable output direction for pins 1,2,3 in port F
GPIO_PORTF_DEN_R |= PF123_mask; // enable digital I/O
 GPIO_PORTF_DATA_R &= ~ PF123_mask; // LEDs are initially OFF
 }

 // Switch SW1 --> Port F pin 4
 void SW1_Init(void){
 GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY; // unlock port F using value 0x4C4F434B from datasheet
 GPIO_PORTF_CR_R |= PF4_mask; // allow changes to pin 4 in port F
 GPIO_PORTF_AMSEL_R &= ~ PF4_mask; // disable analog
 GPIO_PORTF_AFSEL_R &= ~ PF4_mask; // disable alternate function
 GPIO_PORTF_PCTL_R &= ~ 0x000F0000; // clear bits in PCTL
 GPIO_PORTF_DIR_R &= ~ PF4_mask; // enable input direction for pin 4 in port F
 GPIO_PORTF_DEN_R |= PF4_mask; // enable digital I/O
 GPIO_PORTF_PUR_R = PF4_mask;
 }

 // Switch SW2 --> Port F pin 0
 void SW2_Init(void){
GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY; // unlock port F using value 0x4C4F434B from datasheet
GPIO_PORTF_CR_R |= PF0_mask; // allow changes to pin 0 in port F
GPIO_PORTF_AMSEL_R &= ~ PF0_mask; // disable analog
GPIO_PORTF_AFSEL_R &= ~ PF0_mask; // disable alternate function
GPIO_PORTF_PCTL_R &= ~ 0x0000000F; // clear bits in PCTL
GPIO_PORTF_DIR_R &= ~ PF0_mask; // enable input direction for pin 4 in port F
GPIO_PORTF_DEN_R |= PF0_mask; // enable digital I/O
GPIO_PORTF_PUR_R = PF0_mask;
 }






