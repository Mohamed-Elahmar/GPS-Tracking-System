#include "trajectory.h"
#include "tm4c123gh6pm.h"
#include <math.h>
#include "timer.h"
#include <String.h>
#include <stdlib.h>

#include "Switch.h"
#include "LED.h"




void wait_clks(unsigned int delay){
	NVIC_ST_CTRL_R =0;
	NVIC_ST_RELOAD_R = delay-1;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R =0x5;
	while((NVIC_ST_CTRL_R & 0x00010000)== 0);
	NVIC_ST_CTRL_R =0;
}


void wait_sec (unsigned int sec){
	unsigned int i;
	unsigned int j;
	for(i=0 ; i<(sec); i++){
		for(j=0 ; j<10; j++){
		wait_clks(1600000); //0.1 s
		} //1 s
	}
}
