/*
 * compass.c
 *
 *  Created on: May 3, 2024
 *      Author: vw060611
 */
#include "compass.h"

void Compass_initialise(compass *dev, I2C_HandleTypeDef *i2cHandle){
	HAL_StatusTypeDef status = HAL_I2C_IsDeviceReady(dev->i2cHandle, HMC5883l_ADDRESS, 10, 200);
	HAL_I2C_Mem_Write(dev->i2cHandle, HMC5883l_ADDRESS, 0x09 , 1, 0b01000111 , 1, 100);
	//HAL_I2C_Mem_Write(dev->i2cHandle, HMC5883l_ADDRESS, 0x01 , 1, dev->RegSettingB , 1, 100);
	//HAL_I2C_Mem_Write(dev->i2cHandle, HMC5883l_ADDRESS, 0x02 , 1, dev->RegSettingMR , 1, 100);
};


void getHeading(compass *dev){
	HAL_StatusTypeDef status = HAL_I2C_IsDeviceReady(dev->i2cHandle, HMC5883l_ADDRESS, 10, 200);
	/*
	uint8_t DataX[2];
	uint8_t DataY[2];
	uint8_t DataZ[2];

	// RECEIVE X_axis
	HAL_StatusTypeDef status = HAL_I2C_Mem_Read(dev->i2cHandle,HMC5883l_ADDRESS,0x00,1,DataX,2,100);
	uint16_t Xaxis = ((DataX[1]<<8) | DataX[0]);

	// RECEIVE Y_axis
	HAL_I2C_Mem_Read(dev->i2cHandle,HMC5883l_ADDRESS,0x02,1,DataY,2,100);
	uint16_t Yaxis = ((DataY[1]<<8) | DataY[0]);

	// RECEIVE Z_axis
	HAL_I2C_Mem_Read(dev->i2cHandle,HMC5883l_ADDRESS,0x04,1,DataZ,2,100);
	uint16_t Zaxis = ((DataZ[1]<<8) | DataZ[0]);

	float heading = atan2(Yaxis, Xaxis)*10000;
	*/


}
