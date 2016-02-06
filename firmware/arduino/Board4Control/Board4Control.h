// This library controls the functions of 4Control Board
//  - 
//  - 
//  - 

// Written by Fabio Souza
//
//
// Change History:
// 25 Octuber 2015       Initial Version
// 01 November 2015 	 mux pins on LCD library

#ifndef BOARD4CONTROL_H
#define BOARD4CONTROL_H

#include <Arduino.h>
#include "Board4Control_LCD.h"


// Defines

//define pins of 4Control Board
#define LED_PIN 13
#define BUZZER_PIN A3
#define BKLT_PIN  11
#define RS_PIN   A4
#define E_PIN  A5
#define DB4_PIN  7
#define DB5_PIN 4
#define DB6_PIN 12
#define DB7_PIN 8
#define SW1_PIN A4
#define SW2_PIN 8
#define SW3_PIN 12
#define SW4_PIN 4
#define SW5_PIN 7


//constants
#define BUZZERPASSIVE   // using passsive buzzer with tone() funcion
#define NOPRESS 0
#define PRESS 1

class Board4Control
{
	public:
		Board4Control();
		void begin();
		void beep(int time);
		byte readButton(byte bt);

	private:
	
};

extern Board4Control b4Control;

#endif // BOARD4CONTROL_H