#include "rtos.h"

void task_blink(void) {
#ifdef ARDUINO
    PORTB ^= (1 << PB5);  // Toggle LED on Arduino
#else
    printf("Task Blink: LED ON\n");
    usleep(500000);       // Simulate work for 500 ms
    printf("Task Blink: LED OFF\n");
#endif
    task_delay(0, 500);  // Delay for 500 ms
}

void task_fast_blink(void) {
#ifdef ARDUINO
    PORTB ^= (1 << PB5);  // Toggle LED on Arduino
#else
    printf("Task Fast Blink: LED TOGGLE\n");
    usleep(100000);       // Simulate work for 100 ms
#endif
    task_delay(1, 100);  // Delay for 100 ms
}

int main(void) {
#ifdef ARDUINO
    DDRB |= (1 << PB5);  // Set PB5 as output on Arduino
#endif

    task_create(0, task_blink, 500);
    task_create(1, task_fast_blink, 100);
    rtos_start();

    return 0;
}