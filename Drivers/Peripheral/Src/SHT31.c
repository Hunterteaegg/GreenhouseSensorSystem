/*
 * SHT31.c
 *
 *  Created on: Dec 18, 2020
 *      Author: hunterteaegg
 */
#include "stm32f1xx_hal.h"
#include "main.h"
#include "SHT31.h"

extern I2C_HandleTypeDef hi2c2;
static uint8_t com[2] = {0};

void SHT31_init(uint8_t addr, uint8_t com_MSB, uint8_t com_LSB)
{
	com[0] = com_MSB;
	com[1] = com_LSB;
	HAL_I2C_Master_Transmit(&hi2c2, SHT31_SLAVE_ADDRESS, com, sizeof(com), 0xFF);

#if (SHT31_MODE == SHT31_SINGLESHOT_MODE)
	HAL_Delay(1);
#elif (SHT31_MODE == SHT31_PERIODIC_MODE)
	;
#else
	fprintf(stderr,"SHT31 MODE selection failed.\n");
	exit(-1);
#endif
}

SHT31_DATA_T SHT31_readData(void)
{
	uint8_t dataRaw[6];
	SHT31_DATA_T data;

#if (SHT31_MODE == SHT31_SINGLESHOT_MODE)
	HAL_Delay(2);
#elif (SHT31_MODE == SHT31_PERIODIC_MODE)
	com[0] = SHT31_COM_FETCH_DATA_M;
	com[1] = SHT31_COM_FETCH_DATA_L;
	HAL_I2C_Master_Transmit(&hi2c2, SHT31_SLAVE_ADDRESS, com, sizeof(com), 0xFF);
#else
	fprintf(stderr,"SHT31 MODE selection failed.\n");
	exit(-1);
#endif
	HAL_I2C_Master_Receive(&hi2c2, SHT31_SLAVE_ADDRESS, dataRaw, sizeof(dataRaw), 0xFF);
	uint16_t rawTemp = ((dataRaw[0] << 8) | dataRaw[1]);
	uint16_t rawHumi = ((dataRaw[3] << 8) | dataRaw[4]);

	data.temp = -45 + 145 * ((double)rawTemp / ((double)(0x01 << 16) - 1));
	data.humi = 100 * ((double)rawHumi / ((double)(0x01 << 16) - 1));

	return data;
}

void SHT31_artMode(void)
{
#if (SHT31_MODE == SHT31_SINGLESHOT_MODE)
	;
#elif (SHT31_MODE == SHT31_PERIODIC_MODE)
	com[0] = SHT31_COM_ART_M;
	com[1] = SHT31_COM_ART_L;
	HAL_I2C_Master_Transmit(&hi2c, SHT31_SLAVE_ADDRESS, com, sizeof(com), 0xFF);
#else
	fprintf(stderr, "SHT31 MODE selection failed.\n");
	exit(-1);
#endif
}

void SHT31_break(void)
{
	com[0] = SHT31_COM_BREAK_M;
	com[1] = SHT31_COM_BREAK_L;
	HAL_I2C_Master_Transmit(&hi2c2, SHT31_SLAVE_ADDRESS, com, sizeof(com), 0xFF);
}

void SHT31_reset(void)
{
	com[0] = SHT31_COM_RESET_M;
	com[1] = SHT31_COM_RESET_L;
	HAL_I2C_Master_Transmit(&hi2c2, SHT31_SLAVE_ADDRESS, com, sizeof(com), 0xFF);
}
