
# Smart EV Battery Monitoring Using ESP32

## Project Overview
An ESP32-based simulated EV battery monitoring system with safety alerts.

## Features
- Battery voltage monitoring
- Current monitoring
- Power calculation
- Approximate battery percentage
- Low voltage alert using LED and buzzer
- Overcurrent alert using LED and buzzer
- OLED real-time display

## Components Used
- ESP32
- 2 Potentiometers (simulated sensor inputs)
- SSD1306 OLED Display
- LED
- Buzzer

## Pin Configuration
| Component | ESP32 GPIO |
|---|---|
| Voltage Input | 34 |
| Current Input | 35 |
| OLED SDA | 21 |
| OLED SCL | 22 |
| LED | 18 |
| Buzzer | 19 |

## Software & Technologies
- Embedded C / Arduino
- ESP32
- Wokwi Simulator
- Git & GitHub

## Simulation
[▶ Run Smart EV Battery Monitoring Simulation](https://wokwi.com/projects/480491524568263681)

## Working Principle
Potentiometers simulate battery voltage and current inputs.
ESP32 calculates power and approximate battery percentage.
LED and buzzer provide alerts when configured voltage or current thresholds are crossed.

## Future Improvements
- Real battery voltage and current sensors
- Battery State of Charge estimation
- IoT dashboard integration
- Hardware prototype testing
