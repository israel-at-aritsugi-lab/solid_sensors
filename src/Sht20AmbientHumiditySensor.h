#include "Arduino.h"
#include <Wire.h>
#include "DFRobot_SHT20.h"

DFRobot_SHT20 sht20Humid;

class Sht20AmbientHumiditySensor: public AbstractSensor {  
    public: 
        Sht20AmbientHumiditySensor(
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
            
        }

        float fetchData() {
            if(readCount == 0){
                sht20Humid.initSHT20();  
                delay(100);
                sht20Humid.checkSHT20(); 
            }

            return sht20Humid.readHumidity();
        }
};

