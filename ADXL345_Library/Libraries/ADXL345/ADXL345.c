#include "ADXL345.h"
#include <stdbool.h>


static I2C_HandleTypeDef *adxl_i2c;


int who_iam(I2C_HandleTypeDef *dev){

	uint8_t data_rec;
	adxl_i2c = dev;

	HAL_I2C_Mem_Read(adxl_i2c, ADXL345_DEV_ADDR, DEVID, I2C_MEMADD_SIZE_8BIT, &data_rec, 1,100);

	if(data_rec == 0xE5){
		return 1;
	}

	return 0;

}


int writeADXL(uint8_t reg_Addr, uint8_t value){

	uint8_t data[2] = {reg_Addr, value};

	if(HAL_I2C_Master_Transmit(adxl_i2c, ADXL345_DEV_ADDR, data, 2, HAL_MAX_DELAY) == HAL_OK){
		return 1;
	}
	return 0;
}


int readADXL8(uint8_t reg_Addr, uint8_t *value){


	if(HAL_I2C_Mem_Read(adxl_i2c, ADXL345_DEV_ADDR, reg_Addr, I2C_MEMADD_SIZE_8BIT, value, 1,HAL_MAX_DELAY) == HAL_OK){
		return 1;
	}
	return 0;
}


void initADXL(AdxlConfig_t *config){

	if(config == NULL) return;

	uint8_t bwRate = config->LOWP_MODE | config->DATA_RATE;
	writeADXL(BW_RATE, bwRate);

	uint8_t powerControl = config->SET_MEASURE;
	writeADXL(POWER_CTL, powerControl);
}
