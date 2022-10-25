#define echoPin 5
#define trigPin 6

class DistanceSensor: public AbstractSensor {  
    public: 
        DistanceSensor(
            word sensorSleepCount=100, 
            byte sensorReadCount=10, 
            byte sensorMValue=100, 
            byte sensorCValue=0, 
            word sensorMinValue=0, 
            word sensorMaxValue=9999
        ): AbstractSensor(
            sensorSleepCount, 
            sensorReadCount, 
            sensorMValue, 
            sensorCValue, 
            sensorMinValue, 
            sensorMaxValue
        ){
            // if(sensorSleepCount == 0) sensorSleepCount=100;
        }

        float fetchData() {
            pinMode(trigPin, OUTPUT);
            digitalWrite(trigPin, LOW);
            delayMicroseconds(2);
            digitalWrite (trigPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin, LOW);
            pinMode(echoPin, INPUT);
            return pulseIn (echoPin, HIGH) * 0.034/2;
        }
};

