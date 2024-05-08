#include "tm4c123gh6pm.h"
#include "UART0.h"
#include <string.h>



char logFormatted [12][20];  // a 2D array of 12 rows, each row represents a section of GPS_log array 


/*
Description:
A function that reads a complete sentence from the GPS module then cuts it into substrings 

Example of complete sentence:
$GPRMC,203522.0,A,5109.0262308,N,11401.8407342,W,0.004,133.4,130522,0.0,E,D     
  "around 80 characters"

*/

void GPS_Read(){
  
	char GPS_log[80];     
  char logName[] = "$GPRMC";
	
	//Making Sure we recieved the correct Log "$GPRMC"
	char flag = 1;
	do{
		flag =1;
		for (char i=0; i<7; i++){
        if(UART_Rx() != logName[i]){
           flag=0;
           break;   					
				}			
		}
	}while(flag == 0);

	
	//Initializing the log array to null
	strcpy(GPS_log ,"");
	
	
	//Filling the GPS_log array with characters until reaching character '*'
	char charRecieved;
	do{
		
		char logFillCounter = 0;
		charRecieved = UART_Rx();
		GPS_log[logFillCounter] = charRecieved;
		logFillCounter++;
		
	}while(charRecieved != '*');
	
	
	//Cutting GPS_log array into multiple strings 
	char noOfStrings = 0;
	char *p;
	
	p = strtok(GPS_log, ",");
  
	do{
		strcpy(logFormatted[noOfStrings] , p);
	  p = strtok(NULL , ","); 
    noOfStrings++;	
	}while(p != NULL);
		
}





