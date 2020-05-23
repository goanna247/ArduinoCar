#ifndef _ARDUINOCAR_H_
#define _ARDUINOCAR_H_
#include <string.h>

class DriveBase {
  public:
    DriveBase(int pinENA, int pinIN1, int pinIN2, int pinIN3, int pinIN4, int pinENB);
    void forwards(int speed, int waitTime);
    void backwards(int speed, int waitTime);
    void oneWheelLeft(int speed, int waitTime);
    void oneWheelRight(int speed, int waitTime);
    void twoWheelLeft(int speed, int waitTime);
    void twoWheelRight(int speed, int waitTime);
    void STOP();
    void Controller(unsigned long Forwards_Value, unsigned long Backwards_Value, unsigned long Left_Value, unsigned long Right_value);
    void IRON();

  private:
    int ENA;
    int ENB;
    int IN1;
    int IN2;
    int IN3;
    int IN4;
};
#endif