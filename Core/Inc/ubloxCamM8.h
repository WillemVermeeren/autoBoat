#ifndef UBLOXCAMM8_I2C_DRIVER_H
#define UBLOXCAMM8_I2C_DRIVER_H

#include "stm32f4xx_hal.h"


#define longLatScale 0.0000001
#define headingScale 0.00001

typedef struct {
	I2C_HandleTypeDef *i2cHandle;

	signed long lon;
	signed long lat;
	signed long heading;
	signed long groundSpeed;

	unsigned char satellites;

} ubloxCamM8;

void Ublox_clearBuffer(ubloxCamM8 *dev);
void Ublox_initialise(ubloxCamM8 *dev, I2C_HandleTypeDef *i2cHandle);
void Ublox_getCoords(ubloxCamM8 *dev);

#endif
