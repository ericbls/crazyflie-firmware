#include "mbed.h"
#include "horizontal_estimator.h"

// Class constructor
HorizontalEstimator::HorizontalEstimator() : flow(E_MOSI,E_MISO,E_SCK,E_CS1)
{
    v_hx = 0;
    v_hy = 0;
}

// Initialize Class
void HorizontalEstimator::init()
{
    flow.init();
}

// Predict horizontal position and velocity from model
void HorizontalEstimator::predict()
{
    
}

// Correct horizontal position and velocity with measurement
void HorizontalEstimator::correct(float z, float phi, float theta)
{
    flow.read();
    float d = z/(cos(phi)*cos(theta));
    v_hx = d*sigma*flow.px;
    v_hy = d*sigma*flow.py;
    //v_hx = d*(sigma*flow.px);
    //v_hy = d*(sigma*flow.py);

}