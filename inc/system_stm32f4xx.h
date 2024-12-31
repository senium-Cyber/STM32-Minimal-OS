#ifndef __SYSTEM_STM32F4XX_H
#define __SYSTEM_STM32F4XX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/* 定义外部全局变量 */
extern uint32_t SystemCoreClock; /* 系统时钟频率 (Hz) */

/* 函数声明 */
void SystemInit(void);         /* 初始化系统时钟和默认状态 */
void SystemCoreClockUpdate(void); /* 更新 SystemCoreClock 变量 */

#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_STM32F4XX_H */
