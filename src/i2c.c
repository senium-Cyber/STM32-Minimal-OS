#include "i2c.h"

I2C_HandleTypeDef hi2c1; // 使用 I2C1

void I2C_Init(void) {
    __HAL_RCC_I2C1_CLK_ENABLE(); // 启用 I2C1 时钟
    __HAL_RCC_GPIOB_CLK_ENABLE(); // 启用 GPIOB 时钟

    // 配置 GPIOB 引脚
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7; // PB6: SCL, PB7: SDA
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    // 配置 I2C
    hi2c1.Instance = I2C1;
    hi2c1.Init.ClockSpeed = 100000; // 100kHz
    hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
    hi2c1.Init.OwnAddress1 = 0;
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
    HAL_I2C_Init(&hi2c1);
}

void I2C_Send(uint16_t DevAddress, uint8_t *pData, uint16_t Size) {
    HAL_I2C_Master_Transmit(&hi2c1, DevAddress, pData, Size, HAL_MAX_DELAY);
}
