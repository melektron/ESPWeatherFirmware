/**
 * @file main.cpp
 * @author Nilusink
 * @brief A little weather station based on a esp8266 microcontroller
 * @version 1.0
 * @date 2023-02-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <Arduino.h>
#include <DHT.h>

#include "wserver/wserver.hpp"
#include "sensor/sensor.hpp"
#include "RGBLED/rgbled.hpp"
#include "OLED/oled.hpp"


RGBLED::RGBLed led(R_PIN, G_PIN, B_PIN);


uint8_t u = 0;

void setup()
{
    Serial.begin(9600);

    OLED::setup();
    Web::setup();
    Sensor::setup();
}

void loop()
{
    Sensor::w_data_t w_data = Sensor::read_data();
    OLED::update_display(w_data);
    OLED::draw_graph(w_data);
    led.setTemperature(w_data);

    // update the server only every 5 minutes
    if (u==150)
    {
        Web::sendData(w_data);
        u = 0;
    }

    delay(2000);
    u++;
}
