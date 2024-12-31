#include "task_scheduler.h"

// 定义任务结构
typedef struct {
    void (*taskFunc)(void); // 任务函数指针
    uint32_t period;        // 任务周期
    uint32_t lastRunTime;   // 上次运行时间
} Task;

#define MAX_TASKS 5
Task taskList[MAX_TASKS];
uint32_t systemTick = 0; // 系统滴答计数

void TaskScheduler_Init(void) {
    systemTick = HAL_GetTick();
    for (int i = 0; i < MAX_TASKS; i++) {
        taskList[i].taskFunc = NULL;
    }
}

void TaskScheduler_AddTask(void (*taskFunc)(void), uint32_t period) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (taskList[i].taskFunc == NULL) {
            taskList[i].taskFunc = taskFunc;
            taskList[i].period = period;
            taskList[i].lastRunTime = 0;
            break;
        }
    }
}

void TaskScheduler_Run(void) {
    uint32_t currentTime = HAL_GetTick();
    for (int i = 0; i < MAX_TASKS; i++) {
        if (taskList[i].taskFunc != NULL &&
            (currentTime - taskList[i].lastRunTime) >= taskList[i].period) {
            taskList[i].taskFunc();
            taskList[i].lastRunTime = currentTime;
        }
    }
}
