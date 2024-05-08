#include "GPS.h"
#include "tm4c123gh6pm.h"
#include <math.h>
#include "timer.h"
#include <String.h>
#include <stdlib.h>

#include "Switch.h"
#include "LED.h"




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


