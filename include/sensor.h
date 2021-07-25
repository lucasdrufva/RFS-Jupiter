#pragma once
#include <Arduino.h>

class Sensor{
public:
    virtual bool begin() = 0;
    virtual Sensor* readData() = 0;
    virtual String toStringCSV() = 0;
    virtual String getCSVLabels() = 0;
};