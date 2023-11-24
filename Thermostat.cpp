#include "Thermostat.h"
#include "mbed.h"
#include <exception>
#include <string>

Thermostat::Thermostat(PinName tempSensor_pin, PinName potSensor_pin, PinName led_pin, PinName i2c_sda, PinName i2c_slc) : _tempSensor(tempSensor_pin), _potSensor(potSensor_pin), _led(led_pin), _lcd(i2c_sda, i2c_slc),
thermR(0.0), rawTemp(0.0), tempK(0.0), currentTemperature(0.0), desireTemperature(0.0){
}

void Thermostat::showTemperature() {

    rawTemp = _tempSensor.read_u16();
    thermR = R * ((ADCRES / rawTemp) - 1);
    tempK = 1 / (log(thermR / R) / BETA + 1.0 / T0);

    currentTemperature = tempK - K;

    desireTemperature = _potSensor.read_u16();

    _lcd.clear();

    if (currentTemperature < desireTemperature-1)
    {
        _lcd.setRGB(0, 0, 255);
        _lcd.print("It's Cold");
        _lcd.locate(1, 1);

        while (currentTemperature < desireTemperature)
        {
            _led = !_led;
        }
    }else if (currentTemperature > desireTemperature+1)
    {
        _lcd.setRGB(255, 0, 0);
        _lcd.print("It's heat");
        _led = 1;
    }else{
        _led = 0;
        _lcd.setRGB(0, 255, 0);
        _lcd.print("Perfect");
    }
}


