# include "mbed.h"
# include "crazyflie.h"
# include "USBSerial.h"

// USB serial object
USBSerial serial;

// Crazyflie controller objects
AttitudeEstimator att_est;
VerticalEstimator ver_est;
HorizontalEstimator hor_est;

// Define ticker
Ticker tic;
Ticker tic_range;

// Define interrupt flags
bool flag;
bool flag_range = false;

// Define callback functions
void callback()
{
    flag = true;
}
    void callback_range()
{
    flag_range = true;
}

// Main program
int main()
{
    // Initialize estimator objects
    att_est.init();
    ver_est.init();
    hor_est.init();
    // Initialize interrupts
    tic.attach(&callback, dt);
    tic_range.attach(&callback_range, dt_range);
    while (true)
    {
        if (flag)
        {
            flag = false;
            att_est.estimate();
            ver_est.predict();
            if (flag_range)
            {
                flag_range = false;
                ver_est.correct(att_est.phi,att_est.theta);
                serial.printf("Flow v_x: %6.2f; v_y: %6.2f \n",hor_est.v_hx,hor_est.v_hy);
                //serial.printf("valor de D: %6.2f \n", ver_est.z);
                //serial.printf("valor de PHI: %6.2f valor de THETA: %6.2F \n", att_est.phi, att_est.theta);
            }
            hor_est.correct(ver_est.z, att_est.phi, att_est.theta);
        }
    }
}