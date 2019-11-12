#ifndef HorizontalEstimator_h
#define HorizontalEstimator_h

#include "mbed.h"
#include "crazyflie.h"
#include "USBSerial.h"

// Horizontal estimator class
class HorizontalEstimator{
    
    public:

    HorizontalEstimator(); //class constructor

    void init(); // initializing class

    void predict(); // predict horizontal velocity and velocity from model

    void correct(float z, float phi, float theta, float p, float q); //correct horizontal position and velocity with measurement

    float u, v, x, y; // horizontal position (m) and velocity (m/s) estimation

    private:

    PMW3901 flow; // range sensor object

    float d; // last horizontal position measured
};

#endif