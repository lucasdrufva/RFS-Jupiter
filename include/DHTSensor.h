#pragma once
#include "sensor.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>


class DHTSensor: public Sensor {
public:
    DHTSensor() : dht(6, DHT11) {};
    bool begin();
    DHTSensor* readData();
    String toStringCSV();
    String getCSVLabels();
private:
    DHT dht;
    float humidity;
    float temperature;
    unsigned long lastReadingMillis;
};