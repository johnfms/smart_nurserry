# AVR Temperature Control Project

## Overview
This project implements a simple temperature control system using an AVR microcontroller. The code reads analog temperature values from an ADC channel and controls LED outputs based on different temperature ranges.

## Hardware Requirements
- AVR Microcontroller (e.g., ATmega series)
- Temperature Sensor (Analog)
- LEDs connected to PORTC
- Appropriate development board or breadboard setup

## Features
- Initializes Analog-to-Digital Converter (ADC)
- Reads temperature from ADC channel 0
- Controls LED outputs based on temperature thresholds:
  - LED1 (0x01) turns ON when temperature > 30
  - LED2 (0x02) turns ON when temperature < 10
  - Both LEDs OFF for temperatures between 10-30

## Pin Configuration
- PORTC: Output for LED control
- PORTA: Input for ADC channel 0

## Code Explanation

### ADC Initialization (`adc_init()`)
- Configures ADC reference voltage (AVCC with external capacitor)
- Sets prescaler to 128 for ADC clock
- Enables ADC

### ADC Reading (`adc_read()`)
- Supports channels 0-7
- Starts ADC conversion
- Waits for conversion to complete
- Returns 10-bit ADC value (0-1023)

## Dependencies
- avr/io.h
- util/delay.h

## Connections
1. Connect temperature sensor to ADC channel 0
2. Connect LEDs to PORTC
3. Ensure proper power and ground connections
