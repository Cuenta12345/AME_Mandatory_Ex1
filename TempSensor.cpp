#include "TempSensor.h"
#include "mbed.h"

TempSensor::TempSensor(PinName temp_sensor, PinName pot_pin) : _pin(temp_sensor), _potSensor(pot_pin) {
}

float TempSensor::readTemperature() {
    float thermR = NULL;
    float rawTemp = NULL;
    float tempK = NULL;

    rawTemp = _pin.read_u16();
    thermR = R * ((ADCRES / rawTemp) - 1);
    tempK = 1 / (log(thermR / R) / BETA + 1.0 / T0);

    return (tempK - K);
}

float TempSensor::readDesireTemperature(){
    return _potSensor.read_u16();
}



