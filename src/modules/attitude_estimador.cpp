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

    p_bias=0;
    q_bias=0;
    r_bias=0;
}

//Initialize class
void AttitudeEstimador::init()
{
    imu.init();
    for (int i=0; i<500; i++)
    {
        imu.read();
        p_bias+=imu.gx/500.0;
        q_bias+=imu.gy/500.0;
        r_bias+=imu.gz/500.0;
        wait(dt);
    }
}

//Estimate Euler angles (rad) and angular velocities (rad/s)
void AttitudeEstimador::estimate()
{
    imu.read();
    
    p=imu.gx-p_bias;
    q=imu.gy-q_bias;
    r=imu.gz-r_bias;

    /*
    float theta_a = atan2(imu.ax,-imu.ay);
    float theta_g = theta+(q*dt);

    float phi_a = atan2(-imu.ay,-imu.az);
    float phi_g = phi+(p*dt);

    theta=((1-alpha)*theta_g)+(alpha*theta_a);
    phi=((1-alpha)*phi_g)+(alpha*phi_a);
    psi=psi+r*dt;
    */

    float phi_a = atan2(-imu.ay,-imu.az);
    float theta_a = atan2( imu.ax , (sqrt(pow(imu.ay,2)+pow(imu.az,2))));
    
    float phi_g = phi+(p+sin(phi)*tan(theta)*q+cos(phi)*tan(theta)*r)*dt;
    float theta_g = theta+(cos(phi)*q-sin(phi)*r)*dt;    
    float psi_g = psi+(sin(phi)*(1/cos(theta))*q+cos(phi)*(1/cos(theta))*r)*dt;

    phi=(1-alpha)*phi_g+alpha*phi_a;
    theta=(1-alpha)*theta_g+alpha*theta_a;
    psi = psi_g;
}