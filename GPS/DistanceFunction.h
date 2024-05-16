#ifndef DistanceFunction
#define DistanceFunction

#define PI 3.14159265358979323846264338327950288
#define EARTH_RADIUS 6371000


float to_degree(float angle);

float to_rad(float degree);
 
float TotalDistance(float CLong,float CLat,float DLong,float DLat );

#endif