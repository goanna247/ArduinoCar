#include <Arduino.h>
#include <ArduinoCar.h>

class UltraSonic {
  public:
    UltraSonic(int port);
    void Bounce(int distance);
    void Stop(int distance);

  private:
    int UltraPort;
    long duration, cm;
    void Calc();
    long microsecondsToCentimeters(long microseconds);
};