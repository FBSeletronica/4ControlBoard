/*
  PWMout
  This example shows how to control two output form 0 to 100 % with PWM signal using the analogWrite() function.  
  
  
  This example also shows how initialize 4Control board using Board4Control library.
  
  
  It also explains how to use the Board4Control_LCD library
  The LCD display pins on 4Control board is multiplexed with the keys.
  A change was needed in the library of the official Arduino LCD to operate in 4Control board
  The Function b4Control.begin() initialize the pins on the LCD automatically
 
  
  Created by: Fabio Souza
  change history:
           06/02/16 - first version
  
 */


#include <Board4Control.h>

#define DELAY_UPDATE 10000
#define DELAY_PRESS  100

const byte PWM1_PIN = 6;
const byte PWM2_PIN = 9;

byte out1=0,out2=0;  //output percentage value
int SW1debounce,SW2debounce,SW3debounce,SW4debounce,SW5debounce;

void setup() {
  b4Control.begin();  // init pins(LED, buzzer, backlight) and lcd
  
  //init pwm pins
  pinMode(PWM1_PIN, OUTPUT);
  pinMode(PWM2_PIN, OUTPUT);
  
  //LCD config
  //LCD first message
  lcd.setBacklight(HIGH);      //turn on backlight
  
  //LCD message
  lcd.print("    4Control");
  lcd.setCursor(0, 1);
  lcd.print("     Board");
  
  //beep init
  b4Control.beep(300);              //beep 300 ms
  
  delay(1000);                      //delay to display menssage
  
  //LCD message template
  lcd.setCursor(0, 0);
  lcd.print("4Control PWM OUT");
  lcd.setCursor(0, 1);
  lcd.print("O1:000%  O2:000%");   
}

void loop() {
 
  if(b4Control.readButton(SW1_PIN)==LOW){    //if button is pressed
    SW1debounce--;
    if(SW1debounce==0){                     
      SW1debounce = DELAY_UPDATE;
      if(out1<100)out1++;                    //increment output1
      displayOutput(out1,3, 1);              //displays the output percentage
      updateOutput(out1, 1);                  // update pwm value
    }   
  }
  else{                                      //if button isn't pressed
      SW1debounce = DELAY_PRESS;
 }
  
  if(b4Control.readButton(SW2_PIN)==LOW){    //if button is pressed
    SW2debounce--;
    if(SW2debounce==0){  
      SW2debounce = DELAY_UPDATE;
      if(out1>0)out1--;                      //decrement output1  
      displayOutput(out1,3, 1);              //displays the output percentage 
      updateOutput(out1, 1);                  // update pwm value   
    }   
  }
  else{                                      //if button isn't pressed
     SW2debounce = DELAY_PRESS;
  }
  
  if(b4Control.readButton(SW3_PIN)==LOW){    //if button is pressed
    SW3debounce--;
    if(SW3debounce==0){  
      SW3debounce = DELAY_UPDATE;

    }   
  }
  else{                                      //if button isn't pressed
      SW3debounce = DELAY_PRESS;
  }
  
  if(b4Control.readButton(SW4_PIN)==LOW){    //if button is pressed
    SW4debounce--;
    if(SW4debounce==0){  
      SW4debounce = DELAY_UPDATE;
      if(out2<100)out2++;                    //increment output2
      displayOutput(out2,12, 1);              //displays the output percentage
      updateOutput(out2, 2);                  // update pwm value
    }   
  }
  else{                                      //if button isn't pressed
      SW4debounce = DELAY_PRESS;
  }

  
  if(b4Control.readButton(SW5_PIN)==LOW){    //if button is pressed
    SW5debounce--;
    if(SW5debounce==0){  
      SW5debounce = DELAY_UPDATE;
      if(out2>0)out2--;                //decrement output1   
      displayOutput(out2,12, 1);              //displays the output percentage
      updateOutput(out2, 2);                  // update pwm value
    }   
  }
  else{                                      //if button isn't pressed
      SW5debounce = DELAY_PRESS;
  }
}


void displayOutput(byte value,byte col, byte row){
  lcd.setCursor(col, row);
  lcd.print(value/100);
  lcd.print((value%100)/10);
  lcd.print(value%10); 
}

void updateOutput(byte value, byte output){
 
 int pwm = map(value, 0, 100, 0, 255); 
 
 if(output == 1){
   analogWrite(PWM1_PIN, pwm);
 }
 else if(output == 2){
   analogWrite(PWM2_PIN, pwm);
 }
  
}
