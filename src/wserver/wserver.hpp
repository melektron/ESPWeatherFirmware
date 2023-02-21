/**
 * @file wserver.hpp
 * @author Nilusink
 * @brief Connects to the API server and publishes the data (http://home.nilus.ink/redoc)
 * @version 1.0
 * @date 2023-02-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Arduino.h>
#include "sensor/sensor.hpp"


// DHT stuff
#define DHTPIN D3
#define DHTTYPE DHT22

#define STATION_ID 5
#define STATION_SECRET "\"2e870053cf539c3f8b2c3b8345acac30b93d8083e510303ddf56bec3ada9c13e30400e4658158955cc6c71609e2968fa3a7da28edbde8732b143222a29c07104\""


namespace Web
{
    // DHT dht(DHTPIN, DHTTYPE);
    extern const char* serverName;
    extern const char* ssid;
    extern const char* pwd;

    /**
     * @brief initialize the internet connection
     * 
     */
    void setup();

    /**
     * @brief send the weather data
     * 
     * @param d weather data
     */
    void sendData(Sensor::w_data_t d);
}
