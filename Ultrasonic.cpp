#include <ArduinoCar.h>
#include <Ultrasonic.h>

//NOT FINISHED YET
UltraSonic::UltraSonic(int Port) {
  Port = UltraPort;
}

void UltraSonic::Bounce(int distance) {
  // digitalWrite(IN1, HIGH);
  // digitalWrite(IN2, LOW);
  // digitalWrite(IN3, HIGH);
  // digitalWrite(IN4, LOW);
  // analogWrite(ENA, speed);
  // analogWrite(ENB, speed);
  Calc();
  if (cm < 20) {
//     analogWrite(ENA, 0);
//     analogWrite(ENB, 0);
//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, LOW);
//     digitalWrite(IN3, LOW);
//     digitalWrite(IN4, LOW);
//     analogWrite(ENA, 0);
//     analogWrite(ENB, 0);
//     delay(500);
//     analogWrite(ENA, 0);
//     analogWrite(ENB, 0);

//     analogWrite(ENA, 0);
//     analogWrite(ENB, 0);    
//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, HIGH);
//     digitalWrite(IN3, LOW);
//     digitalWrite(IN4, HIGH;
//     analogWrite(ENA, 250);                         
//     analogWrite(ENB, 250);
//     delay(800);
//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, HIGH);
//     digitalWrite(IN3, HIGH);
//     digitalWrite(IN4, LOW);
//     analogWrite(ENA, 250);
//     analogWrite(ENB, 250);
//     delay(1000);
//     analogWrite(ENA, 0);
//     analogWrite(ENB, 0);
  }
}

void UltraSonic::Stop(int distance) {
//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, HIGH);
//   digitalWrite(IN4, LOW);
//   analogWrite(ENA, 250);
//   analogWrite(ENB, 250);
  Calc();
  if (cm < distance) {
//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, LOW);
//     digitalWrite(IN3, LOW);
//     digitalWrite(IN4, LOW);
//     analogWrite(ENA, 0);
//     analogWrite(ENB, 0);
  }
}

void UltraSonic::Calc() {
  pinMode(UltraPort, OUTPUT);
  digitalWrite(UltraPort, LOW);
  delayMicroseconds(2);
  digitalWrite(UltraPort, HIGH);
  delayMicroseconds(5);
  digitalWrite(UltraPort, LOW);
  pinMode(UltraPort, INPUT);
  duration = pulseIn(UltraPort, HIGH);
  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}