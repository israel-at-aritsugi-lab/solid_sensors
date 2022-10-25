#include "Arduino.h"

#include "SensorHandler.h"
#include "DistanceSensor.h"
#include "RainSensor.h"
#include "AmbientHumiditySensor.h"
#include "AmbientTemperatureSensor.h"
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
AmbientHumiditySensor metaAmbientHumiditySensor;
AmbientTemperatureSensor ambientTemperatureSensor;
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
  SHandler.routine(metaDistanceSensor, "Distance");
  SHandler.routine(metaRainSensor, "Rain");
  SHandler.routine(metaAmbientHumiditySensor, "Humidity");
  SHandler.routine(ambientTemperatureSensor, "Temperature");
  SHandler.routine(ambientHumiditySht20Sensor, "HumiditySht20");
  SHandler.routine(ambientTemperatureSht20Sensor, "TemperatureSht20");
  SHandler.routine(metaMPSPhSensor, "MPSPh");
  SHandler.routine(metaMPSEcSensor, "MPSEc");
  SHandler.routine(metaMPSNitroSensor, "MPSNitro");
  SHandler.routine(metaMPSPhosphoSensor, "MPSPhospho");
  SHandler.routine(metaMPSPotaSensor, "MPSPota");
  
  delay(500);
}