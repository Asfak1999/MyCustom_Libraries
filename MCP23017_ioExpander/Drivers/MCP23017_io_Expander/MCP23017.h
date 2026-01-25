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






/*
 * @breif MCP23017 expander direction set register struct
 */

typedef struct{

	uint8_t IO0 : 1;	/*!< pin 0 */

	uint8_t IO1 : 1;	/*!< pin 1 */

	uint8_t IO2 : 1;	/*!< pin 2 */

	uint8_t IO3 : 1;	/*!< pin 3 */

	uint8_t IO4 : 1;	/*!< pin 4 */

	uint8_t IO5 : 1;	/*!< pin 5 */

	uint8_t IO6 : 1;	/*!< pin 6 */

	uint8_t IO7 : 1;	/*!< pin 7 */

}STRUCT_MCP23017_setDir_t;



/*
 * @breif MCP23017 expander direction set register unioin
 */

typedef union{

	uint8_t all;

	STRUCT_MCP23017_setDir_t pin;

}UNION_MCP23017_setDir_t;







/*
 * @breif MCP23017 expander GPIO pull-up resistor registor struct
 */

typedef struct{

	uint8_t PU0 : 1;	/*!< pull-up 0 */

	uint8_t PU1 : 1;	/*!< pull-up 1 */

	uint8_t PU2 : 1;	/*!< pull-up 2 */

	uint8_t PU3 : 1;	/*!< pull-up 3 */

	uint8_t PU4 : 1;	/*!< pull-up 4 */

	uint8_t PU5 : 1;	/*!< pull-up 5 */

	uint8_t PU6 : 1;	/*!< pull-up 6 */

	uint8_t PU7 : 1;	/*!< pull-up 7 */

}STRUCT_MCP23017_pullUp_t;


/*
 * @breif MCP23017 expander GPIO pull-up resistor registor struct
 */

typedef union {

	uint8_t all;

	STRUCT_MCP23017_pullUp_t bits;

}UNION_MCP23017_pullUp_t;





/*
 * @breif MCP23017 expander Interrupt flag registor struct
 */

typedef struct {

	uint8_t INT0 : 1;	/*!< INT flag 0 */

	uint8_t INT1 : 1;	/*!< INT flag 1 */

	uint8_t INT2 : 1;	/*!< INT flag 2 */

	uint8_t INT3 : 1;	/*!< INT flag 3 */

	uint8_t INT4 : 1;	/*!< INT flag 4 */

	uint8_t INT5 : 1;	/*!< INT flag 5 */

	uint8_t INT6 : 1;	/*!< INT flag 6 */

	uint8_t INT7 : 1;	/*!< INT flag 7 */

}STRUCT_MCP23017_IntFlag_t;


/*
 * @breif MCP23017 expander Interrupt flag registor union
 */

typedef union{

	uint8_t all;

	STRUCT_MCP23017_IntFlag_t bits;

}UNION_MCP23017_IntFlag_t;




/*
 * @breif MCP23017 expander Interrupt capture registor struct
 */

typedef struct {

	uint8_t ICP0 : 1;	/*!< ICP bit 0 */

	uint8_t ICP1 : 1;	/*!< ICP bit 1 */

	uint8_t ICP2 : 1;	/*!< ICP bit 2 */

	uint8_t ICP3 : 1;	/*!< ICP bit 3 */

	uint8_t ICP4 : 1;	/*!< ICP bit 4 */

	uint8_t ICP5 : 1;	/*!< ICP bit 5 */

	uint8_t ICP6 : 1;	/*!< ICP bit 6 */

	uint8_t ICP7 : 1;	/*!< ICP bit 7 */

}STRUCT_MCP23017_IntCap_t;



/*
 * @breif MCP23017 expander Interrupt capture registor struct
 */

typedef union {

	uint8_t all;

	STRUCT_MCP23017_IntCap_t bits;

}UNION_MCP23017_IntCap_t;




/*
 * @breif MCP23017 expander Port register struct
 */

typedef struct {

	uint8_t GP0 : 1;	/*!< GPIO bit 0 */

	uint8_t GP1 : 1;	/*!< GPIO bit 1 */

	uint8_t GP2 : 1;	/*!< GPIO bit 2 */

	uint8_t GP3 : 1;	/*!< GPIO bit 3 */

	uint8_t GP4 : 1;	/*!< GPIO bit 4 */

	uint8_t GP5 : 1;	/*!< GPIO bit 5 */

	uint8_t GP6 : 1;	/*!< GPIO bit 6 */

	uint8_t GP7 : 1;	/*!< GPIO bit 7 */

}STRUCT_MCP23017_port_t;


/*
 * @breif MCP23017 expander Port register union
 */

typedef union {

	uint8_t all;

	STRUCT_MCP23017_port_t bits;

}UNION_MCP23017_port_t;




/*
 * @breif MCP23017 expander output latch register struct
 */

typedef struct {

	uint8_t OL0 : 1;	/*!< OL bit 0 */

	uint8_t OL1 : 1;	/*!< OL bit 1 */

	uint8_t OL2 : 1;	/*!< OL bit 2 */

	uint8_t OL3 : 1;	/*!< OL bit 3 */

	uint8_t OL4 : 1;	/*!< OL bit 4 */

	uint8_t OL5 : 1;	/*!< OL bit 5 */

	uint8_t OL6 : 1;	/*!< OL bit 6 */

	uint8_t OL7 : 1;	/*!< OL bit 7 */

}STRUCT_MCP23017_outLatch_t;



/*
 * @breif MCP23017 expander output latch register union
 */

typedef union {

	uint8_t all;

	STRUCT_MCP23017_outLatch_t bits;

}UINOIN_MCP23017_outLatch_t;



/*
 * @breif MCP2307 I/O expander device configuration Initialization
 * @param config configuration of register
 * @param dev configuration of device instance
 */
void init_MCP23017(STRUCT_MCP23017_config_t *config, I2C_HandleTypeDef *i2c, uint8_t devAddress);



#endif /* MCP23017_IO_EXPANDER_MCP23017_H_ */
