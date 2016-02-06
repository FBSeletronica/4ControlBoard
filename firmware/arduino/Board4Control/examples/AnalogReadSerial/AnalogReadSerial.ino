/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
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
    
   // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
   while (!Serial);

}

void loop() {
    
  int sensorValue = analogRead(A0); // read the input on analog pin 0:
  
  Serial.println(sensorValue);      // print out the value you read
  delay(500);                       // delay in between reads for stability


}
