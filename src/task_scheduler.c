#include "task_scheduler.h"

// 定义任务结构
typedef struct {
    void (*taskFunc)(void); // 任务函数指针
    uint32_t period;        // 任务周期
    uint32_t lastRunTime;   // 上次运行时间
    uint8_t priority;       // 任务优先级
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
// 根据优先级排序任务列表
void TaskScheduler_SortTasks(void) {
    for (int i = 0; i < MAX_TASKS - 1; i++) {
        for (int j = 0; j < MAX_TASKS - i - 1; j++) {
            if (taskList[j].priority < taskList[j + 1].priority) {
                Task temp = taskList[j];
                taskList[j] = taskList[j + 1];
                taskList[j + 1] = temp;
            }
        }
    }
}

// 添加任务时支持优先级设置
void TaskScheduler_AddTask(void (*taskFunc)(void), uint32_t period, uint8_t priority) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (taskList[i].taskFunc == NULL) {
            taskList[i].taskFunc = taskFunc;
            taskList[i].period = period;
            taskList[i].lastRunTime = 0;
            taskList[i].priority = priority;
            TaskScheduler_SortTasks(); // 排序
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
