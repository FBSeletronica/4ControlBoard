/*
  readButtons
  This example shows how to read keys presents on the 4ControlBoard   
  
  
  This example show how initialize 4Control board using Board4Control library.
  
  
  It also explains how to use the Board4Control_LCD library
  The LCD display pins on 4Control board is multiplexed with the keys.
  A change was needed in the library of the official Arduino LCD to operate in 4Control board
  The Function b4Control.begin() initialize the pins on the LCD automatically
 
  
  Created by: Fabio Souza
  change history:
           06/02/16 - first version
  
 */


#include <Board4Control.h>

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
  
  lcd.setCursor(0, 0);
  lcd.print("S1:     S2:     ");
  lcd.setCursor(0, 1);
  lcd.print("S3:  S3:  S5:   ");
   
  
  
}

void loop() {
  
  if(b4Control.readButton(SW1_PIN)){
    b4Control.beep(100);
  }
  
  if(b4Control.readButton(SW2_PIN)){
    b4Control.beep(100);
  }
  
  if(b4Control.readButton(SW3_PIN)){
    b4Control.beep(100);
  }
  
  if(b4Control.readButton(SW4_PIN)){
    b4Control.beep(100);
  }
}
