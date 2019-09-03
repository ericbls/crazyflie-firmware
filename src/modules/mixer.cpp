#include "mixer.h"

// Define motors as PWM output object

Mixer::Mixer() : motor1(MOTOR1), motor2(MOTOR2), motor3(MOTOR3), motor4(MOTOR4), led1(LED_RED_R), led2(LED_GREEN_L)
{}

float Mixer::checaRaiz(float x)
{
    if (x>=0.0)
    {
        return sqrt(x);
    }
    else
    {
        return 0.0;
    }
}

void Mixer::arm()
{
    armed=true;
    led1=true;
    led2=false;
}

void Mixer::disarm()
{
    armed=false;
    led1=false;
    led2=true;
    motor1=0.0;
    motor2=0.0;
    motor3=0.0;
    motor4=0.0;
}

void Mixer::actuate(float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    if(armed)
    {
        getMixer(f_t, tau_phi, tau_theta, tau_psi);
        motor1 = motorControl(omega1);
        motor2 = motorControl(omega2);
        motor3 = motorControl(omega3);
        motor4 = motorControl(omega4);
    }
}

void Mixer::getMixer(float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    omega1 = checaRaiz((f_t/(4*kl))-(tau_phi/(4*kl*l))-(tau_theta/(4*kl*l))-(tau_psi/(4*kd)));
    omega2 = checaRaiz((f_t/(4*kl))-(tau_phi/(4*kl*l))+(tau_theta/(4*kl*l))+(tau_psi/(4*kd)));
    omega3 = checaRaiz((f_t/(4*kl))+(tau_phi/(4*kl*l))+(tau_theta/(4*kl*l))-(tau_psi/(4*kd)));
    omega4 = checaRaiz((f_t/(4*kl))+(tau_phi/(4*kl*l))-(tau_theta/(4*kl*l))+(tau_psi/(4*kd)));
}

float Mixer::motorControl(float x)
{
    return (a2*(x*x))+(a1*x);
}