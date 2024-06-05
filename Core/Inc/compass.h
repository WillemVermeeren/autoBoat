/*
 * compass.h
 *
 *  Created on: May 3, 2024
 *      Author: vw060611
 */

#ifndef INC_COMPASS_H_
#define INC_COMPASS_H_

#include "stm32f4xx_hal.h"
// adresses
// HMC5883l - ADDRESS
#define HMC5883l_ADDRESS (0x0D << 1)
// CONTROL REG A
#define HMC5883l_Enable_A (0x78)
// CONTROL REG B
#define HMC5883l_Enable_B (0xA0)
// MODE REGISTER
#define HMC5883l_MR (0x01)
// HMC5883l - MSB / LSB ADDRESSES
#define HMC5883l_ADD_DATAX_MSB (0x03)
#define HMC5883l_ADD_DATAX_LSB (0x04)
#define HMC5883l_ADD_DATAZ_MSB (0x05)
#define HMC5883l_ADD_DATAZ_LSB (0x06)
#define HMC5883l_ADD_DATAY_MSB (0x07)
#define HMC5883l_ADD_DATAY_LSB (0x08)
// SUM (MSB + LSB) DEFINE
#define HMC5883l_ADD_DATAX_MSB_MULTI (HMC5883l_ADD_DATAX_MSB | 0x00)
#define HMC5883l_ADD_DATAY_MSB_MULTI (HMC5883l_ADD_DATAY_MSB | 0x02)
#define HMC5883l_ADD_DATAZ_MSB_MULTI (HMC5883l_ADD_DATAZ_MSB | 0x04)

typedef struct {
	I2C_HandleTypeDef *i2cHandle;

	uint8_t RegSettingA;
	uint8_t RegSettingB;
	uint8_t RegSettingMR;

	uint8_t heading;


} compass;





void Compass_initialise(compass *dev, I2C_HandleTypeDef *i2cHandle);
void getHeading(compass *dev);

#endif /* INC_COMPASS_H_ */
