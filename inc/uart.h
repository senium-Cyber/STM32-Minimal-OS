#ifndef UART_H
#define UART_H

#include "stm32f4xx_hal.h"

// UART 初始化函数
void UART_Init(void);

// UART 发送数据函数
void UART_Send(const char *data);

// UART 进行日志记录
void UART_Log(const char *format, ...);

// UART 接收数据回调
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif // UART_H
