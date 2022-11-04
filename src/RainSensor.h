#define RainAnalogPin A0

class RainSensor: public AbstractSensor {  
    public: 
        RainSensor(
            word sensorSleepCount=100, 
            byte sensorReadCount=10, 
            byte sensorMValue=1, 
            byte sensorCValue=0, 
            word sensorMinValue=0, 
            word sensorMaxValue=1024
        ): AbstractSensor(
            sensorSleepCount, 
            sensorReadCount, 
            sensorMValue, 
            sensorCValue, 
            sensorMinValue, 
            sensorMaxValue
        ){}

        float fetchData() {
            return analogRead(RainAnalogPin);
        }
};

