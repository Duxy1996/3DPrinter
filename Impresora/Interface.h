#include "stdio.h"
#include  <LiquidCrystal.h>
class Interface {
  public: Interface(){

      
      }

   void init(LiquidCrystal lcd){ 
    lcd.print("Hello, Im a Printer");  
    delay(5000);
    lcd.println("Options:");
    delay(5000);  
  }
 
  void Options(LiquidCrystal lcd,int index){   
    switch(index){
       case 0  :  lcd.clear();
                  lcd.print(">CalibrateAxis");
                  lcd.setCursor(0,2);
                  lcd.print(" CalibrateExtrusor");
                  break; //optional
       case 1  :  lcd.clear();
                  lcd.print(" CalibrateAxis");
                  lcd.setCursor(0,2);
                  lcd.print(">CalibrateExtrusor");
                  break; //optional  
       case 2  :  lcd.clear();
                  lcd.print(">loadFromSD");
                  lcd.setCursor(0,2);
                  lcd.print(" More options");
                  break; //optional
       case 3  :  lcd.clear();
                  lcd.print(" loadFromSD");
                  lcd.setCursor(0,2);
                  lcd.print(">More options");
                  break; //optional
       case 4  :  lcd.clear();
                  lcd.print(">About");
                  lcd.setCursor(0,2);
                  lcd.print("");
                  break; //optional          
      }     
    
  }
  void loadFromSD(LiquidCrystal lcd,int index){

    
  }
  void calibrateAxis(LiquidCrystal lcd,int index){
    switch(index){
       case 0  :  lcd.setCursor(0,0);
                  lcd.print(">Go to (0,0,0)");
                  lcd.setCursor(0,1);
                  lcd.print(" Calibrate Board");
                  break; //optional
       case 1  :  lcd.setCursor(0,0);
                  lcd.print(" Go to (0,0,0)");
                  lcd.setCursor(0,1);
                  lcd.print(">Calibrate Board");
                  break; //optional  
       case 2  :  lcd.setCursor(0,0);
                  lcd.print(" Calibrate Board");
                  lcd.setCursor(0,1);
                  lcd.print(">Go to half");
                  break; //optional       
      } 
  }
  void calibrateExtrusor(LiquidCrystal lcd,int index){

    
  }


  
};

