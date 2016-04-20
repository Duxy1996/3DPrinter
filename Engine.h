#include "stdio.h"
#include "Servo.h"
#define MAXSIZE 512

class Engine {
  // Servos that are gonna be used only have two signlas (direction and enable), and VCC and GND
  // Engine position
  int pos;
  // Engine pin enable
  int pin;
  // Engine limit switch in axis
  int final;
  // axis direction
  int directionpin;
  
  // Servo one is always used
  Servo one;
  // Servo Two is used only in the vertical 
  Servo two;
  public:
    Engine(Servo o,int p,int f, int dir){
      this->one = o;
      this->pin = p;
      this->final = f;
      this->directionpin = dir;
      }    
      
   // go to Zero position.
  void toZero(){    
    //final_X is pin which corresponds with a "final de carrera"
    pinMode(pin,OUTPUT);
    while(analogRead(final)>0) {
        //Enable Servo go to left,Under (if is it on LOW position go to the other side)
        digitalWrite(directionpin,HIGH);
        digitalWrite(pin,HIGH);  
    }
    digitalWrite(pin,LOW);
    pos = 0;    
    }
  //move servo to Rigth
  void moveServoStepRigth(int step){
      for(int i = 0; i< step; i++){
        digitalWrite(directionpin,LOW);
        digitalWrite(pin,HIGH);         
      }
      digitalWrite(pin,LOW);    
  }
  //move Servo to left
  void moveServoStepLeft(int step){
      for(int i = 0; i< step; i++){
        digitalWrite(directionpin,HIGH);
        digitalWrite(pin,HIGH);         
      }
      digitalWrite(pin,LOW);    
  }
  
  
  boolean isInSetUp(){
    return 0 == pos;
  }

  
};
