
#include "mbed.h"
#include "PwmOut.h"
#include "DigitalOut.h"
#include "rtos.h"
#include "Motor.h"
#include "uLCD_4DGL.h"
#include "XNucleo53L0A1.h"


// BusOut myled(LED1, LED2, LED3, LED4);
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

DigitalOut headlights(p24);
DigitalOut brakelights(p25);

PwmOut speaker(p21);
uLCD_4DGL LCD(p9,p10,p11); // serial tx, serial rx, reset pin;

Motor motA(p23, p6, p5); // pwm, fwd, rev
Motor motB(p22, p7, p8);

Serial blue(p13,p14);
Serial pc(USBTX, USBRX);

// This VL53L0X board test application performs a range measurement in polling mode
// Use 3.3(Vout) for Vin, p28 for SDA, p27 for SCL, P26 for shdn on mbed LPC1768
DigitalOut shdn(p26);
//I2C sensor pins
#define VL53L0_I2C_SDA   p28
#define VL53L0_I2C_SCL   p27
static XNucleo53L0A1 *board=NULL;



// mutex to make the lcd lib thread safe
Mutex lcd_mutex;


int main()
{
    pc.printf("starting code...");
    LCD.cls();
    LCD.color(WHITE);
    LCD.printf(" _______________\n|               |\n| I'm a helluva |\n|   engineer!   |\n|_____  ________|\n      \\|  \n          ___\n         /. .\\\n           u   \n         \\___/\n       _  /|\\\n      / \\/ | \\\n      \\_/ / \\\n         /   \\\n=================\n=================");

    speaker.period(1.0/500.0); // 500hz period
    brakelights.write(1);

    int status;
    uint32_t distance;
    DevI2C *device_i2c = new DevI2C(VL53L0_I2C_SDA, VL53L0_I2C_SCL);
    // /* creates the 53L0A1 expansion board singleton obj */
    board = XNucleo53L0A1::instance(device_i2c, A2, D8, D2);  // YOU KILLED MY FATHER PREPARE TO DIE (this is where the LCD malfunction originates)
    shdn = 0; //must reset sensor for an mbed reset to work
    wait(0.1);
    shdn = 1;
    wait(0.1);
    /* init the 53L0A1 board with default values */
    status = board->init_board();
    while (status) {
        pc.printf("Failed to init board! \r\n");
        status = board->init_board();
    }


    char bnum=0;
    char bhit=0;
    while(1) {
        // pc.printf("test\n");
        char temp = blue.getc();
        pc.printf("temp: %c", temp);
        if (temp=='!') {
            if (blue.getc()=='B') { //button data packet
                bnum = blue.getc(); //button number
                bhit = blue.getc(); //1=hit, 0=release
                if (blue.getc()==char(~('!' + 'B' + bnum + bhit))) { //checksum OK?
                    // myled = bnum - '0'; //current button number will appear on LEDs
                    switch (bnum) {
                        case '1': //number button 1
                            if (bhit=='1') {
                                //add hit code here
                                speaker.period(1.0/500.0); // 500hz period
                                speaker = 0.2;
                            } else {
                                //add release code here
                                speaker = 0;
                            }
                            break;
                        case '2': //number button 2
                            if (bhit=='1') {
                                //add hit code here
                                headlights.write(!headlights.read());
                            } else {
                                //add release code here
                            }
                            break;
                        case '3': //number button 3
                            if (bhit=='1') {
                                speaker.period(1.0/600.0); // 600hz period
                                speaker = 0.2;
                            } else {
                                //add release code here
                                speaker = 0;
                            }
                            break;
                        case '4': //number button 4
                            if (bhit=='1') {
                                speaker.period(1.0/750.0); // 600hz period
                                speaker = 0.2;
                            } else {
                                //add release code here
                                speaker = 0;
                            }
                            break;
                        case '5': //button 5 up arrow
                            if (bhit=='1') {
                                //add hit code here
                                status = board->sensor_centre->get_distance(&distance);
                                if ((status == VL53L0X_ERROR_NONE && (distance > 150 || distance < 50)) || (status == VL53L0X_ERROR_RANGE_ERROR)) {
                                    // pc.printf("D=%ld mm\r\n", distance);
                                    led1 = 1;
                                    motA.speed(1);
                                    motB.speed(1);
                                    brakelights.write(0);
                                } else {
                                    // pc.printf("Status=%ld\r\n", status);
                                    // pc.printf("D=%ld mm\r\n", distance);
                                    // pc.printf("too close to move!\n");
                                }
                                
                            } else {
                                //add release code here
                                brakelights.write(1);
                                motA.speed(0);
                                motB.speed(0);
                            }
                            break;
                        case '6': //button 6 down arrow
                            if (bhit=='1') {
                                //add hit code here
                                brakelights.write(0);
                                motA.speed(-1);
                                motB.speed(-1);
                            } else {
                                //add release code here
                                brakelights.write(1);
                                motA.speed(0);
                                motB.speed(0);
                            }
                            break;
                        case '7': //button 7 left arrow
                            if (bhit=='1') {
                                //add hit code here
                                brakelights.write(0);
                                motA.speed(1);
                                motB.speed(-1);
                            } else {
                                //add release code here
                                brakelights.write(1);
                                motA.speed(0);
                                motB.speed(0);
                            }
                            break;
                        case '8': //button 8 right arrow
                            if (bhit=='1') {
                                //add hit code here
                                brakelights.write(0);
                                motA.speed(-1);
                                motB.speed(1);
                            } else {
                                //add release code here
                                brakelights.write(1);
                                motA.speed(0);
                                motB.speed(0);
                            }
                            break;
                        default:
                            break;
                    }
                }
            }
        } else {
            // pc.printf("text input:\n");
            // LCD.cls(); // boy dies here :(
            while (temp != '\n') {
                pc.printf("temp: %c", temp);
                // LCD.printf("%c", temp);
                temp = blue.getc();
            }
        }
    }
}
