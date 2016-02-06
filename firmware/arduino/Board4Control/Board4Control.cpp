#include"Board4Control.h"

Board4Control::Board4Control(void)
{
   
}

void Board4Control::begin(){

 //config pins 
  pinMode(LED_PIN,OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BKLT_PIN, OUTPUT);
	
  //init lcd
   lcd.begin(16, 2);	
  
}

void Board4Control::beep(int time){
 #ifdef BUZZERPASSIVE
 tone(BUZZER_PIN,4400,time);
 #else
 digitalWrite(BUZZER_PIN,HIGH);
 delay(time);
 digitalWrite(BUZZER_PIN, LOW);
 #endif
 }
 
 byte Board4Control::readButton(byte bt){
	 return digitalRead(bt);
 }


Board4Control b4Control=Board4Control();