#include "mbed.h"
#include "crazyflie.h"

// Define motors as PWM output object
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

// Define red LED (right) as digital output object
DigitalOut led(LED_RED_R,!false);

// Converts desired angular velocity (rad/s) to PWM signal (%)
float control_motor(float omega_r)
{
    return (a2*(omega_r*omega_r))+(a1*omega_r);
}

// Main program
int main()
{
    int timer = 0;

    // Blink red LED______________________________________
    while(timer<8) 
    {
        led = !led;
        wait(0.5);
        timer=timer+1;
    }

    // Turn on motors with X rad/s_______________________
    float motor_1000 = control_motor(1000);
    float motor_2000 = control_motor(2000);
    motor1 = motor_1000;
    motor2 = motor_2000;
    motor3 = motor_1000;
    motor4 = motor_2000;
    wait(10);

    // Turn off motor 1
    motor1 = 0;
    motor2 = 0;
    motor3 = 0;
    motor4 = 0;

    // End of program
    while(true){
    }
    return 0;
}