#include "spi.h"

SPI_HandleTypeDef hspi1; // 使用 SPI1

void SPI_Init(void) {
    __HAL_RCC_SPI1_CLK_ENABLE(); // 启用 SPI1 时钟
    __HAL_RCC_GPIOA_CLK_ENABLE(); // 启用 GPIOA 时钟

    // 配置 GPIOA 引脚
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7; // PA5: SCK, PA6: MISO, PA7: MOSI
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // 配置 SPI
    hspi1.Instance = SPI1;
    hspi1.Init.Mode = SPI_MODE_MASTER;
    hspi1.Init.Direction = SPI_DIRECTION_2LINES;
    hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
    hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
    hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
    hspi1.Init.NSS = SPI_NSS_SOFT;
    hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
    hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
    hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
    HAL_SPI_Init(&hspi1);
}

void SPI_Send(uint8_t *pData, uint16_t Size) {
    HAL_SPI_Transmit(&hspi1, pData, Size, HAL_MAX_DELAY);
}
