#include "LedControl.h" //  need the library
#include <LiquidCrystal.h>
LedControl lc = LedControl(12, 11, 10, 1);
LiquidCrystal lcd(2,3,4,5,6,7);
#define V0_PIN 9


byte next[8] = {
  B00000000,
  B00000000,
  B00000001,
  B00000010,
  B01000100,
  B00101000,
  B00010000,
  B00000000,
};

byte up[8] = {
  B00011000,
  B00111100,
  B01011010,
  B10011001,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
};

byte down[8] = {
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B10011001,
  B01011010,
  B00111100,
  B00011000,
};

byte right[8] = {
  B00010000,
  B00001000,
  B00000100,
  B11111111,
  B11111111,
  B00000100,
  B00001000,
  B00010000,
};

byte left[8] = {
  B00010000,
  B00100000,
  B01000000,
  B11111111,
  B11111111,
  B01000000,
  B00100000,
  B00010000,
};

const int joyX =  A1;
const int joyY = A0;
int valX, valY;
int count = 0;
int lives = 3; 
void levelOne(){
  for (int i = 0; i< 8; i++){
    lc.setRow(0, i, up[i]);
  if (valX > 600) 
    count++;
    else lives--;
    delay(300);
  }
  
  for (int i = 0; i< 8; i++){
    lc.setRow(0, i, down[i]);
  if (valX < 300) 
    count++;
    else lives--;
    delay(300);
  }
  for (int i = 0; i< 8; i++){
    lc.setRow(0, i, left[i]);
  if (valY <300) 
    count++;
    else lives--;
    delay(300);
  }
  
  for (int i = 0; i< 8; i++){
    lc.setRow(0, i, right[i]);
  if (valX > 600) 
    count++;
    else lives--;
    delay(300); 
  }
  if (lives>0)
     lcd.print("Level up!");
  
}
void setup() {
  lc.shutdown(0, false); 
  lc.setIntensity(0, 2); 
  lc.clearDisplay(0);
  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
  Serial.begin(9600);
  pinMode(V0_PIN, OUTPUT);
  analogWrite(V0_PIN, 110);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(1,1);


}

void loop() {
  valX = analogRead(joyX);
  valY = analogRead(joyY);
  levelOne();
  lc.clearDisplay(0);
}
