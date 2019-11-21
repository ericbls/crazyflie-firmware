#include "mbed.h"
#include "horizontal_estimator.h"

// Class constructor
HorizontalEstimator::HorizontalEstimator() : flow(E_MOSI,E_MISO,E_SCK,E_CS1)
{
    u = 0;
    v = 0;
    x = 0;
    y = 0;
}

// Initialize Class
void HorizontalEstimator::init()
{
    flow.init();
}

// Predict horizontal position and velocity from model
void HorizontalEstimator::predict()
{
    x = x + u * dt;
   // u = u;
    y = y + v * dt;
   // v = v;
}

// Correct horizontal position and velocity with measurement
void HorizontalEstimator::correct(float z, float phi, float theta, float p, float q)
{
    flow.read();
    float div = cos(phi)*cos(theta);
    if (div > 0.5)
    {
        float d = z/div;
        //v_hx = d*sigma*flow.px;
        //v_hy = d*sigma*flow.py;
        float u_m = d*(sigma*flow.px+q);
        float v_m = d*(sigma*flow.py-p);
        u = u + alpha_hor*(u_m-u);
        v = v + alpha_hor*(v_m-v);
    }
}