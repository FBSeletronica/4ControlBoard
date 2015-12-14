/*
  Blink
  Turns on an LED on for half second, then off for half second, repeatedly.

  This example shoe how initialize 4Control board usind Board4Control library.
  
  Created by: Fabio Souza
  change history:
           07/11/15 - first version
  
 */


#include <Board4Control.h>

void setup() {
  b4Control.begin();  // init pins(LED, buzzer, backlight) and lcd
}

void loop() {
  digitalWrite(LED_PIN,HIGH);  //set  pin 13 
  delay(500);                  //wait 500 ms
  digitalWrite(LED_PIN,LOW);   //clear pin 13
  delay(500);                  //wait 
}
