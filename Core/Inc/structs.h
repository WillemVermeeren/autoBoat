/*
 * structs.h
 *
 *  Created on: Apr 11, 2024
 *      Author: wille
 */

#ifndef INC_STRUCTS_H_
#define INC_STRUCTS_H_

typedef struct {
	double longitude;
	double latitude;

	double heading;
	double compass;
	signed long groundspeed;

	double pwmL;
	double pwmR;


	int center;
	int averagPWM;
	int maxPWM;
	int minPWM;

	double I_Temp;
	double D_Temp;
	double differentialValue_Temp;
} boatStruct;


#endif /* INC_STRUCTS_H_ */
