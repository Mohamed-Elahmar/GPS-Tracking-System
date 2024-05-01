#include "tm4c123gh6pm.h"

// tiva_clk = 16 MHz
// baudRate = 9600

void UART0_init(void){
SYSCTL_RCGCUART_R  |= 0x0001;   // enable clock of UART0
SYSCTL_RCGCGPIO_R  |= 0x0001;   // enable clock of port A 
UART0_CTL_R  &=~ 0x0001;    // disable UART0
UART0_IBRD_R = 0x68;		    // IBRD = int(Tiva's clk/16*BR) = int(16000000/(16*9600)) = 104 
UART0_FBRD_R = 0xB;		      // FBRD = int(decimal part *64 +0.5) = int(0.1666667*64+0.5) = 11
UART0_LCRH_R = 0x0070;	    // 8-bit word length, enable FIFO 
UART0_CTL_R	 = 0x0301;	    // enable RXE,TXE and UART0
GPIO_PORTA_AFSEL_R |= 0x03;     // enable alternate function in PA0 and  PA1
GPIO_PORTA_PCTL_R  =(GPIO_PORTA_PCTL_R & 0xFFFFFF00)|0x00000011; // configure UART for PA0 and PA1
GPIO_PORTA_DEN_R   |= 0x03; 	 // enable digital I/O in PA0 and PA1 	
GPIO_PORTA_AMSEL_R &= ~0x03;  // disable analog function on PA0 & PA1
}

