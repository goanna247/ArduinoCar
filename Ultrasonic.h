#include <Arduino.h>

class UltraSonic {
  public:
    UltraSonic(int port);
    void Bounce(int distance);
    void Stop(int distance);

  private:
    int UltraPort;
    long Duration, cm;
};