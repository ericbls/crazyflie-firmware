#include "mbed.h"
#include "crazyflie.h"

// Define all leds objects
DigitalOut led1(LED_GREEN_R,!false);
DigitalOut led2(LED_RED_R,!false);
DigitalOut led3(LED_BLUE_L,!false);

// Define all motors as PWM objects
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

// Main program
int main()
{

    // Blink blue led indicating initialization
    int contador = 0;
    while(contador < 10) 
    {
        led3 = !led3;
        wait(0.5);
        contador=contador+1;
    }
    led3 = !false;
    contador=0;
    

    // Turn on red LEDs indicating motors are armed
    led2=!led2;
    wait(1);

    // Test all motors with different frequencies (to make different noises)
    float p_test=0.1;
    int motor_n=1;
    while(motor_n<5)
    {
        while(p_test < 0.5)
        {
            switch (motor_n)
            {
                case 1:
                    motor1=p_test;
                    wait(0.4);
                    motor1=0;
                    wait(0.4);
                break;
                case 2:
                    motor2=p_test;
                    wait(0.4);
                    motor2=0;
                    wait(0.4);
                break;
                case 3:
                    motor3=p_test;
                    wait(0.4);
                    motor3=0;
                    wait(0.4);
                break;
                case 4:
                    motor4=p_test;
                    wait(0.4);
                    motor4=0;
                    wait(0.4);
                break;
            }
            p_test=p_test+0.1;
        }
        motor_n=motor_n+1;
    }

    // Turn off red LEDs indicating motors are disarmed
    led2=!led2;

    // Blink green LEDs indicating end of program
    while(contador < 10) 
    {
        led3 = !false;
        wait(0.1);
        contador=contador+1;
    }
}
