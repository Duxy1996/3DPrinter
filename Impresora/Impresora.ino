//Created by Carlos Durán Roca.

#include "stdio.h"
#include "Engine.h"
//#include "stepBystep.h"  // hasta 12 SSC32 polulu 4988 allegro
#include "interface.h"
#include <LiquidCrystal.h>
// CONSTANTS
#define sizeX 512
#define sizeY 512
#define sizeZ 512

#define LCDRS 12
#define LCDE 11
#define LCDPINONE 5
#define LCDPINTWO 4
#define LCDPINTHREE 3
#define LCDPINFOUR 2
#define PINANA A0
#define PINANAONE A1

//Vars

  int selected;
  int sensorValue;
  
  //Start display 12->write enable others control the display.
  LiquidCrystal lcd(LCDRS, LCDE, LCDPINONE, LCDPINTWO, LCDPINTHREE, LCDPINFOUR);
  Interface LCDScreen;
  //Start the code
  Engine engenieX =  Engine(22,49,23); // Inizialice StepByStep Engine (Engine pin enable(one step),limit swich pin,Engine pin rotation direction)
  Engine engenieY =  Engine(24,51,25); // Inizialice StepByStep Engine (Engine pin enable(one step),limit swich pin,Engine pin rotation direction)
  Engine engenieZ =  Engine(26,53,27); // Inizialice StepByStep Engine (Engine pin enable(one step),limit swich pin,Engine pin rotation direction)

  //Threads to move stepBysteps
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
    engenieX.movestepBystepStepLeft(1);    
  }
  void moveLeftY(){
    engenieX.movestepBystepStepLeft(1);    
  }
  void moveLeftZ(){
    engenieX.movestepBystepStepLeft(1);    
  }
  
  //Move to Rigth one by one until 512
  void moveRigthX(){
    engenieX.movestepBystepStepLeft(1);    
  }
  void moveRigthY(){
    engenieX.movestepBystepStepLeft(1);    
  }
  void moveRigthZ(){
    engenieX.movestepBystepStepLeft(1);    
  }


void setup() {  
  lcd.begin(16,2);
  //Inizialice Interface
  
  LCDScreen.init(lcd);
  LCDScreen.Options(lcd,0);  
  sensorValue = 0;
 
}
void loop() {
  
   while(true) {    
    while(true) { 
      int ant = sensorValue;
      sensorValue = analogRead(A0);
      sensorValue = sensorValue * 5 / 1010; 
      if(ant != sensorValue){     
        LCDScreen.Options(lcd,sensorValue);  
        delay(100);
      }      
      
      if(analogRead(A1) > 1){
          break;// exit from while(true)  
        }  
    switch(sensorValue){
       case 0  :  calibrateAxisToZero(engenieX,engenieY,engenieZ) ;
                  break; //optional
       case 1  :  calibrateAxisToZero(engenieX,engenieY,engenieZ); 
                  break; //optional  
       case 2  :  for(int i = 0;i < 256;i++){
                    //Create a thread which moves the Engine(Simulation thread)
                    moveThreadX.onRun(moveLeftX);
                    //Create a thread which moves the Engine(Simulation thread)
                    moveThreadY.onRun(moveLeftY);
                    //Create a thread which moves the Engine(Simulation thread)
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
