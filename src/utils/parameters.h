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
const float OS = 0.01;
const float TS = 0.25;
const float zeta = abs(log(OS))/sqrt(pow(log(OS),2)+pow(pi,2));
const float wn = 4/(zeta*TS);
const float kp_phi = pow(wn,2);   
const float kd_phi = 2*zeta*wn;   
const float kp_theta = kp_phi; 
const float kd_theta = kd_phi;
const float kp_psi = 1.0;
const float kd_psi = 0.1;

// Constantes de controle vertical
const float kp_z = 5.86;
const float kd_z = 3.42;
const float L_obs = 20;
const float L_obs2 = 16;
const float rho1 = (L_obs*dt_range)/(1+L_obs*dt_range);
const float rho2 = (L_obs2*dt_range)/(1+L_obs2*dt_range);

// Constantes de controle horizontal
const float OS_h = 0.05;
const float TS_h = 4.0;
const float zeta_h = abs(log(OS_h))/sqrt(pow(log(OS_h),2)+pow(pi,2));
const float wn_h = 4.0/(zeta_h*TS_h);
const float kp_h = pow(wn_h,2);   
const float kd_h = 2.0*zeta_h*wn_h;
const float alpha_hor = 0.4;

//sensor parameters
const float w_h = 420.0;
const float gamma = 42.0;
const float sigma = (2.0*tan(gamma/2.0))/(w_h*dt);

// Filtros
const float alpha = 0.001;             //Constante para filtro passa baixa do estimador de altitude

#endif