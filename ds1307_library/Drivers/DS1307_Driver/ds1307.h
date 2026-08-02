/*
 * ds1307.h
 *
 *  Created on: Aug 2, 2026
 *      Author: Mohamed Ashfak
 */

#ifndef DS1307_DRIVER_DS1307_H_
#define DS1307_DRIVER_DS1307_H_

#include <stdint.h>

#define DS1307_ADDR 	0x68

#define REG_SECONDS		0x00
#define REG_MINUTES		0x01
#define REG_HOURS		0x02
#define REG_DAY			0x03
#define REG_DATE		0x04
#define REG_MONTH		0x05
#define REG_YEAR		0x06
#define REG_CONTROL		0x07


typedef union
{
	uint8_t reg;

	struct
	{
		uint8_t seconds		:4;
		uint8_t ten_seconds :3;
		uint8_t ch			:1;

	}bits;

}ds1307_seconds_t;



typedef union
{
	uint8_t reg;

	struct
	{
		uint8_t minutes		:4;
		uint8_t ten_minutes :3;
		uint8_t reserved    :1;

	}bits;

}ds1307_minutes_t;



typedef union
{
	uint8_t reg;
	struct
	{
		uint8_t hours		:4;
		uint8_t ten_hours	:1;

		union
		{
			struct
			{
				uint8_t am_pm    :1;
				uint8_t mode     :1;
				uint8_t reserved :1;
			}hour_24;

			struct
			{
				uint8_t ten_hour1:1;
				uint8_t mode     :1;
				uint8_t reserved :1;
			}hour_12;
		}format;
	}bits;

}ds1307_hours_t;


typedef union
{
	uint8_t reg;

	struct
	{
		uint8_t day		    :3;
		uint8_t reserved    :4;

	}bits;

}ds1307_day_t;


typedef union
{
	uint8_t reg;

	struct
	{
		uint8_t date		:4;
		uint8_t date_10		:2;
		uint8_t reserved    :2;

	}bits;

}ds1307_date_t;



typedef union
{
	uint8_t reg;

	struct
	{
		uint8_t month		:4;
		uint8_t month_10    :1;
		uint8_t reserved    :3;
	}bits;

}ds1307_month_t;


typedef union
{
	uint8_t reg;

	struct
	{
		uint8_t year		:4;
		uint8_t year_10		:4;

	}bits;

}ds1307_year_t;


typedef union
{
	uint8_t reg;

	struct
	{
		uint8_t rs0			:1;
		uint8_t rs1			:1;
		uint8_t reserved1	:2;
		uint8_t sqwe		:1;
		uint8_t reserved2	:2;
		uint8_t out			:1;
	};
}ds1307_control_t;



#endif /* DS1307_DRIVER_DS1307_H_ */
