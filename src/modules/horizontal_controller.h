#ifndef vertical_controller_h
#define vertical_controller_h

#include "mbed.h"
#include "src/utils/parameters.h"

// Horizontal controller class
class HorizontalController
{
    public:

    // Class constructor
    HorizontalController();

    // Control total thrust force (N) fiven reference vertical position (m)
    // and current vertical position (m) and velocity (m/s)
    void control(float x_r, float y_r, float x, float y, float u, float v);
    
    // Total thrust force
    float ;

    private:

    // Control aceleration given reference ppsition (m) and current position (m)
    // and velocity (m/s) with given controller gains
    float control_state_regulator(float pos_r, float pos, float vel, float kp, float kd);

};

#endif