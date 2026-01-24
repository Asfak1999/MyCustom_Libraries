/*
 * AT24C256C_eeprom.c
 *
 *  Created on: Jan 18, 2026
 *      Author: Mohamed Ashfak
 */


#include "AT24C256C_eeprom.h"


/**
  * @brief  Initializing the EEPROM and check the presence of the device
  * @param  config pointer to At24EEPROM_t that contains device information
  * @param  i2c pointer to a I2C_HandleTypeDef that contains EEPROM i2c information
  * @param  devAddress EEPROM I2c device address
  * @retval EEPROM error Handle
  */
EEPROM_ErrorHandle_t AT24_Init(At24EEPROM_t *config, I2C_HandleTypeDef *i2c, uint8_t devAddress){

	config->i2c_interface = i2c;
	config->devAddr = devAddress;

	if(HAL_I2C_Init(config->i2c_interface) != HAL_OK){
		return EEPROM_INIT_ERROR;
	}

	if(HAL_I2C_IsDeviceReady(config->i2c_interface, config->devAddr, 5, HAL_MAX_DELAY) != HAL_OK){

		return EEPROM_NOT_READY;
	}

	return EEPROM_OK;

}


/**
 *  @breif write the 8bit data to the EEPROM on specified address
 *  @param config pointer to At24EEPROM_t that contains device information
 *  @param pdata ponter of data to be written
 *  @param dataAddr	address of data
 *  @retval EEPROM error Handle
 */

EEPROM_ErrorHandle_t AT24_WriteU8(At24EEPROM_t *config, uint8_t *pdata, uint16_t dataAddr)
{

	if(HAL_I2C_Mem_Write(config->i2c_interface, config->devAddr,
				dataAddr, sizeof(dataAddr), pdata, sizeof(*pdata), HAL_MAX_DELAY) != HAL_OK)
	{
		return EEPROM_WRITE_ERROR;
	}

	HAL_Delay(50);
	return EEPROM_OK;
}





/**
 *  @breif write the 16bit data to the EEPROM on specified address
 *  @param config pointer to At24EEPROM_t that contains device information
 *  @param pdata ponter of data to be written
 *  @param dataAddr	address of data
 *  @retval EEPROM error Handle
 */

EEPROM_ErrorHandle_t AT24_WriteU16(At24EEPROM_t *config, uint16_t *pdata, uint16_t dataAddr)
{
	uint8_t tempData[2];

	tempData[0] = (uint8_t)((*pdata) >> 8);
	tempData[1] = (uint8_t)((*pdata) & 0xFF);

	if(HAL_I2C_Mem_Write(config->i2c_interface, config->devAddr,
				dataAddr, sizeof(dataAddr), tempData, sizeof(tempData), HAL_MAX_DELAY) != HAL_OK)
	{
		return EEPROM_WRITE_ERROR;
	}

	HAL_Delay(50);
	return EEPROM_OK;
}






/**
 *  @breif write the 32bit data to the EEPROM on specified address
 *  @param config pointer to At24EEPROM_t that contains device information
 *  @param pdata ponter of data to be written
 *  @param dataAddr	address of data
 *  @retval EEPROM error Handle
 */

EEPROM_ErrorHandle_t AT24_WriteU32(At24EEPROM_t *config, uint16_t *pdata, uint16_t dataAddr)
{
	uint8_t tempData[4];

	tempData[0] = (uint8_t)((*pdata) >> 24);
	tempData[1] = (uint8_t)((*pdata) >> 16);
	tempData[2] = (uint8_t)((*pdata) >>  8);
	tempData[3] = (uint8_t)((*pdata) & 0xFF);

	if(HAL_I2C_Mem_Write(config->i2c_interface, config->devAddr,
				dataAddr, sizeof(dataAddr), tempData, sizeof(tempData), HAL_MAX_DELAY) != HAL_OK)
	{
		return EEPROM_WRITE_ERROR;
	}

	HAL_Delay(50);
	return EEPROM_OK;
}


/**
 *  @breif write data in page vise
 *  @param config pointer to At24EEPROM_t that contains device information
 *  @param pdata ponter of data to be written
 *  @param pageID location of page (0 to 512)
 *  @param pageByteAddr loaction of inside the page (0 to 64)
 *  @retval EEPROM error Handle
 */

EEPROM_ErrorHandle_t AT24_PageWrite(At24EEPROM_t *config, uint8_t *pdata, uint8_t pageID, uint16_t pageByteAddr){

	uint16_t dataAddr = (uint16_t)((pageID << 6) | (pageByteAddr & 0x3F));


	if(HAL_I2C_Mem_Write(config->i2c_interface, config->devAddr,
				dataAddr, sizeof(dataAddr), pdata, sizeof(pdata), HAL_MAX_DELAY) != HAL_OK)
	{
		return EEPROM_WRITE_ERROR;
	}

	HAL_Delay(50);
	return EEPROM_OK;
}



