/*
 * AT24C256C_eeprom.c
 *
 *  Created on: Jan 18, 2026
 *      Author: Mohamed Ashfak
 */


#include "AT24C256C_eeprom.h"



int init_At24EEPROM(At24EEPROM_t *config, I2C_HandleTypeDef *i2c, uint8_t devAddress){

	config->i2c_interface = i2c;
	config->devAddr = devAddress;

	if(HAL_I2C_Init(config->i2c_interface) != HAL_OK){
		return 1;
	}

	if(HAL_I2C_IsDeviceReady(config->i2c_interface, config->devAddr, 5, 100) != HAL_OK){

		return 2;
	}

	return 0;

}



int8_t write_At24EEPROM(At24EEPROM_t *config, uint8_t *pdata, uint16_t dataAddr){


	if(sizeof(*pdata) < 64){
		HAL_I2C_Mem_Write(config->i2c_interface, config->devAddr,
				dataAddr, sizeof(dataAddr), pdata, sizeof(*pdata), 100);

		HAL_Delay(50);
		return 0;
	}

	return 3;
}


int8_t read_At24EEPROM(At24EEPROM_t *config, uint8_t *pdata, uint16_t dataAddr){

	if(HAL_I2C_Mem_Read(config->i2c_interface, config->devAddr,
			dataAddr, sizeof(dataAddr), pdata, sizeof(*pdata), 100) != HAL_OK){

		return 4;
	}
	return 0;
}


uint8_t readBytes_At24EEPROM(At24EEPROM_t *config, uint8_t *pdata, uint16_t dataAddr, uint8_t n){

	uint8_t tempAddr[2];

	tempAddr[0] = (dataAddr >> 8) & 0xFF;
	tempAddr[1] = dataAddr& 0xFF;

	if(HAL_I2C_Master_Transmit(config->i2c_interface, config->devAddr, tempAddr, 2, HAL_MAX_DELAY) != HAL_OK){
		return 5;
	}

	if(HAL_I2C_Master_Receive(config->i2c_interface, config->devAddr, pdata, n, HAL_MAX_DELAY) != HAL_OK){
		return 5;
	}

	return 0;


}
