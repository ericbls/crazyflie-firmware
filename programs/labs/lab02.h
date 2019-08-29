#include "mbed.h"
#include "crazyflie.h"

// Define motor 1 as PWM output object
PwmOut motor(MOTOR1);
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
    // Blink red LED
    while(timer<8) 
    {
        led = !led;
        wait(0.5);
        timer=timer+1;
    }

    // Turn on motor 1 with 1000 rad/s
    motor = control_motor(1000.0);
    // motor = 0.2;
    wait(5);

    // Turn off motor 1
    motor = 0.0;

    // End of program
    while(true){

    }

    return 0;
}
