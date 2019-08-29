#include "mbed.h"
#include "crazyflie.h"

// Define motors as PWM output object

class Mixer
{
    private:
        PwmOut motor1;
        PwmOut motor2;
        PwmOut motor3;
        PwmOut motor4;
        DigitalOut led1;
        DigitalOut led2;

        float omega1;
        float omega2;
        float omega3;
        float omega4;

        bool armed;

        float checarRaiz(float x)
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

        float motorControl(float x)
        {
            return (a2*(x*x))+(a1*x);
        }
        
        void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi)
        {
            omega1 = checarRaiz((f_t/(4*kl))-(tau_phi/(4*kl*l))-(tau_theta/(4*kl*l))-(tau_psi/(4*kd)));
            omega2 = checarRaiz((f_t/(4*kl))-(tau_phi/(4*kl*l))+(tau_theta/(4*kl*l))+(tau_psi/(4*kd)));
            omega3 = checarRaiz((f_t/(4*kl))+(tau_phi/(4*kl*l))+(tau_theta/(4*kl*l))-(tau_psi/(4*kd)));
            omega4 = checarRaiz((f_t/(4*kl))+(tau_phi/(4*kl*l))-(tau_theta/(4*kl*l))+(tau_psi/(4*kd)));
        }

    public:
        Mixer() : motor1(MOTOR1), motor2(MOTOR2), motor3(MOTOR3), motor4(MOTOR4), led1(LED_RED_R), led2(LED_GREEN_L)
        {}

        void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi)
        {
            if(armed)
            {
                mixer(f_t, tau_phi, tau_theta, tau_psi);
                motor1 = motorControl(omega1);
                motor2 = motorControl(omega2);
                motor3 = motorControl(omega3);
                motor4 = motorControl(omega4);
            }
        }
        
        void arm()
        {
            armed=true;
            led1=true;
            led2=false;
        }

        void disarm()
        {
            armed=false;
            led1=false;
            led2=true;
            motor1=0.0;
            motor2=0.0;
            motor3=0.0;
            motor4=0.0;
        }

};

Mixer mixer;

int main()
{
    mixer.arm();
    mixer.actuate(0,0.005,0,0);
    wait(5.0);
    mixer.disarm();
    return 0;
}