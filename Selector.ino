/*
  Selector
 
  The circuit:
  LCD
 * LCD RS pin to digital pin 20
 * LCD Enable pin to digital pin 13
 * LCD D4 pin to digital pin 8
 * LCD D5 pin to digital pin 9
 * LCD D6 pin to digital pin 10
 * LCD D7 pin to digital pin 11
 * LCD R/W pin to digital pin 12
 SELECTOR
 
 */

// include the library code:
#include <LiquidCrystal.h>
#include <Wire.h>
#include <Adafruit_MCP23008.h>
#include "AnalogSelector.h"
//#include "WM8805.h"
#include <IRremote.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(20, 12, 13, 8, 9, 10, 11);
int lcd_backlight = A2;

// IR control
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);
selector::AnalogSelector analog_selector;

const int buttonPin = 2; 
int buttonState = 0;

void setup() {
  pinMode(lcd_backlight, OUTPUT);  
  digitalWrite(lcd_backlight, HIGH);
  // set up the LCD's number of columns and rows: 
  lcd.begin(20, 4);
  // Print a message to the LCD.
  lcd.print("hello, world! ;)");
  //selector
   analog_selector.setup();
   //button
  pinMode(buttonPin, INPUT);  
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis()/1000);

  lcd.setCursor(0, 2);
  lcd.print(analog_selector.selected_input);

  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
  lcd.setCursor(0, 3);
  lcd.print("BUTTON!");
    int next_input = analog_selector.selected_input + 1;
    if(next_input == 4){
      next_input = 0;
    }
    analog_selector.select(next_input);
    delay(1000);
  }
}

