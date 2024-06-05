/*
 * PID.c
 *
 *  Created on: Mar 15, 2024
 *      Author: vw060611
 */
#include "PID.h"
#include "calculations.h"

#define minSpeed 100

double error = 0;

double Pvalue = 0;
double Ivalue = 0;
double Dvalue = 0;

double differentialValue = 0;


void pidCorrection(boatStruct *boat, double desiredHeading){
	if(boat->groundspeed>minSpeed){
		error = (desiredHeading-boat->heading);
	}else{
		error = (boat->compass);
	}

	if(error>180){
		error = 180-error;
	}
	//if error is negative he needs to turn to port; if error is positive he needs to turn to starboard

	Pvalue = kp*error;

	boat->I_Temp+=error;

	if(boat->I_Temp>Imax){
		boat->I_Temp = Imax;
	}else if(boat->I_Temp<Imin){
		boat->I_Temp = Imin;
	}

	Ivalue = boat->I_Temp*ki;

	Dvalue = kd * (boat->D_Temp - error);
	boat->D_Temp = error;


	differentialValue = boat->differentialValue_Temp - (Pvalue + Ivalue + Dvalue);

	boat->pwmR = MAX(boat->minPWM, MIN(boat->maxPWM, boat->averagPWM+differentialValue));
	boat->pwmL = MAX(boat->minPWM, MIN(boat->maxPWM, boat->averagPWM-differentialValue));

	boat->differentialValue_Temp = differentialValue;

}

