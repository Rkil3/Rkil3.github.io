# by Ryan Kil and Janna Born
## Bluetooth controlled MBED robotic car. It will play audio when hitting the horn button on Bluetooth controller. Lighting is incorporated into headlights (white LED) and brake lights (red LED). It will also send sensor input back for obstacle detection. More features may be developed with further research on MBED Bluetooth capabilities.

[Link to Github Repository](https://github.com/Rkil3/Rkil3.github.io)

[A video demonstrating the Rambling Wreck!](https://www.youtube.com/shorts/OATE5wvw6fY)

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
You can follow this [tutorial for chassis and wheel building](https://learn.sparkfun.com/tutorials/assembly-guide-for-redbot-with-shadow-chassis?_ga=1.167965857.1619691232.144081192) for a step by step instruction to mount the wheel into the chassis body. The motor will be connected to the wheels to drive them. 

![parts](https://cdn.sparkfun.com/r/600-600/assets/learn_tutorials/3/3/7/Redbot_Kit-00_annotated_updated.jpg)

You will only need the physical components, the 2 Gearbox DC Motor, and the Batteries. 

## Step 2
![image](https://cdn.sparkfun.com//assets/parts/3/8/9/9/09835-01a.jpg)

and 

![image2](https://cdn.sparkfun.com//assets/parts/5/8/0/3/10811-03.jpg)


Next step is to grab **2x** 4 Double AA Battery Power Pack and the Power Adapter. These need to fit in between the body and make sure to have 2 of each. This is important because when the Rambling Wreck is wireless, it needs to have both to power the whole integrated system.

## Step 3

Mount the breadboard on top (breadboard usually have a tape side on the bottom so we can easily just tape the breadboard across the top of the chassis) Place the MBED LPC 1768 on the breadboard as shown

![MBED on Breadboard](https://os.mbed.com/media/uploads/mbedofficial/breadboardphoto.jpg)

## Step 4

![Bluetooth Adafruit](https://cdn-shop.adafruit.com/970x728/2633-04.jpg)

Place the Bluetooth Adafruit right below the MBED on the same breadboard. The pins will need to be soldered in order to plug directly into the breadboard. Below is the table for wiring between Bluetooth Adafruit and MBED.

| MBED | Bluetooth Adafruit |
| ----- | ----------- |
| gnd | gnd |
| VU(5v) | Vin(3.3-16V) |
| gnd | CTS |
| p14 (Serial RX) | TXO |
| p13 (Serial TX) | RXI |

After these connections are made, download the BluefruitConnect on your phone from the App Store and then we can control everything via your phone!

To test that this process works, you can try some of these example codes listed [here](https://os.mbed.com/users/4180_1/notebook/adafruit-bluefruit-le-uart-friend---bluetooth-low-/). Make sure to import correctly into kell studio to ensure that the code compiles smoothly.

## Step 5 

![motordriver](https://m.media-amazon.com/images/W/MEDIAX_792452-T1/images/I/51omiFpDDfL.__AC_SX300_SY300_QL70_FMwebp_.jpg)

Next step is to drive the motor with this Dual H Bridge.

Here is the wiring connection between MBED and Dual H Bridge.

| MBED | Dual H Bridge |
| ----- | ----------- |
| gnd | gnd |
| VOUT(3.3V) | VCC |
| p6 | AI1 |
| p5 | AI2 |
| p7 | BI1 |
| p8 | BI2 |
| p23 | PWMA |
| p22 | PWMB |

You will also need to connect the H Bridge to the main power and to the motor leads. Connect the 5V power supply coming from the batteries to VM directly and to STBY with a pull-up resistor. Connect the motor leads of the left motor to A01 and A02 on the H Bridge, and connect the leads of the right motor to B01 and B02.


## Step 6 

![lidarsensor](https://cdn-learn.adafruit.com/guides/images/000/001/516/medium800/VL53L0X_top.jpg)

This is a Time of Flight Sensor that will be used for obstable detection. 

Here is the wiring connection between MBED and Lidar Sensor

| MBED | ToF Sensor |
| ----- | ----------- |
| 3.3V | VIN |
| gnd | gnd |
| P28 | SDA |
| P27 | SCL |
| p26 | SHDN |

## Step 7

![uLCD](https://cdn.sparkfun.com//assets/parts/7/1/2/3/11377-01a.jpg)

The code will print a ASCII drawn driver to the uLCD which can be mounted on the driver side like an actual car!

Here is the wiring connection between the MBED and uLCD

| MBED | uLCD |
| ----- | ----------- |
| Vu | +5V |
| p10 | TX |
| p9 | RX |
| gnd | gnd |
| p11 | RES |

## Step 8

![PCBSpeaker](https://cdn.sparkfun.com//assets/parts/6/5/0/4/11089-01.jpg)

Now that we have the driver and the Rambling Wreck set up, here we will add a nice little feature to be able to honk the horn using the PCB Speaker. To do this, we will use a general purpose amplifier, and p21 on the mbed will be a PWM output that controls the speaker.

![speaker wiring diagram](https://os.mbed.com/media/uploads/4180_1/_scaled_speakerdriverschem.png) ![general purpose amplifier](https://os.mbed.com/media/uploads/4180_1/2n3904.jpg)

| MBED | Amplifier | PCB Speaker |
| ----- | ---------- | ----------- |
|  | C | - |
| p21 (via resistor) | B |  |
| Gnd | E |  |
| VOUT |  | + |

For more information on how to set this up, refer to [this page](https://os.mbed.com/users/4180_1/notebook/using-a-speaker-for-audio-output/).

## Step 9

![LEDwhite](https://www.arborsci.com/cdn/shop/products/WhiteLED1500x1000.jpg?v=1617221784)

and ![LEDred](https://www.arborsci.com/cdn/shop/products/redLED1500x1000.jpg?v=1684434191)

Using these LED's, connect the longer end to the MBED pins listed below and connect the shorter end to ground (gnd).

| MBED | LEDs |
| ----- | ----------- |
| gnd | Short End |
| P24 | White LED Long End |
| P25 | Red LED Long End |

Here we use the two small breadboards to put each in the front and back part of the body. For the front part, the wnite LED's will be connected making them head lights. The back breadboard will have the red LED's for brake lights.

## Step 10

Lastly, we run the code main.cpp located on [Rkil3.github.io](https://github.com/Rkil3/Rkil3.github.io) repository. Make sure to have all libraries imported.

Open the BluefruitConnect app on your phone, and then connect via bluetooth.

Go to the control section and start driving the Rambling Wreck!


