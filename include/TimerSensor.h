#pragma once
#include "sensor.h"


class TimerSensor: public Sensor {
public:
    bool begin();
    TimerSensor* readData();
    String toStringCSV();
    String getCSVLabels();
private:
    unsigned long startTime;
    unsigned long currentTime;
};