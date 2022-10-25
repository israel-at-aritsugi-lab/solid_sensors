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
  SHandler.routine(metaDistanceSensor);
  SHandler.routine(metaRainSensor);
  SHandler.routine(metaAmbientHumiditySensor);
  SHandler.routine(ambientTemperatureSensor);
  SHandler.routine(ambientHumiditySht20Sensor);
  SHandler.routine(ambientTemperatureSht20Sensor);
  SHandler.routine(metaMPSPhSensor);
  SHandler.routine(metaMPSEcSensor);
  SHandler.routine(metaMPSNitroSensor);
  SHandler.routine(metaMPSPhosphoSensor);
  SHandler.routine(metaMPSPotaSensor);
  
  delay(500);
}