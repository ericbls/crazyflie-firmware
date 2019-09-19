// Lab de teste e configuracao do estimador de atitude do Drone

#include "mbed.h"
#include "crazyflie.h"
#include "USBSerial.h"

//Define serial object
USBSerial serial;

//Define serial command variable
char command;

//Define attitude estimator object
AttitudeEstimador estimador;

//Define Ticker object
Ticker tic;

//Define interrupt flag
bool flag;

//Define callback functions
void callback()
{
    flag=true;
}

//Main program
int main()
{
    //esperando alguns segundos para inicializar
    wait(2);

    //Inicia o objeto do estimador
    estimador.init();

    //Inicia o objeto de interrupcao
    tic.attach(&callback, dt);

    while(true)
    {  
        //Estimate attitude
        if(flag)
        {
            flag=false;
            estimador.estimate();
        }

        //Print attitude
        if (serial.readable())
        {
            command=serial.getc();
            if(command=='p')
            {
                serial.printf("%f , %f , %f\n", estimador.phi,estimador.theta,estimador.psi);
            }
        }
    }


    return 0;
}