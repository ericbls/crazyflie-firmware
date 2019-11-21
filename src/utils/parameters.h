#ifndef parameters_h
#define parameters_h
#include <cmath>

// Physical constants
const float pi = 3.1416f;
const float g = 9.81f;              // m/s^2
const float dt = 0.002;
const float dt_range = 0.050;

// Quadcopter dimensions
const float m = 30e-3f;             // kg
const float I_xx = 16.0e-6f;        // kg.m^2
const float I_yy = 16.0e-6f;        // kg.m^2
const float I_zz = 29.0e-6f;        // kg.m^2
const float l = 33e-3f;             // m

// Constantes de Controle
const float a2 = 1.245e-7f;          //sˆ2
const float a1 = 4.032e-14f;         //s
const float kl = 1.648e-8f;          //N.sˆ2/radˆ2
const float kd = 1.047e-10f;         //N.m.sˆ2/radˆ2

// Constantes de controle atitude
const float OS = 0.05f;
const float TS = 0.2f;
const float zeta = abs(log(OS))/sqrt(pow(log(OS),2)+pow(pi,2)); // 
const float wn = 4.0/(zeta*TS);
const float kp_phi = pow(wn,2);   // 310
const float kd_phi = 2.0*zeta*wn;   // 20
const float kp_theta = kp_phi; 
const float kd_theta = kd_phi;

const float OS_yaw = 0.05f;
const float TS_yaw = 0.75f; //0.6f;
const float zeta_yaw = abs(log(OS_yaw))/sqrt(pow(log(OS_yaw),2)+pow(pi,2));
const float wn_yaw = 4.0/(zeta_yaw*TS_yaw);
const float kp_psi = pow(wn_yaw,2); // 93
const float kd_psi = 2.0*zeta_yaw*wn_yaw; // 13.33
const float alpha = 0.01f;             //Constante para filtro passa baixa do estimador de altitude


// Constantes de controle vertical
const float OS_v = 0.02f;
const float TS_v = 3.2f;
const float zeta_v = abs(log(OS_v))/sqrt(pow(log(OS_v),2)+pow(pi,2));
const float wn_v = 4.0/(zeta_v*TS_v);
const float kp_z = pow(wn_v,2); //5.4; // 5.86;
const float kd_z = 2.0*zeta_v*wn_v; //4.0; //3.42;
const float L_obs = 12.0;
const float L_obs2 = 12.0;
const float rho1 = 0.3f; //(L_obs*dt_range)/(1.0+L_obs*dt_range); // 0.5
const float rho2 = 0.3f; //(L_obs2*dt_range)/(1.0+L_obs2*dt_range); // 0.44

// Constantes de controle horizontal
const float OS_h = 0.05f;
const float TS_h = 4.0f;
const float zeta_h = abs(log(OS_h))/sqrt(pow(log(OS_h),2)+pow(pi,2));
const float wn_h = 4.0/(zeta_h*TS_h);
const float kp_h = pow(wn_h,2);     // 2.1
const float kd_h = 2.0*zeta_h*wn_h; // 2
const float alpha_hor = 0.40f;

//sensor parameters
const float w_h = 420.0f;
const float gamma = 0.7330f; //42.0*(pi/180.0));
const float sigma = (2.0*tan(gamma/2.0))/(w_h*dt);

#endif