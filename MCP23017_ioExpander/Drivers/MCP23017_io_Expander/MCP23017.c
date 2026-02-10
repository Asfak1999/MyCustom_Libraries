/*
 * MCP23017.c
 *
 *  Created on: Jan 25, 2026
 *      Author: Mohamed Ashfak
 */


/*
 * @breif Init the MCP23017 expander
 * @param *config
 * @param *i2c
 * @param devAddress
 */

#include "MCP23017.h"


/*
 * @breif MCP2307 I/O expander device configuration Initialization
 * @param config configuration of register
 * @param dev configuration of device instance
 */
ENUM_MCP23017_error_t init_MCP23017(STRUCT_MCP23017_config_t *config, I2C_HandleTypeDef *i2c, uint8_t devAddress)
{
	inst->devAddr = devAddress;

	inst->i2c_interface = i2c;

	if(HAL_I2C_Init(inst->i2c_interface) != HAL_OK){
		return MC23017_I2C_ERROR;
	}

	if(HAL_I2C_IsDeviceReady(inst->i2c_interface, inst->devAddr, 5, HAL_MAX_DELAY) != HAL_OK){
		return MC23017_NOT_READY;
	}

	return MCP23017_OK;
}



/*
 * @breif MCP23017 Port I/O mode
 * @param port
 * @param pin
 */
void pinMode(ENUM_MCP23017_port_t port, uint8_t pin){

	uint8_t pinBit;

	switch(pin){
		case 1:
			pinBit = pin >> 0;
			break;
		case 2:
			pinBit = pin >> 1;
			break;
		case 3:
			pinBit = pin >> 2;
			break;
		case 4:
			pinBit = pin >> 3;
			break;
		case 5:
			pinBit = pin >> 4;
			break;
		case 6:
			pinBit = pin >> 5;
			break;
		case 7:
			pinBit = pin >> 6;
			break;
		case 8:
			pinBit = pin >> 7;
			break;
		default:
			break;
	}

	if(port == PORTA){
		HAL_I2C_Mem_Write(inst->i2c_interface, inst->devAddr, IODIRA, 1, &pinBit, 1, HAL_MAX_DELAY);
	}
	else if(port == PORTB){
		HAL_I2C_Mem_Write(inst->i2c_interface, inst->devAddr, IODIRB, 1, &pinBit, 1, HAL_MAX_DELAY);
	}
}
