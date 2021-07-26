#include <Arduino.h>

#include "logger.h"
#include "DHTSensor.h"
#include "AccelSensor.h"

#define STATUS_LED LED_BUILTIN

#define DEBUG_ENABLED false
Logger logger(DEBUG_ENABLED);
DHTSensor dht;
AccelSensor accel;

unsigned long previousLoopMillis = 0;
const long loopInterval = 50; 

void setup(){
  pinMode(STATUS_LED, OUTPUT);

  logger.registerSensor(&dht);
  logger.registerSensor(&accel);

  if(!(logger.begin()&&accel.begin()&&dht.begin())){
    Serial.println("I dont work");
    while(true);
  }

  digitalWrite(STATUS_LED, HIGH);
}

void loop(){
  // Log data every 50 ms
  unsigned long currentMillis = millis();
  if (currentMillis - previousLoopMillis >= loopInterval) {
    Serial.println("Log data!");
    previousLoopMillis = currentMillis;
    logger.logSensors();
  }
}