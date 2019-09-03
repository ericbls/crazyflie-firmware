#ifndef mixer_h
#define mixer_h

#include "mbed.h"
#include "src/utils/pin_names.h"
#include "src/utils/parameters.h"

class Mixer
{
    public:
        Mixer();
        void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi);
        void arm();
        void disarm();
    private:
        PwmOut motor1, motor2, motor3, motor4;
        DigitalOut led1, led2;
        float omega1, omega2, omega3, omega4;
        void getMixer(float f_t, float tau_phi, float tau_theta, float tau_psi);
        float motorControl(float x);
        float checaRaiz(float x);
        bool armed;
};

#endif