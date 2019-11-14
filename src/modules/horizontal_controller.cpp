#include "mbed.h"
#include "horizontal_controller.h"

// Class constructor
HorizontalController::HorizontalController()
{
    phi_r = 0.0;
    theta_r = 0.0;
}

//Control thrust force (n) given horizontal position (m) and velocity (m/s)
void HorizontalController::control(float x_r, float y_r, float x, float y, float u, float v)
{
    phi_r = (-1.0/g)*control_state_regulator(y_r,y,v,kp_h,kd_h);
    theta_r = (1.0/g)*control_state_regulator(x_r,x,u,kp_h,kd_h);
}

// Control aceleration given reference position(m) and current position (m) and velocity (m/s)
// with given gains
float HorizontalController::control_state_regulator(float pos_r, float pos, float vel, float kp, float kd)
{
    return kp*(pos_r-pos)+kd*(0.0-vel);
}