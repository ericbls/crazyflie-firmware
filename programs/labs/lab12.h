# include "mbed.h"
# include "crazyflie.h"

// Ticker objects
Ticker tic, tic_range;

// Interrupt flag and counter variables
bool flag, flag_range;

// Callback functions
void callback()
{
    flag = true;
}
void callback_range ()
{
    flag_range = true;
}

// Crazyflie controller objects
Mixer mixer;
AttitudeEstimator att_est;
VerticalEstimator ver_est;
HorizontalEstimator hor_est;

int main(){

    float z_r = 0.3f;
    float phi_r = 0.0f;
    float theta_r = 0.0f;
    float psi_r = 0.0f;
    float v_h=0.0;

    // Initialize estimators objects
    att_est.init();
    ver_est.init();
    hor_est.init();

    // Initialize interrupts
    tic.attach(&callback,dt);
    tic_range.attach(&callback_range,dt_range);

    // Arm motors and run controller while stable
    mixer.arm();

    int timer = 0;

     while(abs(att_est.phi)<=pi/4.0f && abs(att_est.theta) <= pi/4.0f && abs(att_est.p) <= 4.0f*pi && abs(att_est.q) <= 4.0f*pi && abs(att_est.r) <= 4.0f*pi && timer<=3000000)
    {
        if ( flag )
        {
            flag = false ;
            att_est.estimate();
            ver_est.predict() ;
            if (flag_range)
            {
                flag_range = false ;
                ver_est.correct( att_est.phi , att_est.theta);
            }
            hor_cont.control();
            ver_cont.control(z_r, ver_est.z, ver_est.w);
            att_cont.control(phi_r, theta_r, psi_r, att_est.phi, att_est.theta, att_est.psi, att_est.p, att_est.q, att_est.r);
            mixer.actuate(ver_cont.ft/(cos(att_est.phi)*cos(att_est.theta)),att_cont.tau_phi,att_cont.tau_theta,att_cont.tau_psi);
        }
        timer+=1;
    }

    // Disarm motors and end program
    mixer.disarm () ;
    while(true);
}