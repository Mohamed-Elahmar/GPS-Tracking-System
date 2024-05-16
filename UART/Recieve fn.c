#include "tm4c123gh6pm.h"
char UART_Rx(void){
//knowing that the UART_FR IS FOR Frame 
while((UART0_FR_R & 0X0010) != 0); // if the it is empty it will not go out from the loop 
//Checking the fifo empty flag for the reciever
return(char)(UART0_DR_R & 0XFF);
// passing the data form the the first 8 bits
}