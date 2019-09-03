#include "mbed.h"
#include "crazyflie.h"

Mixer mix;

int main()
{
    mix.arm();
    mix.actuate(0.7*m*g,0,0,0);
    wait(5);
    mix.disarm();
    while(1)
    {}
    return 0;
}