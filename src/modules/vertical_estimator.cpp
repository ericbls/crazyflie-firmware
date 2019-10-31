#include "mbed.h"
#include "vertical_estimator.h"

// Class constructor
VerticalEstimator::VerticalEstimator() : range(E_SDA,E_SCL)
{
    float z = 0;
    float w = 0;
    float z_m_last = 0;
    float z_last = 0;
}

// Initialize Class
void VerticalEstimator::init()
{
    range.init();
}

// Predict vertical position and velocity from model
void VerticalEstimator::predict()
{
    z=z_last + w*dt_range;
    w=w_last; 
}

// Correct vertical position and velocity with measurement
void VerticalEstimator::correct(float phi, float theta)
{
    range.read();
    float z_m=range.d*cos(phi)*cos(theta);
    float w_m=(z_m-z_m_last)/dt_range;
    z_m_last = z_m;
    z=z+rho2*(z_m - z);
    z_last = z;
    w=w + rho1*(w_m -w);
    w_last = w;
}