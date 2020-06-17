#ifndef _LED_H_
#define _LED_H_
#include <string.h>

class LED {
  public:
    LED(int port1, int port2, int port3);
    void ON(int colour);
    void OFF();
  private:
    void RGBColour(int redLightValue, int greenLightValue, int blueLightValue);
    int blueLED;
    int greenLED;
    int redLED;
};
#endif