#include "mbed.h"
#include "vertical_controller.h"

// Class constructor
VerticalController::VerticalController()
{
    ft = 0.0;
    //float z_e_last = 0;
}

//Control thrust force (n) given vertical position (m) and velocity (m/s)
void VerticalController::control(float z_r, float z, float w)
{
    float dd_zr = VerticalController::control_state_regulator(z_r, z, w, kp_z, kd_z);
    ft = m*(g+dd_zr);
}

// Control aceleration given reference position(m) and current position (m) and velocity (m/s)
// with given gains
float VerticalController::control_state_regulator(float pos_r, float pos, float vel, float kp, float kd)
{

    float dd_zr = kp*(pos_r-pos)+kd*(0.0-vel);
    return dd_zr;
}