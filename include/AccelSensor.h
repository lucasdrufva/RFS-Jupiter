#pragma once
#include "sensor.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

class AccelSensor: public Sensor {
public:
    AccelSensor() : accel(12345) {};
    bool begin();
    AccelSensor* readData();
    String toStringCSV();
    String getCSVLabels();
private:
    Adafruit_ADXL345_Unified accel;
    float x;
    float y;
    float z;
};