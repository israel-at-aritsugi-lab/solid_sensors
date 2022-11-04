/*!
 * @file  example1-simple.cpp
 * @brief  Using Solid Sensors (SS) to fetch and display sensor values
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
#include "MPSSoilTemperatureSensor.h"
#include "MPSSoilHumiditySensor.h"
#include "MPSSoilPhSensor.h"
#include "MPSSoilEcSensor.h"
#include "MPSSoilNitrogenSensor.h"
#include "MPSSoilPotassiumSensor.h"
#include "MPSSoilPhosphorousSensor.h"
// #include "Sht20AmbientHumiditySensor.h"
// #include "Sht20AmbientTemperatureSensor.h"

using namespace std;

SensorHandler SHandler;

DistanceSensor metaDistanceSensor;
RainSensor metaRainSensor;
DHTAmbientHumiditySensor metaAmbientHumiditySensor;
DHTAmbientTemperatureSensor ambientTemperatureSensor;
MPSSoilTemperatureSensor metaMPSTemperatureSensor;
MPSSoilHumiditySensor metaMPSHumiditySensor;
MPSSoilPhSensor metaMPSPhSensor;
MPSSoilEcSensor metaMPSEcSensor;
MPSSoilNitrogenSensor metaMPSNitroSensor;
MPSSoilPotassiumSensor metaMPSPotaSensor;
MPSSoilPhosphorousSensor metaMPSPhosphoSensor;
// Sht20AmbientTemperatureSensor ambientTemperatureSht20Sensor;
// Sht20AmbientHumiditySensor ambientHumiditySht20Sensor;

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("Distance value: " + String(metaDistanceSensor.fetchData()));
  Serial.println("Rain value: " + String(metaRainSensor.fetchData()));
  Serial.println("DHT Humidity value: " + String(metaAmbientHumiditySensor.fetchData()));
  Serial.println("DHT Temperature value: " + String(ambientTemperatureSensor.fetchData()));
  Serial.println("MPS Temperature value: " + String(metaMPSTemperatureSensor.fetchData()));
  Serial.println("MPS Humidity value: " + String(metaMPSHumiditySensor.fetchData()));
  Serial.println("MPSPh value: " + String(metaMPSPhSensor.fetchData()));
  Serial.println("MPSEc value: " + String(metaMPSEcSensor.fetchData()));
  Serial.println("MPSNitro value: " + String(metaMPSNitroSensor.fetchData()));
  Serial.println("MPSPhosphorous value: " + String(metaMPSPhosphoSensor.fetchData()));
  Serial.println("MPSPotassium value: " + String(metaMPSPotaSensor.fetchData()));
  // Serial.println("Sht20 Temperature value: " + String(ambientTemperatureSht20Sensor.fetchData()));
  // Serial.println("Sht20 Humidity value: " + String(ambientHumiditySht20Sensor.fetchData()));
  delay(500);
}