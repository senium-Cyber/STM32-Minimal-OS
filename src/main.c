#include "stm32f4xx_hal.h"
#include "task_scheduler.h"
#include "peripherals.h"

// 全局变量
TIM_HandleTypeDef htim2; // 定时器用于任务调度

void SystemClock_Config(void);
void Error_Handler(void);

int main(void) {
    HAL_Init(); // 初始化 HAL 库
    SystemClock_Config(); // 配置系统时钟
    GPIO_Init(); // 初始化 GPIO
    Peripherals_Init(); // 初始化外设
    Interrupt_Init();
    UART_Init();
    I2C_Init();
    SPI_Init();
    // 初始化任务调度器
    TaskScheduler_Init();
    // 添加带优先级的任务
    TaskScheduler_AddTaskWithPriority(Task_BlinkLED, 1000, 1);
    while (1) {
        // 执行任务调度
        TaskScheduler_Run();
    }
}

void SystemClock_Config(void) {
    // 配置 STM32F401 的 HSE 时钟和 PLL
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 8;
    RCC_OscInitStruct.PLL.PLLN = 336;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 7;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
                                  RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK) {
        Error_Handler();
    }
}

void Error_Handler(void) {
    // 错误处理：LED 指示
    while (1) {
    }
}
