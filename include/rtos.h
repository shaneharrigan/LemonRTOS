#ifndef RTOS_H
#define RTOS_H

#include <stdint.h>  // Fixed-width integer types (e.g., uint16_t)

#define MAX_TASKS 2

#ifdef ARDUINO
#include <avr/io.h>
#else
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>  // For usleep in simulator
#endif

// Task structure
typedef struct {
    void (*taskFunction)(void);  // Task function pointer
    uint16_t delayTicks;         // Delay in ticks
    uint16_t remainingTicks;     // Countdown for task delay
    uint8_t active;              // Whether the task is active
} task_t;

extern task_t tasks[MAX_TASKS];

// Function declarations
void task_create(uint8_t taskId, void (*taskFunction)(void), uint16_t delay);
void task_delay(uint8_t taskId, uint16_t delay);
void rtos_start(void);

#endif