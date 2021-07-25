#include "DHTSensor.h"

bool DHTSensor::begin(){
    dht.begin();
    return true;
}

DHTSensor* DHTSensor::readData(){
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
    Serial.print("Temp: ");
    Serial.println(temperature);
    
    return this;
}

String DHTSensor::toStringCSV(){
    String dataString = "";
    dataString += temperature;
    dataString += ",";
    dataString += humidity;
    return dataString;
}

String DHTSensor::getCSVLabels(){
    return "Temperature,Humidity";
}