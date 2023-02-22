/**
 * @file rgbled.hpp
 * @author Nilusink
 * @brief driver for the RGB Led
 * @version 1.0
 * @date 2023-02-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <Arduino.h>
#include "sensor/sensor.hpp"


#define R_PIN D6
#define G_PIN D7
#define B_PIN D8


#define DHT_MIN -20
#define DHT_MAX 35


namespace RGBLED
{
    /**
     * @brief base color type
     * 
     */
    struct color_t {
        double r;
        double g;
        double b;

        /**
         * @brief convert from temperature
         * 
         * @param temperature temperature value
         * @param value_center temperature center (green)
         */
        color_t(double temperature, double value_center = 20);

        /**
         * @brief check if all values are below 255
         * 
         * @return true - all below 255
         * @return false - at least one above 255
         */
        bool check_max();
    };

    /**
     * @brief driver for the LED
     * 
     */
    class RGBLed
    {
    private:
        uint8_t r_pin;
        uint8_t g_pin;
        uint8_t b_pin;

    public:
        /**
         * @brief Construct a new RGBLed object
         * 
         * @param red_pin pin for the RED led
         * @param green_pin pin for the GREEN led
         * @param blue_pin pin for the BLUE led
         */
        RGBLed(uint8_t red_pin, uint8_t green_pin, uint8_t blue_pin);

        /**
         * @brief change the current color
         * 
         * @param color color value
         */
        void setColor(color_t color);

        /**
         * @brief change the color based on the temperature
         * 
         * @param d weather data object
         */
        void setTemperature(Sensor::w_data_t d);
    };
}
