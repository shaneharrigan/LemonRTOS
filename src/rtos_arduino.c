#include "rtos.h"
#include <avr/interrupt.h>

// Timer1 interrupt service routine (ISR) for 1ms tick
ISR(TIMER1_COMPA_vect) {
    for (uint8_t i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].active && tasks[i].remainingTicks > 0) {
            tasks[i].remainingTicks--;
            if (tasks[i].remainingTicks == 0) {
                tasks[i].taskFunction();
                tasks[i].remainingTicks = tasks[i].delayTicks;  // Reset delay
            }
        }
    }
}

// Start the RTOS by configuring Timer1 for a 1ms tick
void rtos_start(void) {
    // Configure Timer1 for CTC mode with 1ms tick at 16 MHz CPU clock
    TCCR1A = 0;
    TCCR1B = (1 << WGM12) | (1 << CS11);  // CTC mode, prescaler = 8
    OCR1A = 1999;                         // Set compare value for 1ms at 16MHz
    TIMSK1 = (1 << OCIE1A);               // Enable Timer1 compare interrupt
    sei();                                // Enable global interrupts

    while (1) {
        // Main loop left empty, tasks handled by interrupt
    }
}