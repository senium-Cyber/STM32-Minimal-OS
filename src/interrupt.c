#include "interrupt.h"

void Interrupt_Init(void) {
    // 配置外部中断 (例如，GPIO 中断)
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // 启用 GPIO 时钟
    __HAL_RCC_GPIOA_CLK_ENABLE();

    // 配置 GPIO 引脚 (例如，PA0 作为中断输入)
    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING; // 上升沿触发中断
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // 启用中断
    HAL_NVIC_SetPriority(EXTI0_IRQn, 2, 0); // 设置优先级
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

// 用户中断回调
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == GPIO_PIN_0) {
        // 在此处理中断逻辑
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13); // 例如：切换 LED
    }
}
