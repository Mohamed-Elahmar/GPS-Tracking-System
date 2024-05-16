#include "trajectory.h"
#include "tm4c123gh6pm.h"
#include <math.h>
#include "timer.h"
#include <String.h>
#include <stdlib.h>
#include "Initialization.h"
#include "Switch.h"
#include "LED.h"
#include "DistanceFunction.h"


int flagx=0;
float currentDistance;
float DistanceAccstart ;
int k=0;
char rec;

char GPS_log[80];
char logFormatted [12][20];  // a 2D array of 12 rows, each row represents a substring of GPS_log array 



/*
Description:
A function that reads a complete sentence from the GPS module then it Cuts it into substrings 

Example of complete sentence:
$GPRMC,203522.0,A,5109.0262308,N,11401.8407342,W,0.004,133.4,130522,0.0,E,D     
  "around 80 characters"

*/

void GPS_Read(){
	
     char logFillCounter = 0;
     char noOfStrings = 0;
     char *p;
     char charRecieved;
     int i ;
     int j=0;
     char logName[] = "$GPRMC,";

	
    //Making Sure we recieved the correct Log "$GPRMC"
	do{
	   while(UART2_Rx() != logName[j]);
	   j++;	
	}while(j != 7);

	
    //Initializing the log array to null
	strcpy(GPS_log ,"");
	
	
    //Filling the GPS_log array with characters until reaching character '*'
	do{
	   charRecieved = UART2_Rx();
	   GPS_log[logFillCounter] = charRecieved;
	   logFillCounter++;	
	}while(charRecieved != '*');

	
     //Cutting GPS_log array into multiple strings 
	p = strtok(GPS_log, ",");
	do{
	  strcpy(logFormatted[noOfStrings++] , p);
	  p = strtok(NULL , ","); 	
	}while(p != NULL);	
}




void start_walking(float* trajectory_points){
	wait_sec(27);  //wait for warm start
	
	float currentLat;
	float currentLong;
	
	//unsigned char SW1_in;	
	
	do{
	GPS_Read();	  //GPS_formated array will store the point details as a strings	
	if (strcmp (logFormated[1],"A")==0){ //Valid
				
				///////////////
				if (strcmp (logFormated[3],"N")==0)
					 currentLat = atof (logFormated [2]) ;
				else
						currentLat = -atof (logFormated [2]);

				
				if (strcmp (logFormated [5], "E") ==0)
						currentLong = atof ( logFormated [4]);
				else
						currentLong = -atof (logFormated[4]);
				/////////////////

				int i=0;    //trajectory_points index
				
				//SW1_in=SW1_read();
				//if( (SW1_in !=0X10)	){			//If SW1 is pressed
				//	LEDs_turn_on(GREEN);
				//	break;
				//}
				/////////////////
				unsigned char button1;
				button1 = SW1_Input();
				SW1_Pressed();
				///////////////////
	
				trajectory_points[i]=currentLat;  //i=0 ,even fields will be for latitude of each point
				i++;

				trajectory_points[i]=currentLong; //i=1 ,odd fields will be for Longitude of each point
				i++;	
				
				wait_sec(4);	
				
		}
	
	else continue;		
		
	} while(1);
	
}
	
	//normal walking speed is 1.4 metres per second wikipedia
	
	//100 m needs 72 sec 
	//each second will take a point


