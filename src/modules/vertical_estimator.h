#ifndef VerticalEstimator_h
#define VerticalEstimator_h

#include "mbed.h"
#include "parameters.h"
#include "pin_names.h"
#include "vl53l0x.h"

class VerticalEstimator{
    public:

    VerticalEstimator(); //class constructor

    void init(); // initializing class

    void predict(); // predict vertical position and velocity from model

    void correct(float phi, float theta); //correct vertical position and velocity with measurement

    float z, w; // vertical position (m) and velocity (m/s) estimation

    private:

    VL53L0X range; // range sensor object

    float z_m_last; // last vertical position measured
};

#endif