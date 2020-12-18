/*
 * GY30.c
 *
 *  Created on: 2020年12月18日
 *      Author: hunterteaegg
 */
#include "GY30.h"
#include <stdint.h>
#include "stm32f1xx_hal.h"

extern I2C_HandleTypeDef hi2c2;
uint8_t com;
uint8_t rawData[2];

void GY30_init(uint8_t addr)
{
	com = GY30_MODE;
	HAL_I2C_Master_Transmit(&hi2c2, addr, &com, sizeof(com), 0xFF);
#if ((GY30_MODE & 0x03) == 0x03)
	HAL_Delay(50);
#else
	HAL_Delay(180);
#endif
}

double GY30_getData(uint8_t addr)
{
#if ((GY30_MODE & 0x10) == 0x10)
	;
#elif ((GY30_MODE & 0x20) == 0x20)
	com = GY30_POWER_ON;
	HAL_I2C_Master_Transmit(&hi2c2, addr, &com, sizeof(com), 0xFF);
#endif
	HAL_I2C_Master_Receive(&hi2c2, addr, rawData, sizeof(rawData), 0xFF);
	uint16_t temp = ((rawData[0] << 8) | rawData[1]);

	return ((double)temp / 1.2);
}
