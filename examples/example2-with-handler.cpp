/*!
 * @file  example2-with-handler.cpp
 * @brief  Using Solid Sensors (SS) with Hander class to routinely fetch and display sensor values.
 * @details  This example uses instances of SS objects to fetch and display sensor values.
 * @n  Library dependencies for each SS class must first be added to the PlatformIO project.
 * @n  SS classes needed must be included at the top of the .cpp file.
 * @n  Each SS class must then be instantiated, and the fetch method on the instance can be used to get the sensor value.
 * @copyright  Copyright (c) 2022 Kumamoto University (https://www.kumamoto-u.ac.jp/)
 * @license  The MIT License (MIT)
 * @version  V1.0
 * @date  2022-10-01
 * @url  https://github.com/DFRobot/DFRobot_SHT20
 */

#include "Arduino.h"

#include "SensorHandler.h"
#include "DistanceSensor.h"
#include "RainSensor.h"
#include "DHTAmbientHumiditySensor.h"
#include "DHTAmbientTemperatureSensor.h"
#include "Sht20AmbientHumiditySensor.h"
#include "Sht20AmbientTemperatureSensor.h"
// #include "MPSSoilTemperatureSensor.h"
// #include "MPSSoilHumiditySensor.h"
// #include "MPSSoilPhSensor.h"
// #include "MPSSoilEcSensor.h"
// #include "MPSSoilNitrogenSensor.h"
// #include "MPSSoilPotassiumSensor.h"
// #include "MPSSoilPhosphorousSensor.h"

using namespace std;

SensorHandler SHandler;

DistanceSensor metaDistanceSensor;
RainSensor metaRainSensor;
DHTAmbientHumiditySensor metaAmbientHumidityDHTSensor;
DHTAmbientTemperatureSensor ambientTemperatureDHTSensor;
Sht20AmbientHumiditySensor ambientHumiditySht20Sensor;
Sht20AmbientTemperatureSensor ambientTemperatureSht20Sensor;
// MPSSoilTemperatureSensor metaMPSTemperatureSensor;
// MPSSoilHumiditySensor metaMPSHumiditySensor;
// MPSSoilEcSensor metaMPSEcSensor;
// MPSSoilPhSensor metaMPSPhSensor;
// MPSSoilNitrogenSensor metaMPSNitroSensor;
// MPSSoilPotassiumSensor metaMPSPotaSensor;
// MPSSoilPhosphorousSensor metaMPSPhosphoSensor;

void setup() {
  Serial.begin(115200);
}

void loop() {
  SHandler.routine(metaDistanceSensor, "Distance");
  SHandler.routine(metaRainSensor, "Rain");
  SHandler.routine(metaAmbientHumidityDHTSensor, "Humidity");
  SHandler.routine(ambientTemperatureDHTSensor, "Temperature");
  SHandler.routine(ambientHumiditySht20Sensor, "HumiditySht20");
  SHandler.routine(ambientTemperatureSht20Sensor, "TemperatureSht20");
  // SHandler.routine(metaMPSTemperatureSensor, "MPSTemperature");
  // SHandler.routine(metaMPSHumiditySensor, "MPSHumidity");
  // SHandler.routine(metaMPSPhSensor, "MPSPh");
  // SHandler.routine(metaMPSEcSensor, "MPSEc");
  // SHandler.routine(metaMPSNitroSensor, "MPSNitro");
  // SHandler.routine(metaMPSPhosphoSensor, "MPSPhospho");
  // SHandler.routine(metaMPSPotaSensor, "MPSPota");
  
  delay(500);
}