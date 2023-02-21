#include "sensor.hpp"


DHT Sensor::sensor(DHT_PIN, DHT_TYPE);


void Sensor::setup()
{
    sensor.begin();
}


Sensor::w_data_t Sensor::read_data()
{
    double temperature = sensor.readTemperature(false);
    double humidity = sensor.readHumidity();
    double temperature_index = sensor.computeHeatIndex(temperature, humidity, false);

    return {
        .temperature_index = temperature_index,
        .temperature       = temperature,
        .humidity          = humidity
    };
}
