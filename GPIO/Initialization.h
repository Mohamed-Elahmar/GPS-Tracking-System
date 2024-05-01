#ifndef Initialization
#define Initialization


#define PA_mask 0x0001
#define PB_mask 0x0002
#define PB_PINS_mask 0xFF // if we will use all pins 
#define PF_mask 0x20
#define PF123_mask 0x0E
#define PF4_mask 0x10
#define PF0_mask 0x01




void PORTB_init(void);
										 /*initialization for Port B*/

void LED_Init(void);
										 /*initialization for LED*/

void SW1_Init(void);
										 /*initialization for Switch 1*/

void SW2_Init(void);
										 /*initialization for Switch 2*/

#endif