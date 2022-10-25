#define freeAnalogPin A7

class AbstractSensor {   
  public:
    float sum; 
    bool sleeping;
    word sleepCount; 
    byte readCount;
    word cycleCount; 
    float stateData = 0;
    byte mValue;
    byte cValue;
    word minValue;
    word maxValue;
  
  public:
    AbstractSensor(
      word sensorSleepCount=1000, 
      byte sensorReadCount=10, 
      byte sensorMValue=1, 
      byte sensorCValue=0, 
      word sensorMinValue=0, 
      word sensorMaxValue=100
    ){
      sum = 0;
      sleeping = false;
      sleepCount = sensorSleepCount;
      readCount = sensorReadCount;
      cycleCount = 0;
      stateData = 0;
      mValue = sensorMValue;
      cValue = sensorCValue;
      minValue = sensorMinValue;
      maxValue = sensorMaxValue;
      sleeping = true;
    }

    virtual float fetchData()=0;
};

