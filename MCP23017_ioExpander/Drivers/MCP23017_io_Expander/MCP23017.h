/*
 * MCP23017.h
 *
 *  Created on: Jan 25, 2026
 *      Author: Mohamed Ashfak
 */

#ifndef MCP23017_IO_EXPANDER_MCP23017_H_
#define MCP23017_IO_EXPANDER_MCP23017_H_

#define IODIRA		0x00	/*!< Direction register */
#define IPOLA		0x01	/*!< Input polarity port register */
#define GPINTENA	0x02	/*!< Interrupt on-change pin register */
#define DEFVALA		0x03	/*!< Default value register */
#define INTCONA		0x04	/*!< Interrup on-change control register */
#define IOCONA		0x05	/*!< Configuration register */
#define GPPUA		0x06	/*!< GPIO PULL-UP resistor register */
#define	INTFA		0x07	/*!< Interrupt flag register */
#define INTCAPA		0x08	/*!< Interrupt capture value port register */
#define	GPIOA		0x09	/*!< GPIO port register */
#define OLATA		0x0A	/*!< Output latch register */

#define IODIRB		0x10	/*!< Direction register */
#define IPOLB		0x11	/*!< Input polarity port register */
#define GPINTENB	0x12	/*!< Interrup on-change pin register */
#define DEFVALB		0x13	/*!< Default value register */
#define INTCONB		0x14	/*!< Interrupt on-change control register */
#define IOCONB		0x15	/*!< Configuration register */
#define GPPUB		0x16	/*!< GPIO PULL-UP resistor register */
#define	INTFB		0x17	/*!< Interrupt flag register */
#define INTCAPB		0x18	/*!< Interrupt capture value register */
#define	GPIOB		0x19	/*!< GPIO port register */
#define OLATB		0x1A	/*!< Output latch register */





/*
 * @breif MCP23017 I/O expander configuration register struct
 */

typedef struct {

	uint8_t BANK:	1;		/*!< BANK bit */

	uint8_t MIRROR: 1;		/*!< Mirror bit */

	uint8_t SEQOP: 	1;		/*!< Sequencial operation bit */

	uint8_t DISSLW:	1;		/*!< slew rate bit */

	uint8_t HAEN: 	1;		/*!< Hardware address enable bit */

	uint8_t INTPOL:	1;		/*!< Interrupt polarity bit */

	uint8_t RES:	1;  	/*!< Reserved bit */

}STRUCT_MCP23017_config_t;




/*
 * @breif MCP23017 I/O expander configuration register union
 */

typedef union {

	uint8_t all;

	STRUCT_MCP23017_config_t bits;

}UNIOIN_MCP23017_config_t;


#endif /* MCP23017_IO_EXPANDER_MCP23017_H_ */
