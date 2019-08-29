#include "mbed.h"
#include "crazyflie.h"

class Mixer
{
    private:
        float omega1;
        float omega2;
        float omega3;
        float omega4;

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
    {
        void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi)
        {
            mixer(f_t, tau_phi, tau_theta, tau_psi);
            motor1 = motorControl(omega1);
            motor2 = motorControl(omega2);
            motor3 = motorControl(omega3);
            motor4 = motorControl(omega4);
        }
    }

}