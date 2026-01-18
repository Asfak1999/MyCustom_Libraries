/*
 * AT24C256C_eeprom.h
 *
 *  Created on: Jan 18, 2026
 *      Author: Mohamed Ashfak
 */

#ifndef INC_AT24C256C_EEPROM_H_
#define INC_AT24C256C_EEPROM_H_

#include <stdint.h>
#include "main.h"

typedef struct {

	I2C_HandleTypeDef *i2c_interface;	/*!< I2c Interface instance         */

	uint8_t devAddr;					/*!< EEPROM Device address         */

}At24EEPROM_t;


void init_At24EEPROM(At24EEPROM_t *config, I2C_HandleTypeDef *i2c, uint8_t devAddress);
int8_t write_At24EEPROM(At24EEPROM_t *config, uint8_t *pdata, uint16_t dataAddr);
int8_t read_At24EEPROM(At24EEPROM_t *config, uint8_t *pdata, uint16_t dataAddr);

#endif /* INC_AT24C256C_EEPROM_H_ */
