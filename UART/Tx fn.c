#include "tm4c123gh6pm.h"
void UART_Tx(char Data){
while ((UART0_FR_R & 0X0020) !=0); 
//Checking the fifo if it's full or not so I can pass data 
UART0_DR_R = Data;
}
