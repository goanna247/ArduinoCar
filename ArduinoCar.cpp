#include "ArduinoCar.h"
#include <Arduino.h>
#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <string.h>

const int Port = 11;
IRrecv irrecv(Port);

DriveBase::DriveBase(int pinENA,int pinIN1, int pinIN2, int pinIN3, int pinIN4, int pinENB) {
  ENA = pinENA;
  ENB = pinENB;
  IN1 = pinIN1;
  IN2 = pinIN2;
  IN3 = pinIN3;
  IN4 = pinIN4;
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void DriveBase::IRON() {
  Serial.begin(9600);
  irrecv.enableIRIn(); 
}


void DriveBase::forwards(int speed, int waitTime) {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  delay(waitTime);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void DriveBase::backwards(int speed, int waitTime) {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  delay(waitTime);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void DriveBase::oneWheelLeft(int speed, int waitTime) {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  delay(waitTime);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void DriveBase::oneWheelRight(int speed, int waitTime) {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  delay(waitTime);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void DriveBase::twoWheelLeft(int speed, int waitTime) {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  delay(waitTime);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void DriveBase::twoWheelRight(int speed, int waitTime) {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  delay(waitTime);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void DriveBase::STOP() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}




void DriveBase::Controller(unsigned long Forwards_Value, unsigned long Backwards_Value, unsigned long Left_Value, unsigned long Right_value) {
  decode_results results; 

  if(irrecv.decode(&results)) {
    irrecv.resume();
  } 

  // Serial.println(Forwards_Value);
  // Serial.println(Backwards_Value);
  // Serial.println(Left_Value);
  // Serial.println(Right_value);

  if (results.value == Forwards_Value ) {
    forwards(250, 100);
    Serial.println("forwards");
  } else if (results.value == Backwards_Value) {
    backwards(250, 100);
    Serial.println("backwards");
  } else if (results.value == Left_Value) {
    twoWheelLeft(250, 100);
    Serial.println("left");
  } else if (results.value == Right_value) {
    twoWheelRight(250, 100);
    Serial.println("right");
  }
}





