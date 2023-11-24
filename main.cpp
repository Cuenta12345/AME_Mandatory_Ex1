#include "mbed.h"
#include "Thermostat.h"
#include "ThisThread.h"
#include <cstdio>
#include <string>


// main() runs in its own thread in the OS
Thermostat thermostat(A0, A1, D4, D14, D15);

int main()
{

    while (true) 
    {
        thermostat.showTemperature();
        ThisThread::sleep_for(500ms);
    }
}
