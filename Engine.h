#include "stdio.h"
#include "Thread.h"
#include "ThreadController.h"
#define MAXSIZE 512

class Engine {
  // stepBysteps that are gonna be used only have two signlas (direction and enable), and VCC and GND
  // Engine position
  int pos;
  // Engine pin! enable
  int pin;
  // Engine limit switch in axis
  int final;
  // axis direction pin!
  int directionpin;

  Thread moveThread = Thread();
  
  
  
  public:
    Engine(int p,int f, int dir){
      this->pin = p;
      this->final = f;
      this->directionpin = dir;
      }    
      
   // go to Zero position.
  void toZero(){    
    //final_X is pin which corresponds with a end switch
    pinMode(pin,OUTPUT);
    while(analogRead(final)>0) {
        //Enable stepBystep go to left,Under (if is it on LOW position go to the other side)
        digitalWrite(directionpin,HIGH);
        digitalWrite(pin,HIGH);  
    }
    digitalWrite(pin,LOW);
    pos = 0;    
    }
    
  //move stepBystep to Rigth
  int movestepBystepStepRigth(int step){
      for(int i = 0; i< step; i++){
        digitalWrite(directionpin,LOW);
        digitalWrite(pin,HIGH); 
        this->pos = step - 1;          
      }
      digitalWrite(pin,LOW);
      return this->pos;
        
  }
  //move stepBystep to left
  int movestepBystepStepLeft(int step){
      for(int i = 0; i< step; i++){
        digitalWrite(directionpin,HIGH);
        digitalWrite(pin,HIGH);
        this->pos = step + 1;          
      }
      digitalWrite(pin,LOW);    
      return this->pos;
  }
 
  void setPos(int step) {
      this->pos = step;
      }
  
  boolean isInSetUp(){
    return 0 == pos;
  }

  
};
