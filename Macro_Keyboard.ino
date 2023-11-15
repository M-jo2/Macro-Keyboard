#include "Keyboard.h"

#define b0x0 7
#define b0x1 5
#define b0x2 10
#define b0x3 16
#define b1x0 6
#define b1x1 4
#define b1x2 9
#define b1x3 14
#define b2x0 3
#define b2x1 2
#define b2x2 8
#define b2x3 15

#define KEYBOARD_KEY 0
#define PRINT 1

int buttonPin[12] = {b0x0,b0x1,b0x2,b0x3,b1x0,b1x1,b1x2,b1x3,b2x0,b2x1,b2x2,b2x3};
int fonctionList[12] = {
  KEYBOARD_KEY,
  KEYBOARD_KEY,
  KEYBOARD_KEY,
  KEYBOARD_KEY,
  PRINT,
  KEYBOARD_KEY,
  KEYBOARD_KEY,
  KEYBOARD_KEY,
  PRINT,
  KEYBOARD_KEY,
  KEYBOARD_KEY,
  KEYBOARD_KEY
};
int ASCII[12] = {KEY_KP_0, KEY_KP_1, KEY_KP_2 ,KEY_KP_3 , 0,KEY_KP_4,KEY_KP_5,KEY_KP_6, 0,KEY_KP_7,KEY_KP_8,KEY_KP_9};
String printList[12];

bool buttonsState[12];
bool oldButtonsState[12];

void setup() {
  pinMode(b0x0, INPUT_PULLUP);
  pinMode(b0x1, INPUT_PULLUP);
  pinMode(b0x2, INPUT_PULLUP);
  pinMode(b0x3, INPUT_PULLUP);
  pinMode(b1x0, INPUT_PULLUP);
  pinMode(b1x1, INPUT_PULLUP);
  pinMode(b1x2, INPUT_PULLUP);
  pinMode(b1x3, INPUT_PULLUP);
  pinMode(b2x0, INPUT_PULLUP);
  pinMode(b2x1, INPUT_PULLUP);
  pinMode(b2x2, INPUT_PULLUP);
  pinMode(b2x3, INPUT_PULLUP);
  
  printList[4] = "Hello comment tu vas ajd ?";
  printList[8] = "B&em1m@phmau";

  Keyboard.begin();
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A3);
  
  for(int i=0; i<12 ; i++){
    oldButtonsState[i] = buttonsState[i];
    buttonsState[i] = digitalRead(buttonPin[i]);
    if(fonctionList[i] == KEYBOARD_KEY){
      if(buttonsState[i] && oldButtonsState[i] != buttonsState[i]){
          Keyboard.release(ASCII[i]);
        }else if (!buttonsState[i] && oldButtonsState[i] != buttonsState[i]){
          Keyboard.press(ASCII[i]);
        }
    }else if(fonctionList[i] == PRINT && !buttonsState[i] && oldButtonsState[i] != buttonsState[i]){
      Keyboard.print(printList[i]);
    }
  }

  delay(1);
}

