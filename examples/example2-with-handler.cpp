#include "Arduino.h"

#include "SensorHandler.h"
#include "DistanceSensor.h"
#include "RainSensor.h"
#include "DHTAmbientHumiditySensor.h"
#include "DHTAmbientTemperatureSensor.h"
#include "Sht20AmbientHumiditySensor.h"
#include "Sht20AmbientTemperatureSensor.h"
#include "MPSSoilTemperatureSensor.h"
#include "MPSSoilHumiditySensor.h"
#include "MPSSoilPhSensor.h"
#include "MPSSoilEcSensor.h"
#include "MPSSoilNitrogenSensor.h"
#include "MPSSoilPotassiumSensor.h"
#include "MPSSoilPhosphorousSensor.h"

using namespace std;

SensorHandler SHandler;

DistanceSensor metaDistanceSensor;
RainSensor metaRainSensor;
DHTAmbientHumiditySensor metaAmbientHumidityDHTSensor;
DHTAmbientTemperatureSensor ambientTemperatureDHTSensor;
Sht20AmbientHumiditySensor ambientHumiditySht20Sensor;
Sht20AmbientTemperatureSensor ambientTemperatureSht20Sensor;
MPSSoilTemperatureSensor metaMPSTemperatureSensor;
MPSSoilHumiditySensor metaMPSHumiditySensor;
MPSSoilEcSensor metaMPSEcSensor;
MPSSoilPhSensor metaMPSPhSensor;
MPSSoilNitrogenSensor metaMPSNitroSensor;
MPSSoilPotassiumSensor metaMPSPotaSensor;
MPSSoilPhosphorousSensor metaMPSPhosphoSensor;

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
  SHandler.routine(metaMPSTemperatureSensor, "MPSTemperature");
  SHandler.routine(metaMPSHumiditySensor, "MPSHumidity");
  SHandler.routine(metaMPSPhSensor, "MPSPh");
  SHandler.routine(metaMPSEcSensor, "MPSEc");
  SHandler.routine(metaMPSNitroSensor, "MPSNitro");
  SHandler.routine(metaMPSPhosphoSensor, "MPSPhospho");
  SHandler.routine(metaMPSPotaSensor, "MPSPota");
  
  delay(500);
}