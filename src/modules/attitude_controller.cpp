#include "mbed.h"
#include "attitude_controller.h"

// Class constructor
AttitudeController::AttitudeController()
{
    tau_phi=0.0;
    tau_psi=0.0;
    tau_theta=0.0;

}

// Control torques (N.m) given reference angles (rad) and current angles (rad) and angular velocities (rad/s)
void AttitudeController::control(float phi_r, float theta_r, float psi_r, float phi, float theta, float psi, float p, float q, float r)
{
    tau_phi=I_xx*control_state_regulator(phi_r, phi, p, kp_phi, kd_phi);
    tau_theta=I_yy*control_state_regulator(theta_r, theta, q, kp_theta, kd_theta);
    tau_psi=I_zz*control_state_regulator(psi_r, psi, r, kp_psi, kd_psi);
}

// Control torque (N.m) given reference angle (rad) and current angle (rad) and angular velocity (rad/s) with given controller gains
float AttitudeController::control_state_regulator(float angle_r, float angle, float rate, float kp, float kd)
{
    return kp*(angle_r-angle)+kd*(0.0-rate);
}