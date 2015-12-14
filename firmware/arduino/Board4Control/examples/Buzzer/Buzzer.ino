/*
  Buzzer
  Turns on a buzzer for 100 ms, then off for half second, repeatedly.

  This example show how initialize 4Control board usind Board4Control library and
  use beep funcion for buzzer
  
  Created by: Fabio Souza
  change history:
           07/11/15 - first version
  
 */

#include <Board4Control.h>

void setup() {
  b4Control.begin();  // init pins(LED, buzzer, backlight) and lcd
}

void loop() {
  b4Control.beep(100);         //turn on beep fo 100 ms
  delay(500);                  //wait 500 ms
}
