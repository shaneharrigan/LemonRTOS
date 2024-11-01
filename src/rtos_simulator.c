#include "rtos.h"

// Simulator scheduler function
void *scheduler(void *arg) {
    while (1) {
        for (int i = 0; i < MAX_TASKS; i++) {
            if (tasks[i].active && tasks[i].remainingTicks == 0) {
                tasks[i].taskFunction();
                tasks[i].remainingTicks = tasks[i].delayTicks;  // Reset delay
            }
            usleep(1000);  // Simulate a 1ms tick
            if (tasks[i].remainingTicks > 0) {
                tasks[i].remainingTicks--;  // Decrement remaining ticks
            }
        }
    }
    return NULL;
}

// Start the RTOS simulation
void rtos_start(void) {
    pthread_t schedulerThread;
    pthread_create(&schedulerThread, NULL, scheduler, NULL);
    pthread_join(schedulerThread, NULL);
}