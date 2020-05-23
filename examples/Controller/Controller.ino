#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <ArduinoCar.h>
//these are all the librarys that we need to include 

DriveBase _driveBase(4, 3, 2, 10, 9, 7);
//this defines an instance of the DriveBase (your car) and sets the ports 
//for this example we have set the ports as follows:
/*
ENA - 4
IN1 - 3
IN2 - 2
IN3 - 10
IN4 - 9
ENB - 7
and the IR remote port is always set to port 11
*/

unsigned long forwards = 0xFF629D;
unsigned long backwards = 0xFFA857;
unsigned long left = 0xFFC23D;
unsigned long right = 0xFF22DD;
//these are the Hex values that your remote sends to your car
//if these values dont match up to what your IR reciever reads,
//there is instructions in the read.me on how to change them 

void setup() {
  //this is called once at the beginning of our code
  //this function turns on the Serial monitor and enables the IR reciever
  _driveBase.IRON();
}

void loop() {
  //this is our code which runs when we deploy the program
  //it continuously loops running all of the code inside it 

  _driveBase.Controller(forwards, backwards, left,right);
  //this function gives basic controller functions, forwards, backwards, left and right
}