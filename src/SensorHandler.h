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

    // float transformData(AbstractSensor &AbSensor){
    //     if(isnan(AbSensor.stateData)) return 0;
    //     return (AbSensor.stateData * AbSensor.mValue) + AbSensor.cValue;
    // }

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

    void routine(AbstractSensor &AbSensor){
        Serial.print(".");
        AbSensor.cycleCount++;
        if(AbSensor.sleeping){
            delay(1);
            if (AbSensor.cycleCount >= AbSensor.sleepCount) setSleepingMode(AbSensor, false);
        } else processData(DTransformer, AbSensor);
    }
};

