/*
 * calculation.h
 *
 *  Created on: Feb 28, 2024
 *      Author: vw060611
 */

#ifndef INC_CALCULATIONS_H_
#define INC_CALCULATIONS_H_

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

double haversineBearing(double latA, double lonA, double latB, double lonB);
double haversineDistance(double latA, double lonA, double latB, double lonB);
float toRadians(float degrees);

#endif /* INC_CALCULATIONS_H_ */
