#include "mbed.h"
#include "crazyflie.h"

class Mixer
{
    private:
        float sqr_omega1;
        float sqr_omega2;
        float sqr_omega3;
        float sqr_omega4;

        int checarRaiz(float x)
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

    public:
    {
        void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi)
        {
            mixer(f_t, tau_phi, tau_theta, tau_psi);
            motor1 = motorControl(omega_r_1);
            motor2 = motorControl(omega_r_2);
            motor3 = motorControl(omega_r_3);
            motor4 = motorControl(omega_r_4);
        }
    }

}