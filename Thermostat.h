#ifndef MBED_TEMPSENSOR_H
#define MBED_TEMPSENSOR_H
#include "mbed.h"
#include "Grove_LCD_RGB_Backlight.h"  // Reemplaza con el nombre real de tu archivo de encabezado para Grove_LCD_RGB_Backlight

#define ADCRES 65535.0
#define R 100000.0
#define BETA 4250
#define K 273.15
#define T0 298.15

class Thermostat {
public:
    Thermostat(PinName tempSensor_pin, PinName potSensor_pin, PinName led_pin, PinName i2c_sda, PinName i2c_slc);
    void showTemperature();

private:
    Grove_LCD_RGB_Backlight _lcd;
    DigitalInOut _led;
    AnalogIn _tempSensor;
    AnalogIn _potSensor;

    float thermR;
    float rawTemp;
    float tempK;

    float currentTemperature;
    float desireTemperature;


};

#endif