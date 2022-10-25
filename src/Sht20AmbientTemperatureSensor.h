#include "Arduino.h"
#include <Wire.h>
#include "DFRobot_SHT20.h"

DFRobot_SHT20 sht20Temp;

class Sht20AmbientTemperatureSensor: public AbstractSensor {  
    public: 
        Sht20AmbientTemperatureSensor(
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
            
        }

        float fetchData() {
            if(readCount == 0){
                sht20Temp.initSHT20();
                delay(100);
                sht20Temp.checkSHT20(); 
            }
            
            return sht20Temp.readTemperature();
        }
};