/**
 *  @breif read data in page vise
 *  @param config pointer to At24EEPROM_t that contains device information
 *  @param pdata ponter of data to be written
 *  @param pageID location of page (0 to 512)
 *  @param pageByteAddr loaction of inside the page (0 to 64)
 *  @retval EEPROM error Handle
 */

EEPROM_ErrorHandle_t AT24_PageRead(At24EEPROM_t *config, uint8_t *pdata, uint8_t pageID, uint16_t pageByteAddr){

	uint16_t dataAddr = (uint16_t)((pageID << 6) | (pageByteAddr & 0x3F));

	if(HAL_I2C_Mem_Read(config->i2c_interface, config->devAddr,
			dataAddr, sizeof(dataAddr), pdata, sizeof(*pdata), 100) != HAL_OK){

		return EEPROM_READ_ERROR;
	}
	HAL_Delay(50);
	return EEPROM_OK;
}






/**
 *  @breif write the 32bit data to the EEPROM on specified address
 *  @param config pointer to At24EEPROM_t that contains device information
 *  @param pdata ponter of data to be written
 *  @param dataAddr	address of data
 *  @retval EEPROM error Handle
 */

EEPROM_ErrorHandle_t AT24_ReadU8(At24EEPROM_t *config, uint8_t *pdata, uint16_t dataAddr)
{

	if(HAL_I2C_Mem_Read(config->i2c_interface, config->devAddr,
			dataAddr, sizeof(dataAddr), pdata, sizeof(*pdata), 100) != HAL_OK){

		return EEPROM_READ_ERROR;
	}
	HAL_Delay(50);
	return EEPROM_OK;
}






/**
 *  @breif write the 32bit data to the EEPROM on specified address
 *  @param config pointer to At24EEPROM_t that contains device information
 *  @param pdata ponter of data to be written
 *  @param dataAddr	address of data
 *  @retval EEPROM error Handle
 */

EEPROM_ErrorHandle_t AT24_ReadBytes(At24EEPROM_t *config, uint8_t *pdata, uint16_t dataAddr, uint8_t n)
{

	uint8_t tempAddr[2];

	tempAddr[0] = (dataAddr >> 8) & 0xFF;
	tempAddr[1] = dataAddr& 0xFF;

	if(HAL_I2C_Master_Transmit(config->i2c_interface, config->devAddr, tempAddr, 2, HAL_MAX_DELAY) != HAL_OK){
		return EEPROM_WRITE_ERROR;
	}

	if(HAL_I2C_Master_Receive(config->i2c_interface, config->devAddr, pdata, n, HAL_MAX_DELAY) != HAL_OK){
		return EEPROM_READ_ERROR;
	}

	HAL_Delay(50);
	return EEPROM_OK;

}







/**
 *  @breif earase page data
 *  @param config pointer to At24EEPROM_t that contains device information
 *  @param pageID location of page (0 to 512)
 *  @retval EEPROM error Handle
 */

EEPROM_ErrorHandle_t AT24_PageErase(At24EEPROM_t *config, uint8_t pageID){

	uint16_t dataAddr = (uint16_t)(pageID << 6);
	uint8_t pdata[64];

	memset(&pdata, 0xFF, sizeof(pdata));

	if(HAL_I2C_Mem_Write(config->i2c_interface, config->devAddr,
				dataAddr, sizeof(dataAddr), pdata, sizeof(pdata), HAL_MAX_DELAY) != HAL_OK)
	{
		return EEPROM_WRITE_ERROR;
	}

	HAL_Delay(50);
	return EEPROM_OK;
}


/**
 *  @breif EEPROM Full erase
 *  @param config pointer to At24EEPROM_t that contains device information
 *  @param pageID location of page (0 to 512)
 *  @retval EEPROM error Handle
 */

EEPROM_ErrorHandle_t AT24_FullErase(At24EEPROM_t *config){

	uint16_t pageAddr = 0;
	uint8_t pdata[64];

	memset(&pdata, 0xFF, sizeof(pdata));

	for(int i = 0; i < 512; i++)
	{
		pageAddr = (uint16_t)(i << 6);

		if(HAL_I2C_Mem_Write(config->i2c_interface, config->devAddr,
				pageAddr, sizeof(pageAddr), pdata, sizeof(pdata), HAL_MAX_DELAY) != HAL_OK)
		{
			return EEPROM_NOT_ERASE;
		}

		HAL_Delay(50);
	}


	return EEPROM_OK;
}







