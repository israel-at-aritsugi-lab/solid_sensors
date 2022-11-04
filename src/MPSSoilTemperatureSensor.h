#include <AltSoftSerial.h>

#define DEPin 11

const byte soiltemp[] = {0x01, 0x03, 0x00, 0x13, 0x00, 0x01, 0x75, 0xCF};

class MPSSoilTemperatureSensor: public AbstractSensor {   
  public:
    AltSoftSerial mod;
    int values[12];
    int val1, val2, val3, val4, val5, val6,val7;

    MPSSoilTemperatureSensor(
      word sensorSleepCount=100, 
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
      mod.begin(9600);
      pinMode(DEPin, OUTPUT);
      digitalWrite(DEPin, LOW);
    }

  float fetchData(){
      mod.begin(9600);
      int* tempval = RS485soil();
      return ((tempval[3]*256) + tempval[4]) / 10;
  }

  int* RS485soil() {
    // clear the receive buffer
    mod.flushInput();
    digitalWrite(DEPin, HIGH);
    delay(1);
    // write out the message
    for (uint8_t i = 0; i < sizeof(soiltemp); i++ ) mod.write( soiltemp[i] );
    // wait for the transmission to complete
    mod.flush();
    digitalWrite(DEPin, LOW);
    // delay to allow response bytes to be received!
    delay(500);
    // read in the received bytes
    for (int i = 0; i < 7; i++) {
      values[i] = mod.read();
    }
    return values;
  }
};

