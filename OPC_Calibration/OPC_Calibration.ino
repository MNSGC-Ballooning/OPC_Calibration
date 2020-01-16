#include <OPCSensor.h>
#include <SD.h>
#include <Arduino.h>

//Constants//
#define LOG_RATE 1000 //This can be changed to adjust the rate at which the OPCs log

//Timer
unsigned long Counter = 0;

//On Board SD Chipselect
const int chipSelect = BUILTIN_SDCARD;

//Pin Definitions//
#define PMS_SERIAL Serial1

//Data Logging//                          
File file;
String Fname = "";
boolean SDcard = true;

//OPC's//
Plantower Plan(&PMS_SERIAL, LOG_RATE);
String data="";

void setup() {
  initSD();
  delay(1000);
  Serial.begin(9600);
  initOPCs();
  delay(1000);
  Serial.println("SETUP COMPLETE");
}

void loop() {
  Plan.readData();
  if (millis() - Counter >= LOG_RATE) {
    Counter = millis();
    data = Plan.logUpdate();
    Serial.println(data);
    openlog();
    file.println(data);
    closelog();
    } 
}
