#include "TimerSensor.h"

bool TimerSensor::begin() {
    startTime = millis();
    currentTime = startTime;

    if(!millis()){
        Serial.println("Millis not working");
        return false;
    }
    return true;
}

TimerSensor * TimerSensor::readData() {
    currentTime = millis() - startTime;

    return this;
}

String TimerSensor::toStringCSV() {
    return String(currentTime);
}

String TimerSensor::getCSVLabels(){
    return "Millis";
}