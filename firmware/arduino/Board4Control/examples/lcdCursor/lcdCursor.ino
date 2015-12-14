/*
  lcdCursor
  This example shows how to use the LCD display of 4Control board and its cursor
  
  The LCD display on 4Control board is multiplexed with the keys.
  
 A change was needed in the library of the official Arduino LCD to operate in 4Control board
  
  The Function b4Control.begin() initialize the pins on the LCD automatically
  
  This example show how initialize 4Control board using Board4Control library.
  
  It also explains how to use the Board4Control_LCD library
  
  Created by: Fabio Souza
  change history:
           08/11/15 - first version
  
 */

//4Control Board Library
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
  
}

void loop() {
 // Turn off the blinking cursor:
  lcd.noBlink();
  delay(3000);
  // Turn on the blinking cursor:
  lcd.blink();
  delay(3000);
}
