#include "uart.h"

UART_HandleTypeDef huart2; // 使用 USART2

void UART_Init(void) {
    __HAL_RCC_USART2_CLK_ENABLE(); // 启用 USART2 时钟
    __HAL_RCC_GPIOA_CLK_ENABLE();  // 启用 GPIOA 时钟

    // 配置 GPIOA 引脚
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_2 | GPIO_PIN_3; // PA2: TX, PA3: RX
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // 配置 UART
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
    HAL_UART_Init(&huart2);
}

void UART_Send(const char *data) {
    HAL_UART_Transmit(&huart2, (uint8_t *)data, strlen(data), HAL_MAX_DELAY);
}

// UART 接收回调
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->Instance == USART2) {
        // 在此处理接收逻辑
    }
}

// UART 日志记录
void UART_Log(const char *format, ...) {
    char buffer[256]; // 日志缓冲区
    va_list args;     // 定义可变参数列表

    va_start(args, format);                    // 初始化可变参数
    vsnprintf(buffer, sizeof(buffer), format, args); // 格式化输出到缓冲区
    va_end(args);                              // 结束可变参数处理

    UART_Send(buffer); // 通过 UART 发送缓冲区内容
}
