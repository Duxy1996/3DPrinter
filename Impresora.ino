

#include "stdio.h"
#include "Engine.h"
#include "Servo.h"
#include <LiquidCrystal.h>
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

  int selected;

  //Start display
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
  
  //Start the code
  Engine engenieX =  Engine(servoX,22,49,23);
  Engine engenieY =  Engine(servoY,24,51,25);
  Engine engenieZ =  Engine(servoZ,26,53,27);
  
  lcd.begin(16,1);
  lcd.print("Hello, Im a Printer");
  
  while(true){
    lcd.println("Options");
    lcd.setCursor(0,0);
    lcd.print("calibrate");
    lcd.setCursor(0,1);
    lcd.print("None");
    while(true){ 
      int sensorValue = analogRead(A0);
      sensorValue = sensorValue * 5 * 1023;
      if(sensorValue < 1){selected == 0;}
      if(sensorValue < 2 && sensorValue > 1){selected == 1;}
      if(sensorValue < 3 && sensorValue > 2){selected == 2;}
      if(sensorValue < 4 && sensorValue > 3){selected == 3;}
      if(sensorValue > 4){selected == 4;}      
      if(analogRead(A1) > 1){
          break;        
        }  
      switch(sensorValue){
          case 0  :  calibrateAxisToZero(engenieX,engenieY,engenieZ) ;
                     break; //optional
          case 1  :  calibrateAxisToZero(engenieX,engenieY,engenieZ);
                     break; //optional  
          
      }


        

              
      
    }



    
  }

  
}
void loop() {
  // no need to repeat the melody.
}
