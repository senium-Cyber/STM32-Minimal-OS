#ifndef I2C_H
#define I2C_H

#include "stm32f4xx_hal.h"

// I2C 初始化函数
void I2C_Init(void);

// I2C 发送数据函数
void I2C_Send(uint16_t DevAddress, uint8_t *pData, uint16_t Size);

#endif // I2C_H
