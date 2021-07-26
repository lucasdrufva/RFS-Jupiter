#include "DHTSensor.h"

bool DHTSensor::begin(){
    lastReadingMillis = millis();
    dht.begin();
    delay(30);
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
    if(temperature == NAN||int(temperature)==0){
        Serial.println("DHT not working");
        return false;
    }
    return true;
}

DHTSensor* DHTSensor::readData(){
    // Only poll data from the sensor every 2000 ms
    if(millis()-lastReadingMillis > 2000){
        temperature = dht.readTemperature();
        humidity = dht.readHumidity();
    }
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