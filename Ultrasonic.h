#include <Arduino.h>
#include <ArduinoCar.h>

class UltraSonic {
  public:
    UltraSonic(int port);
    void Stop(int distance);
    void Calc();
    int UltraPort;
    long duration, cm;
    long microsecondsToCentimeters(long microseconds);  
  private:

};