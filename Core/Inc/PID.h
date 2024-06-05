/*
 * PID.h
 *
 *  Created on: Mar 15, 2024
 *      Author: vw060611
 */

#ifndef INC_PID_H_
#define INC_PID_H_

#include "structs.h"

#define kp 0.005
#define ki 0.005
#define kd 0.00005

#define Imax 50
#define Imin -50




void pidCorrection(boatStruct *boat, double desiredHeading);

#endif /* INC_PID_H_ */




