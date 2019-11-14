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
AttitudeController att_cont;
HorizontalController hor_cont;
VerticalController ver_cont;

Timer tim;

int main(){

    float x_r = 0.0f;
    float y_r = 0.0f;
    float z_r = 0.3f;
    float psi_r = 0.0f;

    // Initialize estimators objects
    att_est.init();
    ver_est.init();
    hor_est.init();

    // Initialize interrupts
    tic.attach(&callback,dt);
    tic_range.attach(&callback_range,dt_range);

    // Arm motors and run controller while stable
    mixer.arm();

    tim.start();
    float timer = 0;

     while(abs(att_est.phi)<=pi/4.0f && abs(att_est.theta) <= pi/4.0f && abs(att_est.p) <= 4.0f*pi && abs(att_est.q) <= 4.0f*pi && abs(att_est.r) <= 4.0f*pi && timer<=3.0)
    {
        if (flag)
        {
            flag = false ;
            att_est.estimate();
            ver_est.predict();
            if (flag_range)
            {
                flag_range = false ;
                ver_est.correct( att_est.phi , att_est.theta);
            }
            hor_est.correct(ver_est.z, att_est.phi, att_est.theta, att_est.p, att_est.q);
            hor_cont.control(x_r,y_r,hor_est.x,hor_est.y,hor_est.u,hor_est.v);
            ver_cont.control(z_r, ver_est.z, ver_est.w);
            att_cont.control(hor_cont.phi_r, hor_cont.theta_r, psi_r, att_est.phi, att_est.theta, att_est.psi, att_est.p, att_est.q, att_est.r);
            mixer.actuate(ver_cont.ft/(cos(att_est.phi)*cos(att_est.theta)),att_cont.tau_phi,att_cont.tau_theta,att_cont.tau_psi);
        }
        timer=tim.read();
    }

    // Disarm motors and end program
    mixer.disarm () ;
    while(true);
}