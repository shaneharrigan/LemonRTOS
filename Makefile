# Makefile for LemonRTOS (Simulator and Arduino)

# Microcontroller for Arduino build
MCU = atmega328p
F_CPU = 16000000UL

# Compiler and flags
CC = gcc
AVR_CC = avr-gcc
AVR_OBJCOPY = avr-objcopy
AVRDUDE = avrdude
AVRDUDE_FLAGS = -c arduino -p $(MCU) -P /dev/ttyUSB0 -b 115200  # Update /dev/ttyUSB0 as needed

# Directories and files
SRC = src/main.c src/rtos.c
TARGET_SIMULATOR = lemonRTOS_simulator
TARGET_ARDUINO = lemonRTOS_arduino.elf
HEX = lemonRTOS_arduino.hex

# Default target
all: simulator

# Simulator build
simulator: $(SRC) src/rtos_simulator.c
	$(CC) -DSIMULATOR -Iinclude -o $(TARGET_SIMULATOR) $(SRC) src/rtos_simulator.c -lpthread

# Arduino build
arduino: $(SRC) src/rtos_arduino.c
	$(AVR_CC) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DARDUINO -Iinclude -o $(TARGET_ARDUINO) $(SRC) src/rtos_arduino.c
	$(AVR_OBJCOPY) -O ihex -R .eeprom $(TARGET_ARDUINO) $(HEX)

# Flash to Arduino
flash: $(HEX)
	$(AVRDUDE) $(AVRDUDE_FLAGS) -U flash:w:$(HEX)

# Clean build files
clean:
	rm -f $(TARGET_SIMULATOR) $(TARGET_ARDUINO) $(HEX)