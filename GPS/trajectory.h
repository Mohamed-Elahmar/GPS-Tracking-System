#ifndef GPS
#define GPS

#define PI 3.14159265358979323846264338327950288
#define EARTH_RADIUS 6371000

char logFormated [12][20];

void start_walking(float* trajectory_points);
void GPS_Read();



float to_degree(float angle);

float to_rad(float degree);

float TotalDistance(float* array );  // return distance in meters


#endif
