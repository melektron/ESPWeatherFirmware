/**
 * @file sensor.hpp
 * @author Nilusink
 * @brief driver for the DHT22
 * @version 1.0
 * @date 2023-02-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <DHT.h>

#define DHT_PIN D3
#define DHT_TYPE DHT22


namespace Sensor
{
    // DHT sensor(DHT_PIN, DHT_TYPE);
    extern DHT sensor;

    struct w_data_t {
        double temperature_index;
        double temperature;
        double humidity;
    };


    /**
     * @brief initialize the sensor
     * 
     */
    void setup();

    /**
     * @brief get current weather data
     * 
     * @return w_data_t - temperature, humidity
     */
    w_data_t read_data();
}
