#include <ArduinoCar.h>
#include <Ultrasonic.h>

//NOT FINISHED YET
UltraSonic::UltraSonic(int Port) {
  Port = UltraPort;
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
  int a = microseconds/ 29 /2;
  return a;
}