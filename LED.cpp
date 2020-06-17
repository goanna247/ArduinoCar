#include <LED.h>
#include <Arduino.h>

LED::LED(int port1,int port2, int port3) {
  blueLED = port1;
  greenLED = port2;
  redLED = port3;
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void LED::OFF() {
  digitalWrite(blueLED, LOW);   
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW); 
}

void LED::ON(int colour) {
  if (colour == 0) {
    // RGBColour(255, 0, 0); //blue
    digitalWrite(blueLED, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
  } else if (colour == 1) {
    // RGBColour(0, 255, 0); //green
    digitalWrite(blueLED, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
  } else if (colour == 2) {
    // RGBColour(0, 0, 255); //red
    digitalWrite(blueLED, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
  } else if (colour == 3) {
    // RGBColour(255, 255, 125); //aqua
    digitalWrite(blueLED, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
  } else if (colour == 4) {
    // RGBColour(0, 255, 255); //yellow 
    digitalWrite(blueLED, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, HIGH);
  } else if (colour == 5) {
    // RGBColour(255, 0, 255); //purple
    digitalWrite(blueLED, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
  } 
  // else if (colour == 6) {
  //   RGBColour(255, 255, 0); //yellow
  // } else if (colour == 7) {
  //   RGBColour(255, 255, 255); //white 
  // }
}

// void LED::RGBColour(int redLightValue, int greenLightValue, int blueLightValue) {
//   analogWrite(redLED, redLightValue);
//   analogWrite(greenLED, greenLightValue);
//   analogWrite(blueLED, blueLightValue);
// }