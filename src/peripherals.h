#ifndef PERIPHERALS_H
#define PERIPHERALS_H

#include "stm32f4xx_hal.h"

/**
 * @brief 初始化 GPIO 外设
 * @note 例如用于 LED 指示灯
 */
void Peripherals_InitGPIO(void);

/**
 * @brief 初始化 I2C 外设
 * @note 例如用于 MPU6050 等传感器
 */
void Peripherals_InitI2C(I2C_HandleTypeDef *hi2c);

/**
 * @brief 初始化 UART 外设
 * @note 用于串口调试或数据传输
 */
void Peripherals_InitUART(UART_HandleTypeDef *huart);

/**
 * @brief 初始化定时器
 * @note 用于 PWM 或周期性中断
 */
void Peripherals_InitTimer(TIM_HandleTypeDef *htim);

#endif // PERIPHERALS_H
