// Lab de teste e configuracao do estimador de atitude do Drone

#include "mbed.h"
#include "crazyflie.h"
#include "USBSerial.h"

USBSerial serial;

//Define attitude estimator object
AttitudeEstimador estimador;

//Main program
int main()
{
    //esperando alguns segundos para inicializar
    wait(2);

    //Inicia o objeto do estimador
    estimador.init();

    while(true)
    {
        estimador.init();
        estimador.estimate();

        serial.printf("valor obtido para phi é %f\n", estimador.phi);
        wait(0.2);
    }


    return 0;
}