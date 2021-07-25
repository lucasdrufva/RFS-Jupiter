#include "AccelSensor.h"

bool AccelSensor::begin() {
    if(!accel.begin()){
        Serial.println("Could not find accelerometer");
        return false;
    }
    return true;
}

AccelSensor * AccelSensor::readData() {
    sensors_event_t accelEvent;
    accel.getEvent( & accelEvent);

    x = accelEvent.acceleration.x;
    y = accelEvent.acceleration.y;
    z = accelEvent.acceleration.z;

    return this;
}

String AccelSensor::toStringCSV() {
    String dataString = "";
    dataString += x;
    dataString += ",";
    dataString += y;
    dataString += ",";
    dataString += z;
    return dataString;
}

String AccelSensor::getCSVLabels(){
    return "X,Y,Z";
}