# Rambling Wreck by Ryan Kil and Janna Born
## Bluetooth controlled MBED robotic car. It will play audio when hitting the horn button on Bluetooth controller. Lighting is incorporated into headlights (white LED) and brake lights (red LED). It will also send sensor input back for obstacle detection. More features may be developed with further research on MBED Bluetooth capabilities.

[Rambling Wreck!](https://www.youtube.com/shorts/OATE5wvw6fY)

## Step by Step documentation to recreate the Rambling Wreck!

## Table of Contents

| Components | Description |
| ----- | ----------- |
| MBED LPC 1768 | Microcontroller to control all components |
| Breadboards | To connect everything via wires |
| 2x 4 Double AA Battery Power Pack | Generates the power for all components |
| 2x Power Jack | Adapter for the Battery Power Pack |
| Body and Wheels  | Chassis and Wheels placement |
| DC Gearbox Motors | The DC Gearbox Motors will drive the wheels |
| Dual H Bridge Motor Controller | The Dual H Bridge will drive both DC Gearbox Motors |
| Bluetooth Adafruit | UART bluetooth connection with controls via phone for the car |
| VL53L0X Lidar Sensor | ToF Distance Sensor for obstacle detection | 
| PCB Speaker | Output audio for Horn functionality |
| Red LED and White LED | Lighting functionality for headlight and brake lights |

## Step 1

To start off the Rambling Wreck, the wheels and chassis need to be properly built.
You can follow this [tutorial for chassis and wheel building](https://learn.sparkfun.com/tutorials/assembly-guide-for-redbot-with-shadow-chassis?_ga=1.167965857.1619691232.144081192) for a step by step instruction to mount the wheel into the chassis body.

## Step 2

Mount the breadboard on top (breadboard usually have a tape side on the bottom so we can easily just tape the breadboard across the top of the chassis) like shown below 
![Rambling Wreck](https//rkil3.github.io/RamblingWreckFront.jpg)

