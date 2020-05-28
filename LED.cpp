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
  RGBColour(0, 0, 0); // off
}

void LED::ON(int colour) {
  if (colour == 0) {
    RGBColour(255, 0, 0); //red 
  } else if (colour == 1) {
    RGBColour(0, 255, 0); //green
  } else if (colour == 2) {
    RGBColour(0, 0, 255); //blue 
  } else if (colour == 3) {
    RGBColour(255, 255, 125); //raspberry 
  } else if (colour == 4) {
    RGBColour(0, 255, 255); //cyan 
  } else if (colour == 5) {
    RGBColour(255, 0, 255); //magenta
  } else if (colour == 6) {
    RGBColour(255, 255, 0); //yellow
  } else if (colour == 7) {
    RGBColour(255, 255, 255); //white 
  }
}

void LED::RGBColour(int redLightValue, int greenLightValue, int blueLightValue) {
  analogWrite(redLED, redLightValue);
  analogWrite(greenLED, greenLightValue);
  analogWrite(blueLED, blueLightValue);
}