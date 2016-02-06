/*
  AnalogReadLCD
  Reads an analog input on pin 0, prints the result to the LCD.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
  
  This example show how initialize 4Control board using Board4Control library.
  
  It also explains how to use the Board4Control_LCD library
  The LCD display pins on 4Control board is multiplexed with the keys.
  A change was needed in the library of the official Arduino LCD to operate in 4Control board
  The Function b4Control.begin() initialize the pins on the LCD automatically
 
  Created by: Fabio Souza
  change history:
           06/02/16 - first version
  
 */

#include <Board4Control.h>   // include 4Control Library

void setup() {
  
  b4Control.begin();  // init pins(LED, buzzer, backlight) and lcd
  
  //LCD config
  //LCD first message
  lcd.setBacklight(HIGH);      //turn on backlight
  
  //LCD message
  lcd.print("    4Control");
  lcd.setCursor(0, 1);
  lcd.print("     Board");
  
  //beep init
  b4Control.beep(300);              //beep 300 ms
  
  delay(1000);
  lcd.clear();
    
}

void loop() {
    
  int potValue = analogRead(A0); // read the input on analog pin 0:
  
  lcd.setCursor(0,0);           //set cursor 
  lcd.print("        ");        //clear data
  lcd.setCursor(0,0);           //set cursor
  lcd.print("POT:");            //print a label: POT:
  lcd.print(potValue);          //print the value
  delay(500);                   // delay in between reads 


}
