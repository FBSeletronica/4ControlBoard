/*
  readButtons
  This example shows how to read buttons presents on the 4ControlBoard   
  
  
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

boolean ST_SW1, ST_SW2, ST_SW3, ST_SW4, ST_SW5;  // flags

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
  
  delay(1000);                      //delay to display menssage
  
  //LCD message template
  lcd.setCursor(0, 0);
  lcd.print("4Control Buttons");
  lcd.setCursor(0, 1);
  lcd.print("                ");   
}

void loop() {
 
  if(b4Control.readButton(SW1_PIN)==LOW){    //if button is pressed
    if(ST_SW1 == NOPRESS){                   //is button wasn't pressed
      ST_SW1 = PRESS;                        //flag pressed
      b4Control.beep(100);                   //beep to indicate button pressed
      lcd.setCursor(0,1);                    //show button name
      lcd.print("SW1");                      
    }   
  }
  else{                                      //if button isn't pressed
    if(ST_SW1 == PRESS){                     //if was pressed
      ST_SW1 = NOPRESS;                      //flag not pressed
      lcd.setCursor(0,1);                    //clear button name
      lcd.print("   ");
    }
  }
  
  if(b4Control.readButton(SW2_PIN)==LOW){    //if button is pressed
    if(ST_SW2 == NOPRESS){                   //is button wasn't pressed
      ST_SW2 = PRESS;                        //flag pressed
      b4Control.beep(100);                   //beep to indicate button pressed
      lcd.setCursor(3,1);                    //show button name
      lcd.print("SW2");                      
    }   
  }
  else{                                      //if button isn't pressed
    if(ST_SW2 == PRESS){                     //if was pressed
      ST_SW2 = NOPRESS;                      //flag not pressed
      lcd.setCursor(3,1);                    //clear button name
      lcd.print("   ");
    }
  }
  
  if(b4Control.readButton(SW3_PIN)==LOW){    //if button is pressed
    if(ST_SW3 == NOPRESS){                   //is button wasn't pressed
      ST_SW3 = PRESS;                        //flag pressed
      b4Control.beep(100);                   //beep to indicate button pressed
      lcd.setCursor(6,1);                    //show button name
      lcd.print("SW3");                      
    }   
  }
  else{                                      //if button isn't pressed
    if(ST_SW3 == PRESS){                     //if was pressed
      ST_SW3 = NOPRESS;                      //flag not pressed
      lcd.setCursor(6,1);                    //clear button name
      lcd.print("   ");
    }
  }
  
  if(b4Control.readButton(SW4_PIN)==LOW){    //if button is pressed
    if(ST_SW4 == NOPRESS){                   //is button wasn't pressed
      ST_SW4 = PRESS;                        //flag pressed
      b4Control.beep(100);                   //beep to indicate button pressed
      lcd.setCursor(9,1);                    //show button name
      lcd.print("SW4");                      
    }   
  }
  else{                                      //if button isn't pressed
    if(ST_SW4 == PRESS){                     //if was pressed
      ST_SW4 = NOPRESS;                      //flag not pressed
      lcd.setCursor(9,1);                    //clear button name
      lcd.print("   ");
    }
  }

  
  if(b4Control.readButton(SW5_PIN)==LOW){    //if button is pressed
    if(ST_SW5 == NOPRESS){                   //is button wasn't pressed
      ST_SW5 = PRESS;                        //flag pressed
      b4Control.beep(100);                   //beep to indicate button pressed
      lcd.setCursor(12,1);                    //show button name
      lcd.print("SW5");                      
    }   
  }
  else{                                      //if button isn't pressed
    if(ST_SW5 == PRESS){                     //if was pressed
      ST_SW5 = NOPRESS;                      //flag not pressed
      lcd.setCursor(12,1);                    //clear button name
      lcd.print("   ");
    }
  }

}
