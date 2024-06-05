/*
 * calculations.c
 *
 *  Created on: Feb 28, 2024
 *      Author: vw060611
 */

#include <math.h>



double toRadians(double degrees){
	return degrees*3.1415926535/180;
}

double toDegrees(double radians){
	return radians*180/3.1415926535;
}

double haversineBearing(double latA, double lonA, double latB, double lonB){
	latA = toRadians(latA);
	latB = toRadians(latB);
	lonA = toRadians(lonA);
	lonB = toRadians(lonB);

	double vertical = cos(latB)*sin(lonB-lonA);
	double horizontal = cos(latA)*sin(latB)-sin(latA)*cos(latB)*cos(lonB-lonA);

	double bearing = toDegrees(atan2(vertical, horizontal));

	return bearing;
}

double haversineDistance(double latA, double lonA, double latB, double lonB){
	latA = toRadians(latA);
	latB = toRadians(latB);
	lonA = toRadians(lonA);
	lonB = toRadians(lonB);

	double radiusEarth = 6371000;
	double distance = 2*radiusEarth*asinhf(sqrt(pow(sin((latB-latA)/2),2)+cos(latA)*cos(latB)*pow(sin((lonB-lonA)/2),2)));

	return distance;
}
