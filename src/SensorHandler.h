#include "AbstractSensor.h"
#include "DataTransformer.h"
#include "RegressiveDataTransformer.h"

class SensorHandler { 
  public:
    RegressiveDataTransformer DTransformer;
  public:
    SensorHandler(){
        DTransformer = RegressiveDataTransformer();
    }

    void setSleepingMode(AbstractSensor &AbSensor, bool sleepingValue){
        AbSensor.cycleCount = 0;
        AbSensor.sleeping = sleepingValue;
    }

    float closeCycle(AbstractSensor &AbSensor){
        float meanData = 0;
        if(AbSensor.cycleCount != 0) meanData = AbSensor.sum / AbSensor.cycleCount;
        
        AbSensor.sum = 0;
        AbSensor.cycleCount = 0;
        
        return meanData;
    }

    void processData(DataTransformer &DtTransformer, AbstractSensor &AbSensor){
        AbSensor.sum += AbSensor.fetchData();
        
        if(AbSensor.cycleCount >= AbSensor.readCount){
            float tempValue = closeCycle(AbSensor);
            AbSensor.stateData = DtTransformer.transformData(tempValue, AbSensor);
            setSleepingMode(AbSensor, true);
        }
    }

    void routine(AbstractSensor &AbSensor, String label = "sensor"){
        
        AbSensor.cycleCount++;
        if(AbSensor.sleeping){
            delay(1);
            if (AbSensor.cycleCount >= AbSensor.sleepCount) setSleepingMode(AbSensor, false);
        } else {
            processData(DTransformer, AbSensor);

            // use sensor and data here
            Serial.println(label + " value: " + String(AbSensor.fetchData()));
        }
    }
};

