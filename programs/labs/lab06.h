#include "mbed.h"
#include "crazyflie.h"

Mixer mix;

int main()
{
    mix.arm();
    mix.actuate(0.4*m*g,0,0,0);
    wait(4);
    mix.disarm();
    while(1)
    {}
    return 0;
}