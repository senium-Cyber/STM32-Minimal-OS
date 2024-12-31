#ifndef __STM32F4XX_HAL_CONF_H
#define __STM32F4XX_HAL_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/* ########################## Module Selection ############################## */
#define HAL_MODULE_ENABLED
#define HAL_RCC_MODULE_ENABLED
#define HAL_GPIO_MODULE_ENABLED
#define HAL_DMA_MODULE_ENABLED
#define HAL_I2C_MODULE_ENABLED
#define HAL_UART_MODULE_ENABLED
#define HAL_TIM_MODULE_ENABLED

/* ######################### HSE/HSI Values adaptation ##################### */
#define HSE_VALUE    ((uint32_t)8000000)  /* External oscillator frequency in Hz */
#define HSI_VALUE    ((uint32_t)16000000) /* Internal oscillator frequency in Hz */

/* ########################### System Configuration ######################## */
#define  VDD_VALUE                    ((uint32_t)3300) /* Value in mv */
#define  TICK_INT_PRIORITY            ((uint32_t)0x0F) /* Lowest priority */
#define  USE_RTOS                     0
#define  PREFETCH_ENABLE              1
#define  INSTRUCTION_CACHE_ENABLE     1
#define  DATA_CACHE_ENABLE            1

/* ########################## Assert Selection ############################# */
#define USE_FULL_ASSERT    1U

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4XX_HAL_CONF_H */
