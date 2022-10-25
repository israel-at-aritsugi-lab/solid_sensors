// #include "AbstractSensor.h"

class DataTransformer {
  public:
    DataTransformer(){}

    virtual float transformData(float data, AbstractSensor &AbSensor)=0;
};

