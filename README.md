🍋 LemonRTOS 🍋

Welcome to LemonRTOS – a zesty, lightweight Real-Time Operating System (RTOS) designed to be as refreshing as a squeeze of lemon juice on a hot summer day! 🍋 Built for fun, flexibility, and simplicity, LemonRTOS is ideal for hobby projects, embedded systems, and learning the basics of RTOS design.

🌟 Key Features

	•	Squeeze the Most Out of Limited Hardware: Designed to run on microcontrollers like the Arduino Uno (ATmega328P), LemonRTOS packs a punch even in the smallest of setups.
	•	Juicy Round-Robin Scheduling: Simple and effective round-robin scheduler with delay handling.
	•	Task Management: Create, run, and delay tasks with an easy-to-use API.
	•	Cross-Platform Simulation: Test and simulate your RTOS logic on your computer with pthread before deploying it to hardware – no lemons lost in translation!

🍋 Project Structure

LemonRTOS is organized for both simulation on a PC and deployment on embedded devices like the Arduino Uno.
```bash
lemonRTOS/
├── include/
│   └── rtos.h            # Core RTOS definitions and declarations
├── src/
│   ├── main.c            # Main application and example tasks
│   ├── rtos.c            # Core RTOS logic (shared)
│   ├── rtos_arduino.c    # Platform-specific code for Arduino
│   └── rtos_simulator.c  # Platform-specific code for simulator
└── Makefile
```
🚀 Getting Started

1. Clone the Repository
```bash
git clone https://github.com/yourusername/lemonRTOS.git
cd lemonRTOS
```
2. Flash to Arduino Uno

LemonRTOS is designed to run on the ATmega328P, used in Arduino Uno. Once your code is ready, compile with avr-gcc and flash it with avrdude (see the Makefile comments for details on how to do this).

🛠 Usage

To create tasks, define functions with the task logic and then use task_create() to add them to the scheduler. Here’s a quick example:
```c
void my_task(void) {
    // Task code goes here
}

int main(void) {
    task_create(0, my_task, 500); // Run `my_task` every 500 ms
    rtos_start();                  // Start the LemonRTOS scheduler
    return 0;
}
```

1. Build for Simulator:
```bash
make simulator
./lemonRTOS_simulator
```

2. Build for Arduino:
```bash
make arduino
make flash
```

🍋 Example Tasks

Included in the code are two demo tasks:

	•	Task Blink: Simulates blinking an LED on and off at a slower pace.
	•	Task Fast Blink: Blinks the LED at a faster rate, so you get a refreshing mix of speeds!

🧃 Why LemonRTOS?

LemonRTOS is all about simplicity, learning, and having fun with embedded systems. It’s designed to be easy enough to understand while teaching the fundamentals of real-time operating systems.

🛠 Development and Contributions

Want to add more flavor to LemonRTOS? 🍋 Contributions are welcome! Feel free to submit a pull request or raise issues to discuss improvements, new features, or bug fixes.

	1.	Fork the repo 🍴
	2.	Create your feature branch (git checkout -b feature/juicy-feature)
	3.	Commit your changes (git commit -m 'Add juicy feature')
	4.	Push to the branch (git push origin feature/juicy-feature)
	5.	Open a pull request 🚀

🏛 License

LemonRTOS is open-source under the MIT License. Feel free to squeeze the code into your own projects.

🎉 Acknowledgments

Thank you to the lemon tree for inspiring this refreshing project! 🍋

Enjoy squeezing the best performance out of your hardware with LemonRTOS!