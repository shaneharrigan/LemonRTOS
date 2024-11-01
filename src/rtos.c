#include "rtos.h"

task_t tasks[MAX_TASKS];

// Task creation function
void task_create(uint8_t taskId, void (*taskFunction)(void), uint16_t delay) {
    tasks[taskId].taskFunction = taskFunction;
    tasks[taskId].delayTicks = delay;
    tasks[taskId].remainingTicks = delay;
    tasks[taskId].active = 1;
}

// Task delay function
void task_delay(uint8_t taskId, uint16_t delay) {
    tasks[taskId].remainingTicks = delay;
}