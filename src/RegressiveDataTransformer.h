// #include "DataTransformer.h"
// #include "AbstractSensor.h"

class RegressiveDataTransformer: public DataTransformer {  
    public: 
        RegressiveDataTransformer(): DataTransformer(){}

        float transformData(float data, AbstractSensor &AbSensor) {
            return (data * AbSensor.mValue) + AbSensor.cValue;
        }
};

