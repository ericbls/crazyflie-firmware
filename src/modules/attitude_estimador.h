#ifndef atitude_estimador_h
#define atitude_estimador_h

#include "mbed.h"
#include "src/utils/pin_names.h"
#include "src/utils/parameters.h"
#include "src/drivers/mpu9250.h"

// Attitude estimador class
class AttitudeEstimador
{
    public:
    //Class constructor
    AttitudeEstimador();
    //Initialize class
    void init();
    //Estimate Euler angles (rad) and angular velocities (rad/s)
    void estimate();
    //Euler angles
    float phi, theta, psi;
    //Angular velocities (rad/s)
    float p, q, r;

    private:
    //IMU sensor object
    MPU9250 imu;
    float p_bias, q_bias, r_bias;
};

#endif