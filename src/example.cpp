/*!
 * @file  example2-with-handler.cpp
 * @brief  Using Solid Sensors (SS) with Hander class to routinely fetch and display sensor values.
 * @details  This example a Handler instance to manage the sleep and read cycles of the sensors for periodic sensor values.
 * @n  The use of the Handler makes it easy to manage different sleep and read cycles for each sensor.
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
#include "MPSSoilTemperatureSensor.h"
#include "MPSSoilHumiditySensor.h"
#include "MPSSoilPhSensor.h"
#include "MPSSoilEcSensor.h"
#include "MPSSoilNitrogenSensor.h"
#include "MPSSoilPotassiumSensor.h"
#include "MPSSoilPhosphorousSensor.h"
#include "Sht20AmbientHumiditySensor.h"
#include "Sht20AmbientTemperatureSensor.h"

using namespace std;

SensorHandler SHandler;

DistanceSensor metaDistanceSensor;
RainSensor metaRainSensor;
DHTAmbientHumiditySensor metaAmbientHumidityDHTSensor;
DHTAmbientTemperatureSensor ambientTemperatureDHTSensor;
MPSSoilTemperatureSensor metaMPSTemperatureSensor;
MPSSoilHumiditySensor metaMPSHumiditySensor;
MPSSoilEcSensor metaMPSEcSensor;
MPSSoilPhSensor metaMPSPhSensor;
MPSSoilNitrogenSensor metaMPSNitroSensor;
MPSSoilPotassiumSensor metaMPSPotaSensor;
MPSSoilPhosphorousSensor metaMPSPhosphoSensor;
// Sht20AmbientHumiditySensor ambientHumiditySht20Sensor;
// Sht20AmbientTemperatureSensor ambientTemperatureSht20Sensor;

void setup() {
  Serial.begin(115200);
}

void loop() {
  SHandler.routine(metaDistanceSensor, "Distance");
  SHandler.routine(metaRainSensor, "Rain");
  SHandler.routine(metaAmbientHumidityDHTSensor, "Humidity");
  SHandler.routine(ambientTemperatureDHTSensor, "Temperature");
  SHandler.routine(metaMPSTemperatureSensor, "MPSTemperature");
  SHandler.routine(metaMPSHumiditySensor, "MPSHumidity");
  SHandler.routine(metaMPSPhSensor, "MPSPh");
  SHandler.routine(metaMPSEcSensor, "MPSEc");
  SHandler.routine(metaMPSNitroSensor, "MPSNitro");
  SHandler.routine(metaMPSPhosphoSensor, "MPSPhospho");
  SHandler.routine(metaMPSPotaSensor, "MPSPota");
  // SHandler.routine(ambientHumiditySht20Sensor, "HumiditySht20");
  // SHandler.routine(ambientTemperatureSht20Sensor, "TemperatureSht20");
  
  Serial.print("*"); // Just for feedback
  delay(500);
}