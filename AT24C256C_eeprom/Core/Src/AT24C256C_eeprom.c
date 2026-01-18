/*
 * AT24C256C_eeprom.c
 *
 *  Created on: Jan 18, 2026
 *      Author: Mohamed Ashfak
 */


#include "AT24C256C_eeprom.h"



void init_At24EEPROM(At24EEPROM_t *config, I2C_HandleTypeDef *i2c, uint8_t devAddress){

	config->i2c_interface = i2c;
	config->devAddr = devAddress;
}



int8_t write_At24EEPROM(At24EEPROM_t *config, uint8_t *pdata, uint16_t dataAddr){


	if(sizeof(*pdata) < 64){
		HAL_I2C_Mem_Write(config->i2c_interface, config->devAddr,
				dataAddr, sizeof(dataAddr), pdata, sizeof(*pdata), 100);

		HAL_Delay(50);
		return 0;
	}

	return -1;
}


int8_t read_At24EEPROM(At24EEPROM_t *config, uint8_t *pdata, uint16_t dataAddr){

	if(HAL_I2C_Mem_Read(config->i2c_interface, config->devAddr,
			dataAddr, sizeof(dataAddr), pdata, sizeof(*pdata), 100) == HAL_OK){

		HAL_Delay(50);
		return 0;
	}
	return -1;
}
