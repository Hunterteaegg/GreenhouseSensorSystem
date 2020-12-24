/*
 * SHT31.c
 *
 *  Created on: Dec 18, 2020
 *      Author: hunterteaegg
 */
#include "stm32f1xx_hal.h"
#include "main.h"
#include "SHT31.h"
#include "LCD1602.h"

extern I2C_HandleTypeDef hi2c2;		//external I2C handle
static uint8_t com[2] = {0};		//global variable of command prepared to send

void SHT31_init(uint8_t com_MSB, uint8_t com_LSB)
{
	com[0] = com_MSB;
	com[1] = com_LSB;
	HAL_I2C_Master_Transmit(&hi2c2, SHT31_WRITE_ADDR, com, sizeof(com), 0xFF);	//transmit command about mode selection

//conditional compilation according to different running modes
#if (SHT31_MODE == SHT31_SINGLESHOT_MODE)
	HAL_Delay(10);
#elif (SHT31_MODE == SHT31_PERIODIC_MODE)
	;
#else
	fprintf(stderr,"SHT31 MODE selection failed.\n");
	exit(-1);
#endif
}

SHT31_DATA_T SHT31_readData(void)
{
	uint8_t dataRaw[6];	//six bytes ready to received.First three bytes include two bytes temperature raw data and its CRC-8 checksum,
						//as well as humidity raw data
	SHT31_DATA_T data;	//data after converting
//conditional compilation according to different running modes
#if (SHT31_MODE == SHT31_SINGLESHOT_MODE)
	HAL_Delay(20);
#elif (SHT31_MODE == SHT31_PERIODIC_MODE)
	com[0] = SHT31_COM_FETCH_DATA_M;
	com[1] = SHT31_COM_FETCH_DATA_L;
	HAL_I2C_Master_Transmit(&hi2c2, SHT31_WRITE_ADDR, com, sizeof(com), 0xFF);
#else
	fprintf(stderr,"SHT31 MODE selection failed.\n");
	exit(-1);
#endif
	HAL_I2C_Master_Receive(&hi2c2, SHT31_READ_ADDR, dataRaw, sizeof(dataRaw), 0xFF);

	//data conversion referred to the formulas on SHT31 datasheet
	uint16_t rawTemp = ((uint16_t)(dataRaw[0] << 8) | (uint16_t)dataRaw[1]);
	uint16_t rawHumi = ((uint16_t)(dataRaw[3] << 8) | (uint16_t)dataRaw[4]);

	data.temp = (-45) + 175 * (rawTemp / (double)((0x01UL << 16) - 1));
	data.humi = 100 * (rawHumi / (double)((0x01UL << 16) - 1));

	return data;
}

void SHT31_artMode(void)
{
#if (SHT31_MODE == SHT31_SINGLESHOT_MODE)
	;
#elif (SHT31_MODE == SHT31_PERIODIC_MODE)
	com[0] = SHT31_COM_ART_M;
	com[1] = SHT31_COM_ART_L;
	HAL_I2C_Master_Transmit(&hi2c2, SHT31_WRITE_ADDR, com, sizeof(com), 0xFF);
#else
	fprintf(stderr, "SHT31 MODE selection failed.\n");
	exit(-1);
#endif
}

void SHT31_break(void)
{
	com[0] = SHT31_COM_BREAK_M;
	com[1] = SHT31_COM_BREAK_L;
	HAL_I2C_Master_Transmit(&hi2c2, SHT31_WRITE_ADDR, com, sizeof(com), 0xFF);
}

void SHT31_reset(void)
{
	com[0] = SHT31_COM_RESET_M;
	com[1] = SHT31_COM_RESET_L;
	HAL_I2C_Master_Transmit(&hi2c2, SHT31_WRITE_ADDR, com, sizeof(com), 0xFF);
}
