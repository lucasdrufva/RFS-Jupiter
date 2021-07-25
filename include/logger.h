#pragma once
#include <Arduino.h>
#include <SD.h>
#include <SPI.h>
#include <sensor.h>
#include <initializer_list>
#include <vector>

class Logger {
public:
    Logger(bool debugEnabled);
    bool begin();
    void log(String data);
    void logSensor(std::initializer_list<Sensor>& sensors);
    void registerSensor(Sensor* sensor);
    void logSensors();
private:
    File file;
    unsigned long startTime;
    bool debugEnabled;
    std::vector<Sensor*> sensors;

    String generateLabels();
};