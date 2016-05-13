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
       case 0  :  lcd.setCursor(0,0);
                  lcd.print(">CalibrateAxis");
                  lcd.setCursor(0,1);
                  lcd.print(" CalibrateExtrusor");
                  break; //optional
       case 1  :  lcd.setCursor(0,0);
                  lcd.print(" CalibrateAxis");
                  lcd.setCursor(0,1);
                  lcd.print(">CalibrateExtrusor");
                  break; //optional  
       case 2  :  lcd.setCursor(0,0);
                  lcd.print("CalibrateExtrusor");
                  lcd.setCursor(0,1);
                  lcd.print(">loadFromSD");
                  break; //optional
       case 3  :  
                  break; //optional
       case 4  :  
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

