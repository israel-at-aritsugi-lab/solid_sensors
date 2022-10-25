#include "Arduino.h"

#include "SensorHandler.h"
#include "DistanceSensor.h"
#include "RainSensor.h"
#include "DHTAmbientHumiditySensor.h"
#include "DHTAmbientTemperatureSensor.h"
#include "Sht20AmbientHumiditySensor.h"
#include "Sht20AmbientTemperatureSensor.h"
#include "MPSSoilPhSensor.h"
#include "MPSSoilEcSensor.h"
#include "MPSSoilNitrogenSensor.h"
#include "MPSSoilPotassiumSensor.h"
#include "MPSSoilPhosphorousSensor.h"

using namespace std;

SensorHandler SHandler;

DistanceSensor metaDistanceSensor;
RainSensor metaRainSensor;
DHTAmbientHumiditySensor metaAmbientHumiditySensor;
DHTAmbientTemperatureSensor ambientTemperatureSensor;
Sht20AmbientHumiditySensor ambientHumiditySht20Sensor;
Sht20AmbientTemperatureSensor ambientTemperatureSht20Sensor;
MPSSoilEcSensor metaMPSEcSensor;
MPSSoilPhSensor metaMPSPhSensor;
MPSSoilNitrogenSensor metaMPSNitroSensor;
MPSSoilPotassiumSensor metaMPSPotaSensor;
MPSSoilPhosphorousSensor metaMPSPhosphoSensor;

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("Distance value: " + String(metaDistanceSensor.fetchData()));
  Serial.println("Rain value: " + String(metaRainSensor.fetchData()));
  Serial.println("DHT Humidity value: " + String(metaAmbientHumiditySensor.fetchData()));
  Serial.println("DHT Temperature value: " + String(ambientTemperatureSensor.fetchData()));
  Serial.println("Sht20 Humidity value: " + String(ambientHumiditySht20Sensor.fetchData()));
  Serial.println("Sht20 Temperature value: " + String(ambientTemperatureSht20Sensor.fetchData()));
  Serial.println("MPSPh value: " + String(metaMPSPhSensor.fetchData()));
  Serial.println("MPSEc value: " + String(metaMPSEcSensor.fetchData()));
  Serial.println("Nitro value: " + String(metaMPSNitroSensor.fetchData()));
  Serial.println("MPSPhosphorous value: " + String(metaMPSPhosphoSensor.fetchData()));
  Serial.println("MPSPotassium value: " + String(metaMPSPotaSensor.fetchData()));
  
  delay(500);
}