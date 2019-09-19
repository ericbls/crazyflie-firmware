#ifndef parameters_h
#define parameters_h

// Physical constants
const float pi = 3.1416f;
const float g = 9.81f;              // m/s^2
const float dt = 0.002;

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

// Filtros
const float alpha = 0.001;             //Constante para filtro passa baixa do estimador de altitude

#endif