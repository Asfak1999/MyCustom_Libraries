/*
 * AT24C256C_eeprom.h
 *
 *  Created on: Jan 18, 2026
 *      Author: Mohamed Ashfak
 */

#ifndef INC_AT24C256C_EEPROM_H_
#define INC_AT24C256C_EEPROM_H_

#include <stdint.h>
#include <string.h>
#include "main.h"

#define EEPROM_HEADER 	0x0000
#define EEPROM_BODY 	0x0000




/**
  * @brief EEPROM Initialization Structure definition
  */
typedef struct
{
	I2C_HandleTypeDef *i2c_interface;	/*!< I2c Interface instance         */
	uint8_t devAddr;					/*!< EEPROM Device address         */

}At24EEPROM_t;





/**
  * @brief EEPROM Error handle enum definition
  */
typedef enum
{
	EEPROM_OK = 0,			/*!< EEPROM Successful operation             */
	EEPROM_INIT_ERROR,		/*!< EEPROM Initialization error             */
	EEPROM_NOT_READY,		/*!< EEPROM Device status		             */
	EEPROM_WRITE_ERROR,		/*!< EEPROM Write Memory Error               */
	EEPROM_READ_ERROR,		/*!< EEPROM Read Memory Error                */
	EEPROM_NOT_ERASE		/*!< EEPROM Read Memory Error                */

}EEPROM_ErrorHandle_t;








/******* AT24C256 EEPROM Function decelerations */
EEPROM_ErrorHandle_t AT24_Init(At24EEPROM_t *config, I2C_HandleTypeDef *i2c, uint8_t devAddress);
EEPROM_ErrorHandle_t AT24_WriteU8(At24EEPROM_t *config, uint8_t *pdata, uint16_t dataAddr);
EEPROM_ErrorHandle_t AT24_WriteU16(At24EEPROM_t *config, uint16_t *pdata, uint16_t dataAddr);
EEPROM_ErrorHandle_t AT24_WriteU32(At24EEPROM_t *config, uint16_t *pdata, uint16_t dataAddr);
EEPROM_ErrorHandle_t AT24_ReadU8(At24EEPROM_t *config, uint8_t *pdata, uint16_t dataAddr);
EEPROM_ErrorHandle_t AT24_ReadBytes(At24EEPROM_t *config, uint8_t *pdata, uint16_t dataAddr, uint8_t n);
EEPROM_ErrorHandle_t AT24_PageWrite(At24EEPROM_t *config, uint8_t *pdata, uint8_t pageID, uint16_t pageByteAddr);
EEPROM_ErrorHandle_t AT24_PageRead(At24EEPROM_t *config, uint8_t *pdata, uint8_t pageID, uint16_t pageByteAddr);
EEPROM_ErrorHandle_t AT24_PageErase(At24EEPROM_t *config, uint8_t pageID);
EEPROM_ErrorHandle_t AT24_FullErase(At24EEPROM_t *config);


#endif /* INC_AT24C256C_EEPROM_H_ */
