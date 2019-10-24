// Lab de controlador de atitude do Drone

#include "mbed.h"
#include "crazyflie.h"

// Crazyflie constroller objects
Mixer mixer;
AttitudeEstimador att_est;
AttitudeController att_cont;

// Ticker objects
Ticker tic;

// Interrupt flag and counter variables
bool flag;

// Callback functions
void callback()
{
    flag=true;
}

// Main program
int main()
{
    // Set references
    float f_t=0.2*m*g;
    float phi_r=0.0f;
    float theta_r=0.0f;
    float psi_r=0.0f;

    //Initialize estimators objects
    att_est.init();
    tic.attach(&callback,dt);

    //Arm motors and run controller while stable
    mixer.arm();
    while(abs(att_est.phi)<=pi/4.0f && abs(att_est.theta)<=pi/4.0f && abs(att_est.p)<=4.0f*pi && abs(att_est.q)<=4.0f*pi && abs(att_est.r)<=4.0f*pi)
    {
        if (flag)
        {
            flag = false;
            att_est.estimate();
            att_cont.control(phi_r,theta_r,psi_r,att_est.phi,att_est.theta,att_est.psi,att_est.p,att_est.q,att_est.r);
            mixer.actuate(f_t,0.0f,att_cont.tau_theta,0.0f);
        }
    }
    // Disarm motors and end program
    mixer.disarm();
    while(1);
}