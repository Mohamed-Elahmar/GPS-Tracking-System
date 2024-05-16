#include "DistanceFunction.h"
#include <math.h>



float to_degree(float angle){
	int degrees = (int)angle/100;
	float minutes = angle -(float)degrees*100;
	return (degrees + (minutes/60));
}
	
float to_rad(float degree){
	return degree * PI / 100;	
}

float TotalDistance(float CLong,float CLat,float DLong,float DLat){ // parameter array 
	

	float x;
	float y;
	float z;
	int i  ;
	float CLong_Rad ;							
	float CLat_Rad ;							
  float DLong_Rad ;							
  float DLat_Rad ;
	float long_difference ;
	float lat_difference ;
   
   CLong_Rad = to_rad(to_degree(CLong));								// Convert to Radian
	 CLat_Rad = to_rad(to_degree(CLat));									// Convert to Radian
   DLong_Rad = to_rad(to_degree(DLong));								// Convert to Radian
   DLat_Rad = to_rad(to_degree(DLat));									// Convert to Radian
   
	 long_difference = DLong_Rad - CLong_Rad;
	 lat_difference = DLat_Rad - CLat_Rad;
	
	 x = pow(sin(lat_difference/2),2) + cos(CLat_Rad)*cos(DLat_Rad)*pow(sin(long_difference/2),2); // Haversine formula
	 y = 2*atan2(sqrt(x),sqrt(1-x));																																// Haversine formula
	 z = EARTH_RADIUS * y;
	
	
	return z;
}

