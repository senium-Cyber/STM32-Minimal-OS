#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "stm32f4xx_hal.h"

// 初始化中断
void Interrupt_Init(void);

// 用户中断回调函数声明
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#endif // INTERRUPT_H
