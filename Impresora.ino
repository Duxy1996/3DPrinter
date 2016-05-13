//Created by Carlos Durán Roca.

#include "stdio.h"
#include "Engine.h"
//#include "Servo.h"  // hasta 12 SSC32 polulu 4988 allegro
#include "interface.h"
#include <LiquidCrystal.h>
// CONSTANTS
#define sizeX 512
#define sizeY 512
#define sizeZ 512

//Vars

  int selected;

  //Start display 12->write enable others control the display.
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
  
  //Start the code
  Engine engenieX =  Engine(22,49,23);
  Engine engenieY =  Engine(24,51,25);
  Engine engenieZ =  Engine(26,53,27);

  //Threads to move Servos
  Thread moveThreadX = Thread();
  Thread moveThreadY = Thread();
  Thread moveThreadZ = Thread();



  void calibrateAxisToZero(Engine &engenieX,Engine &engenieY,Engine &engenieZ){
    engenieX.toZero();
    engenieY.toZero();
    engenieZ.toZero();  
  }

  //Move to left one by one until 512
  void moveLeftX(){
    engenieX.moveServoStepLeft(1);    
  }
  void moveLeftY(){
    engenieX.moveServoStepLeft(1);    
  }
  void moveLeftZ(){
    engenieX.moveServoStepLeft(1);    
  }
  
  //Move to Rigth one by one until 512
  void moveRigthX(){
    engenieX.moveServoStepLeft(1);    
  }
  void moveRigthY(){
    engenieX.moveServoStepLeft(1);    
  }
  void moveRigthZ(){
    engenieX.moveServoStepLeft(1);    
  }


void setup() {  
  lcd.begin(16,2);
  //Inizialice Interface
  Interface LCDScreen;  
  
  LCDScreen.init(lcd);
  LCDScreen.Options(lcd,0);
  
  while(true){
    
    while(true){ 
      int sensorValue = analogRead(A0);
      sensorValue = sensorValue * 5 * 1023;
      //Calibrate Axis
      if(sensorValue < 1){selected == 0;LCDScreen.Options(lcd,selected);}
      //Calibrate Extrusor
      if(sensorValue < 2 && sensorValue > 1){selected == 1;LCDScreen.Options(lcd,selected);}
      //Load From sd
      if(sensorValue < 3 && sensorValue > 2){selected == 2;LCDScreen.Options(lcd,selected);}
      //More
      if(sensorValue < 4 && sensorValue > 3){selected == 3;LCDScreen.Options(lcd,selected);}
      //about
      if(sensorValue > 4){selected == 4;LCDScreen.Options(lcd,selected);}      
      if(analogRead(A1) > 1){
          break;        
        }  
    switch(sensorValue){
       case 0  :  calibrateAxisToZero(engenieX,engenieY,engenieZ) ;
                  break; //optional
       case 1  :  calibrateAxisToZero(engenieX,engenieY,engenieZ); 
                  break; //optional  
       case 2  :  for(int i = 0;i < 256;i++){
                    moveThreadX.onRun(moveLeftX);
                    moveThreadY.onRun(moveLeftY);
                    moveThreadZ.onRun(moveLeftZ);   
                  } 
                  break; //optional
       case 3  :  calibrateAxisToZero(engenieX,engenieY,engenieZ);
                  break; //optional
       case 4  :  calibrateAxisToZero(engenieX,engenieY,engenieZ);
                  break; //optional          
      }
    }
   
  }
}
void loop() {
  // no need to repeat the melody.
}
