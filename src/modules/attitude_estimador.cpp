#include "mbed.h"
#include "attitude_estimador.h"

//Class constructor
AttitudeEstimador::AttitudeEstimador():imu(IMU_SDA, IMU_SCL)
{
    phi=0;
    theta=0;
    psi=0;

    p=0;
    q=0;
    r=0;
}

//Initialize class
void AttitudeEstimador::init()
{
    imu.init();
}

//Estimate Euler angles (rad) and angular velocities (rad/s)
void AttitudeEstimador::estimate()
{
    imu.read();
    float phi_a = imu.ay/imu.az;
    phi=phi_a;

}