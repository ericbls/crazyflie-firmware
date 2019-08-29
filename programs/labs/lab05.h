#include "mbed.h"
#include "crazyflie.h"

// Define motors as PWM output object
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

// Define angular velocities (rad/s)
float omega_r_1;
float omega_r_2;
float omega_r_3;
float omega_r_4;

// Declarando funcão que checa se existe raiz de um número negativo
float checaRaiz(float omega)
{
    if (omega>=0.0)
    {
        return sqrt(omega);
    }
    else
    {
        return 0.0;
    }
}

// Converts desired angular velocity (rad/s) to PWM signal (%)
float control_motor(float omega_r)
{
    return (a2*(omega_r*omega_r))+(a1*omega_r);
}

// Converts total trust force (N) and torques (N.m) to angular velocities (rad/s)
void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    omega_r_1 = checaRaiz((f_t/(4*kl))-(tau_phi/(4*kl*l))-(tau_theta/(4*kl*l))-(tau_psi/(4*kd)));
    omega_r_2 = checaRaiz((f_t/(4*kl))-(tau_phi/(4*kl*l))+(tau_theta/(4*kl*l))+(tau_psi/(4*kd)));
    omega_r_3 = checaRaiz((f_t/(4*kl))+(tau_phi/(4*kl*l))+(tau_theta/(4*kl*l))-(tau_psi/(4*kd)));
    omega_r_4 = checaRaiz((f_t/(4*kl))+(tau_phi/(4*kl*l))-(tau_theta/(4*kl*l))+(tau_psi/(4*kd)));
}

// Actuate motors with desired total trust force (N) and torques (N.m)
void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    mixer(f_t, tau_phi, tau_theta, tau_psi);
    motor1 = control_motor(omega_r_1);
    motor2 = control_motor(omega_r_2);
    motor3 = control_motor(omega_r_3);
    motor4 = control_motor(omega_r_4);
}

// Main program
int main()
{
    wait(5);
    // Actuate motor with 70% mg total thrust force (N) and zero torques
    actuate(0,0,0,-0.001);
    wait(3);
    // Turn off all motors
    actuate(0,0,0,0);
    // End of PROGRAM
    while(true)
    {}
}