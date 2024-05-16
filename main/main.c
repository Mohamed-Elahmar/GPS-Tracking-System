#include "UART0.h"
#include "LED.h"
#include "Switch.h"
#include "Initialization.h"
#include "DistanceFunction.h"
#include "uart.h"
#include "eeprom.h"
#include "trajectory.h"
#include "bit_utilies.h"
#include "timer.h"
#include "hw_memmap.h"
#include "hw_sysctl.h"
#include "hw_types.h"
#include "hw_uart.h"
#include <stdint.h>
#include <stdbool.h>
#include <String.h>
#include "sysctl.h"
#include "hw_ints.h"
#include "hw_nvic.h"
#include "hw_flash.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <net_config.h>

#define U 0x55


	  int longcounter;
	 int latcounter;
		uint32_t Trajectory_Points[202] ;
	  extern float currentDistance;
	float DistanceAcc ;
		float Trajectory [202]={0};
		
		uint32_t long_int1[101];
		uint32_t lat_int1[101];
		uint32_t long_int2[101];
		uint32_t lat_int2[101];
		uint32_t dis_acc1[1];
		uint32_t dis_acc2[1];
		int s;
		char Urecieved;
		int sentflag;
char str[9]; // Assuming a maximum of 20 characters for the string representation
char strs[5];
    // Convert integer to string


void printString(char *p){
	while(*p)
	{
		UART0_Tx(*p);
		p++;
	}	
}
		
void send_coordinates(){
	s=0;
while(1){
	if(lat_int1[s]==0)break;
	sprintf(str, "%d", lat_int1[s]);
	printString(str);
	s++;
 printString("\n");
}
printString("latdone\n\n");
s=0;
while(1){
	
		if(long_int1[s]==0) break;
sprintf(str, "%d", long_int1[s]);
	printString(str);
	s++;
printString("\n");
}
printString("logdone\n\n");

sprintf(strs, "%d",dis_acc1[0] );
printString(strs);
printString("\n");
printString("done\n\n");
}
void eeprom_read(){
SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

SysCtlPeripheralEnable(SYSCTL_PERIPH_EEPROM0);
EEPROMInit();	
EEPROMRead((uint32_t*)&lat_int2,0x0000,sizeof(lat_int2));
EEPROMRead((uint32_t*)&long_int2,0x200,sizeof(long_int2));
EEPROMRead((uint32_t*)&dis_acc2,0x400,sizeof(dis_acc2));

}

 int main(){	
		uint32_t mul;//define new var
		int j ;
		int i;
		char temp;
		
	
		UART0_Init();
		UART2_Init();
	

	
		PORTB_init();      	
		LED_Init();
		SW1_Init();
	
	
	while(1){
	DistanceAcc=start_walking(Trajectory);
	// to show in the screen  , array of one element 
	dis_acc1[0] = DistanceAcc ;
		
for(i =0; i < (sizeof(Trajectory) / sizeof(Trajectory[0])) ; i++)	{
  UART0_Tx((char)Trajectory[i]);
mul=Trajectory[i]*100000;//define mul and multiply with 100000 to avoid floaing point problem	
Trajectory_Points[i] = mul;//removing the cast
}
longcounter=0;
latcounter=0;
// to seperate the array into two arrays
for(i=0;i<(sizeof(Trajectory_Points) / sizeof(Trajectory_Points[0])); i++ ){
	if(i%2==0){ 
	long_int1[longcounter]=Trajectory_Points[i];
		longcounter++;
	}
	
	else{
	lat_int1[latcounter]=Trajectory_Points[i];
		latcounter++;
}
	}
//to save the data in eeprom , after pressing the switch 
 			
EEPROMProgram((long_int1) , 0x0 , sizeof(long_int1)); //to save the long
EEPROMProgram((lat_int1) , 0x2 , sizeof(lat_int1));//to save the lat 
EEPROMProgram((dis_acc1) , 0x4 , sizeof(dis_acc1));//to save the acumlative distance
LED_TurnOff();
GPIO_SetLedValues(LED_BLUE , LED_ON);

//to send the data and read it from eeprom
	
Urecieved=UART0_Rx();
if (sentflag==1){
	
if (Urecieved==U)
{	
eeprom_read();
EEPROMMassErase();
SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN);
SysCtlPeripheralDisable(SYSCTL_PERIPH_EEPROM0);
send_coordinates();
LED_TurnOff();
GPIO_SetLedValues(LED_RED , LED_ON);

 break;
}
 }
	}
}
	
