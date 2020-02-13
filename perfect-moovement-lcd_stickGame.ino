#include <LiquidCrystal.h>
//ci dessou les pin relies aux pin du lcd
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};
byte armsRight[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00101,
  0b01110,
  0b10100,
  0b00100,
  0b01010
};
byte armsLeft[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10100,
  0b01110,
  0b00101,
  0b00100,
  0b01010
};

int Xpos=0;
int Ypos=1;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  lcd.createChar(0, armsDown);
  lcd.createChar(1, armsUp);
  lcd.createChar(2, armsRight);
  lcd.createChar(3, armsLeft);
}

void loop(){
  lcd.setCursor(Xpos,Ypos);
  lcd.write((byte)0);
  
  if(Xpos>15){
    Xpos=0;
  }
  if(Xpos<0){
    Xpos=15;
  }
  
  if(digitalRead(A0)){
    lcd.write((byte)2);
    Xpos++;
    delay(50);
  }
  if(digitalRead(A1)){
    Xpos--;
    lcd.setCursor(Xpos,Ypos);
    lcd.write((byte)3);
    delay(50);
  }
  if(digitalRead(A4)){
    Ypos=1;
  }
  if(digitalRead(A5)){
    Ypos=0;
    lcd.setCursor(Xpos,Ypos);
    lcd.write((byte)1);
    delay(100);
  }
  delay(100);
  lcd.clear();
}
