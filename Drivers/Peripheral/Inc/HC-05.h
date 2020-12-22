/*
 * HC-05.h
 *
 *  Created on: Dec 22, 2020
 *      Author: hunterteaegg
 */

#ifndef PERIPHERAL_INC_HC_05_H_
#define PERIPHERAL_INC_HC_05_H_

#include <stdint.h>

/*
 * @brief Initialize HC05 module (no complement yet)
 */
void HC05_init(void);

/*
 * @brief Transmit data to HC05 module by UART2
 * @param pdata Pointer to memory including bytes ready to send
 * @param len Length of bytes
 */
void HC05_transmit(char *pdata,int len);

#endif /* PERIPHERAL_INC_HC_05_H_ */
