/*
 * lcd1602.h
 *
 *  Created on: Oct 13, 2020
 *      Author: hunterteaegg
 */

#ifndef INC_LCD1602_H_
#define INC_LCD1602_H_

#include "main.h"
#include <stm32f1xx_hal.h>

/*
 * @brief Initialize LCD1602
 */
void LCD_init(void);

/*
 * @brief Write Command to LCD1602
 * @param com Command ready to send
 */
void LCD_writeCom(uint8_t com);

/*
 * @brief Write Data to LCD1602
 * @param data Data ready to send
 */
void LCD_writeData(uint8_t data);

/*
 * @brief Show GY30 data
 * @param result The result from GY30
 */
void LCD_show_GY30(uint16_t result);

/*
 * @brief Show SHT31 data
 * @param temp Temperature acquired from SHT31
 * @param humi Humidity acquired from SHT31
 */
void LCD_show_SHT31(uint16_t temp, uint16_t humi);

/*
 * @brief CRC8 Checksum
 * @param pdat The pointer to memory ready to be checked
 * @param len The length of memory ready to be checked
 * @param factor
 */
uint8_t CRC8_compute(const uint8_t *pdat, short len, const uint8_t factor);

//void LCD_showByte(uint8_t byte);

#endif /* INC_LCD1602_H_ */
