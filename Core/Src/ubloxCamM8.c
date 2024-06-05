/*
 * ubloxCamM8.c
 *
 *  Created on: Feb 17, 2024
 *      Author: wille
 */
#include "ubloxCamM8.h"
#include "calculations.h"




void Ublox_clearBuffer(ubloxCamM8 *dev){
	uint8_t data[2];
	HAL_StatusTypeDef status = HAL_I2C_Mem_Read(dev->i2cHandle, (0x42 << 1), 0xFD, 1, data, sizeof(data), 100);

	if (status != HAL_OK)
		return;

	uint8_t length = (((uint16_t)data[0] << 8) + (uint16_t)data[1]);


	static uint8_t buffer[1000];
	uint16_t len = MIN(length, sizeof(buffer));

	if(len){
		status = HAL_I2C_Mem_Read(dev->i2cHandle, (0x42 << 1), 0xFF, 1, buffer, len, 300);

		if (status != HAL_OK)
			return;
	}
}

void Ublox_initialise(ubloxCamM8 *dev, I2C_HandleTypeDef *i2cHandle){
	dev->i2cHandle = i2cHandle;


	uint8_t wakeup[] = { 0xB5,0x62,0x0A,0x04,0x00,0x00,0x0E,0x34 };
	HAL_StatusTypeDef statuswakeup = HAL_I2C_Mem_Write(dev->i2cHandle, (0x42 << 1), 0xFF, 1, wakeup, sizeof(wakeup), 500);


	while(statuswakeup!=HAL_OK){
		HAL_Delay(500);
		statuswakeup = HAL_I2C_Mem_Write(dev->i2cHandle, (0x42 << 1), 0xFF, 1, wakeup, sizeof(wakeup), 500);

	}
	HAL_Delay(100);
	Ublox_clearBuffer(dev);

	uint8_t disableNmea[] = { 0xB5,0x62,0x06,0x00,0x14,0x00,0x00,0x00,0x00,0x00,0x84,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0xA0,0x96};
	HAL_StatusTypeDef statusDisable = HAL_I2C_Mem_Write(dev->i2cHandle, (0x42 << 1), 0xFF, 1, disableNmea, sizeof(disableNmea), 500);

	while(statusDisable!=HAL_OK){
		HAL_Delay(500);
		statusDisable = HAL_I2C_Mem_Write(dev->i2cHandle, (0x42 << 1), 0xFF, 1, disableNmea, sizeof(disableNmea), 500);

	}
	HAL_Delay(100);
	Ublox_clearBuffer(dev);
}

void Ublox_getCoords(ubloxCamM8 *dev){
	uint8_t wakeup[] = { 0xB5,0x62,0x0A,0x04,0x00,0x00,0x0E,0x34 };
	HAL_StatusTypeDef statuswakeup = HAL_I2C_Mem_Write(dev->i2cHandle, (0x42 << 1), 0xFF, 1, wakeup, sizeof(wakeup), 500);


	while(statuswakeup!=HAL_OK){
		HAL_Delay(500);
		statuswakeup = HAL_I2C_Mem_Write(dev->i2cHandle, (0x42 << 1), 0xFF, 1, wakeup, sizeof(wakeup), 500);

	}
	Ublox_clearBuffer(dev);

	uint8_t coords_msg[] = { 0xB5, 0x62, 0x01, 0x07, 0x00, 0x00, 0x08, 0x19};


	HAL_StatusTypeDef status = HAL_I2C_Mem_Write(dev->i2cHandle, (0x42 << 1), 0xFF, 1, coords_msg, sizeof(coords_msg), 400);

	if (status != HAL_OK)
		return;
	HAL_Delay(100);
	for(int i=0;i<10;i++){

		uint8_t data[2];
		status = HAL_I2C_Mem_Read(dev->i2cHandle, (0x42 << 1), 0xFD, 1, data, sizeof(data), 100);

		if (status != HAL_OK)
			return;

		uint8_t length = (((uint16_t)data[0] << 8) + (uint16_t)data[1]);


		static uint8_t buffer[1000];
		uint16_t len = MIN(length, sizeof(buffer));

		if(len){
			status = HAL_I2C_Mem_Read(dev->i2cHandle, (0x42 << 1), 0xFF, 1, buffer, len, 300);

			if (status != HAL_OK)
				return;

			dev->lon = (buffer[24]<<24)+(buffer[25]<<16)+(buffer[26]<<8)+(buffer[27]);
			dev->lat = (buffer[28]<<24)+(buffer[29]<<16)+(buffer[30]<<8)+(buffer[31]);

			dev->heading = (buffer[64]<<24)+(buffer[65]<<16)+(buffer[66]<<8)+(buffer[67]);
			dev->satellites = buffer[23];
		}
		HAL_Delay(100);
	}
}


