#include "rgbled.hpp"
#include <cmath>


using namespace RGBLED;


color_t::color_t(double temperature, double value_center)
{
    // calculates a color based on temperature
    double green_val = (temperature > value_center) ? (255 - map(temperature, value_center, DHT_MAX, 0, 255)) : map(temperature, DHT_MIN, value_center, 0, 255);
    double red_val = (temperature < value_center) ? 0 : map(temperature, value_center, DHT_MAX, 0, 255);
    double blue_val = (temperature > value_center) ? 0 : (255 - map(temperature, DHT_MIN, value_center, 0, 255));

    double total_brightness = green_val + red_val + blue_val;

    // so the total brightness matches LED_MAX
    double brightness_multiplier = 255 / total_brightness;

    r = red_val * brightness_multiplier;
    g = green_val * brightness_multiplier;
    b = blue_val* brightness_multiplier;
}


bool color_t::check_max()
{
    return (r < 256 && g < 256 && b < 256);
}


RGBLed::RGBLed(uint8_t red_pin, uint8_t green_pin, uint8_t blue_pin)
    : r_pin(red_pin), g_pin(green_pin), b_pin(blue_pin)
{
    pinMode(r_pin, OUTPUT);
    pinMode(g_pin, OUTPUT);
    pinMode(b_pin, OUTPUT);
}


void RGBLed::setColor(color_t color)
{
    // check if the color is valid
    if (!color.check_max())
    {
        Serial.println(F("Invalid RGB color!"));
        return;
    }

    // write PWM values
    analogWrite(r_pin, color.r);
    analogWrite(g_pin, color.g);
    analogWrite(b_pin, color.b);
}


void RGBLed::setTemperature(Sensor::w_data_t d)
{
    // use the constructor to convert from temperature to color
    setColor(d.temperature);
}
