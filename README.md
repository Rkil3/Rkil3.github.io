# Rambling Wreck by Ryan Kil and Janna Born
## Bluetooth controlled MBED robotic car. It will play audio when hitting the horn button on Bluetooth controller. Lighting is incorporated into headlights (white LED) and brake lights (red LED). It will also send sensor input back for obstacle detection. More features may be developed with further research on MBED Bluetooth capabilities.

[Rambling Wreck!](https://www.youtube.com/shorts/OATE5wvw6fY)

## Step by Step documentation to recreate the Rambling Wreck!

## Table of Contents

| Components | Description |
| ----- | ----------- |
| MBED LPC 1768 | Microcontroller to control all components |
| 1 long Breadboard | To connect everything via wires |
| 2 small Breadboard | To connect leds for headlight and brake lights |
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
![image](https://cdn.sparkfun.com//assets/parts/3/8/9/9/09835-01a.jpg)

and 

![image2](https://cdn.sparkfun.com//assets/parts/5/8/0/3/10811-03.jpg)


Next step is to grab **2x** 4 Double AA Battery Power Pack and the Power Adapter. 

## Step 3

Mount the breadboard on top (breadboard usually have a tape side on the bottom so we can easily just tape the breadboard across the top of the chassis) Place the MBED LPC 1768 on the breadboard as shown

![MBED on Breadboard](https://os.mbed.com/media/uploads/mbedofficial/breadboardphoto.jpg)

## Step 4

![Bluetooth Adafruit](https://cdn-shop.adafruit.com/970x728/2633-04.jpg)

Place the Bluetooth Adafruit right below the MBED on the same breadboard. The pins will need to be soldered in order to plug directly into the breadboard. Below is the table for wiring between Bluetooth Adafruit and MBED.

| MBED | Bluetooth Adafruit |
| ----- | ----------- |
| gnd | gnd |
| VU(5v) | Vin(3.3-16V)
| nc | RTS |
| gnd | CTS |
| p27 (Serial RX) | TXO |
| p28 (Serial TX) | RXI |

After these connections are made, download the BluefruitConnect on your phone from the App Store and then we can control everything via your phone!

To test that this process works, you can try some of these example codes listed [here](https://os.mbed.com/users/4180_1/notebook/adafruit-bluefruit-le-uart-friend---bluetooth-low-/). Make sure to import correctly into kell studio to ensure that the code compiles smoothly.




