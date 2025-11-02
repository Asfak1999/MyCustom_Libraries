#ifndef __ADXL345_H
#define __ADXL345_H




#include "main.h"
#include <stdint.h>
#include <stdbool.h>



#define ADXL345_DEV_ADDR    (0x53 << 1)


//---------- ADXL345 Register Mapping -----------//

#define DEVID 				(0x00)	//  Device ID
#define THERSH_TAP 			(0x1D)	//  Tap threshold
#define OFSX				(0x1E)	//  X-axis offset
#define OFSY				(0x1F)	//  Y-axis offset
#define OFSZ				(0x20)	//  Z-axis offset
#define DUR					(0x21)	//  Tap duration
#define LATENT				(0x22)	//  Tap latency
#define WINDOW				(0x23)	//  Tap window
#define THERSH_ACT			(0x24)	//	Activity threshold
#define THERSH_INACT		(0x25)	//	Inactive threshold
#define TIME_INACT			(0x26)	//	Inactive time
#define ACT_INACT_CTL		(0x27)	//	Axis enable control for activity and inactivity detection
#define	THRESH_FF			(0x28)	//	Free-fall threshold
#define	TIME_FF				(0x29)	//	Free-fall time
#define	TAP_AXES			(0x2A)	//	Axis control for single tap/double tap
#define	ACT_TAP_STATUS		(0x2B)	// 	Source of single tap/double tap
#define	BW_RATE				(0x2C)	// 	Data rate and power mode control
#define	POWER_CTL			(0x2D)	//	Power-saving features control
#define	INT_ENABLE			(0x2E)	//	Interrupt enable control
#define	INT_MAP				(0x2F)	//	Interrupt mapping control
#define	INT_SOURCE			(0x30)	//	Source mapping control
#define	DATA_FORMAT			(0x31)	//	Data format control
#define	DATAX0				(0x32)	//	X-Axis Data 0
#define	DATAX1				(0x33)	//	X-Axis Data 1
#define	DATAY0				(0x34)	//	Y-Axis Data 0
#define	DATAY1				(0x35)	//	Y-Axis Data 1
#define	DATAZ0				(0x36)	//	Z-Axis Data 0
#define	DATAZ1				(0x37)	//	Z-Axis Data 1
#define	FIFO_CTL			(0x38)	//  FIFO Control
#define	FIFO_STATUS			(0x39)	//  FIFO Status



/**
 * @brief Represents   Register 0x2C—BW_RATE (Read/Write)
 */
#define LOW_POWER			(0x10)
#define RATE				()




/**
 * @brief Represents  Register 0x2D—POWER_CTL (Read/Write)
 */
#define WAKEUP				(0x03)
#define SLEEP				(0x04)
#define MEASURE				(0x08)
#define AUTO_SLEEP			(0x10)
#define LINK				(0x20)


/**
 * @brief Represents  Register 0x31—DATA_FORMAT (Read/Write)
 */

#define FULL_RES 			(0x08)

#define RANG_2G				(0x00)
#define RANG_4G				(0x01)
#define RANG_8G				(0x02)
#define RANG_16G			(0x03)



/**
 * @brief Represents INTERRUPTS of sensor
 */
typedef enum
{
    DATA_READY = 0,    /**< ADXL New data is ready */
	SINGLE_TAP,        /**< single tap event */
	DOUBLE_TAP,        /**< Double tap event */
	ACTIVITY,          /**< Activity event */
	INACTIVITY,        /**< Inactivity event */
	FREE_FALL,         /**< Free fall event */
	WATERMARK,         /**< Water mark  event */
	OVERRUN,           /**< Over run event */

} AdxlIntr_t;






/**
 * @brief Represents initialization of sensor
 */
typedef struct
{
    uint8_t LOWP_MODE;    	/**< Low Power mode */
    uint8_t DATA_RATE;	  	/**< Data rate and band width */
    uint8_t LINK_MODE;	  	/**< Link mode */
    uint8_t A_SLEEP;	  	/**< Automatic sleep */
    uint8_t SET_MEASURE;	/**< Enable measuring data */

} AdxlConfig_t;






int who_iam(I2C_HandleTypeDef *dev);

int writeADXL(uint8_t reg_Addr, uint8_t value);
int readADXL8(uint8_t reg_Addr, uint8_t *value);
void initADXL(AdxlConfig_t *config);


#endif /* __ADXL345_H */
