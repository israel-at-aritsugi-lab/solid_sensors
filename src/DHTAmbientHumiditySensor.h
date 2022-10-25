#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dhtHumid(DHTPIN, DHTTYPE);

class DHTAmbientHumiditySensor: public AbstractSensor {  
    public: 
        DHTAmbientHumiditySensor(
            word sensorSleepCount=1000, 
            byte sensorReadCount=10, 
            byte sensorMValue=10, 
            byte sensorCValue=0, 
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
            dhtHumid.begin();
        }

        float fetchData() {
            return dhtHumid.readHumidity();
        }
};

