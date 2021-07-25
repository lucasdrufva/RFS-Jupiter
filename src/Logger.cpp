#include "logger.h"

Logger::Logger(bool debugEnabled) {
    this->debugEnabled = debugEnabled;
}

bool Logger::begin() {
    Serial.begin(9600);

    if (debugEnabled) {
        while (!Serial);
    }

    Serial.println("Hi! if you see this, the serial port should work");

    while (!SD.begin(SDCARD_SS_PIN)) {
        Serial.println("Could not find sd card");
        return false;
    }

    SD.remove("Lund3.csv");
    file = SD.open("Lund3.csv", FILE_WRITE);
    if (!file) {
        Serial.println("Could not open file");
        return false;
    }

    file.println(generateLabels());

    startTime = millis();

    return true;
}

void Logger::log(String data) {
    file.println(data);
    file.flush();
    Serial.println(data);
}

void Logger::registerSensor(Sensor* sensor){
    sensors.push_back(sensor);
}

void Logger::logSensors(){
    String dataString = "";
    dataString += millis() - startTime;
    dataString += ",";
     for(std::vector<Sensor*>::iterator sensor = sensors.begin(); sensor != sensors.end(); ++sensor) {
        dataString += (*sensor)->readData()->toStringCSV();
        Serial.println((*sensor)->readData()->toStringCSV());
        if(sensor+1 != sensors.end()){
            dataString += ",";
        }
    }
    Serial.println(dataString);
    file.println(dataString);
    file.flush();
}

String Logger::generateLabels(){
    String labelString = "#Millis,";
    for(std::vector<Sensor*>::iterator sensor = sensors.begin(); sensor != sensors.end(); ++sensor) {
        labelString += (*sensor)->getCSVLabels();
        if(sensor+1 != sensors.end()){
            labelString += ",";
        }
    }
    return labelString;
}