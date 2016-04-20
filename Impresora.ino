

#include "stdio.h"
#include "Engine.h"
#include "Servo.h"
// CONSTANTS
#define sizeX 512
#define sizeY 512
#define sizeZ 512


void calibrateAxisToZero(Engine &engenieX,Engine &engenieY,Engine &engenieZ){
  engenieX.toZero();
  engenieY.toZero();
  engenieZ.toZero();  
}


void setup() {
  //Vars
  Servo servoX;
  Servo servoY;
  Servo servoZ;
  
  //Start the code
  Engine engenieX =  Engine(servoX,22,49,23);
  Engine engenieY =  Engine(servoY,24,51,25);
  Engine engenieZ =  Engine(servoZ,26,53,27);
  while(true){
    Serial.println("Options");
    



    
  }

  
}
void loop() {
  // no need to repeat the melody.
}
