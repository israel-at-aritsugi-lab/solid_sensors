#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dhtTemp(DHTPIN, DHTTYPE);

class DHTAmbientTemperatureSensor: public AbstractSensor {  
    public: 
        DHTAmbientTemperatureSensor(
            word sensorSleepCount=1000, 
            byte sensorReadCount=10, 
            byte sensorMValue=10, 
            byte sensorCValue=200, 
            word sensorMinValue=0, 
            word sensorMaxValue=1000
        ): AbstractSensor(
            sensorSleepCount, 
            sensorReadCount, 
            sensorMValue, 
            sensorCValue, 
            sensorMinValue, 
            sensorMaxValue
        ){
            dhtTemp.begin();
        }

        float fetchData() {
            return dhtTemp.readTemperature();
        }
};

