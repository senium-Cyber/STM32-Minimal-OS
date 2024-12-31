#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H

#include <stdint.h>

/**
 * @brief 任务类型定义
 */
typedef struct {
    void (*task_function)(void); // 任务函数指针
    uint32_t period_ms;          // 任务周期，单位：毫秒
    uint32_t last_run_time;      // 上次运行时间，单位：毫秒
} Task;

/**
 * @brief 初始化任务调度器
 */
void TaskScheduler_Init(void);

/**
 * @brief 添加任务到任务调度器
 * @param task_function 任务函数指针
 * @param period_ms 任务运行周期
 */
void TaskScheduler_SortTasks(void) 
/**
 * @brief 优先级排序
 */
void TaskScheduler_AddTask(void (*task_function)(void), uint32_t period_ms);

/**
 * @brief 运行任务调度器，通常需要放在主循环中
 */
void TaskScheduler_Run(void);

/**
 * @brief 获取系统当前时间，单位：毫秒
 * @return 系统时间
 */
uint32_t TaskScheduler_GetSystemTime(void);

#endif // TASK_SCHEDULER_H
