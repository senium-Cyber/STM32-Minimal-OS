#ifndef SPI_H
#define SPI_H

#include "stm32f4xx_hal.h"

// SPI 初始化函数
void SPI_Init(void);

// SPI 发送数据函数
void SPI_Send(uint8_t *pData, uint16_t Size);

#endif // SPI_H
