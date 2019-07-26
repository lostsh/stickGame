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

int Xpos=0;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  lcd.createChar(0, armsDown);
  lcd.createChar(1, armsUp);
}

void loop(){
  lcd.setCursor(7,0);
  if(digitalRead(A0)){
    lcd.write((byte)1);
    delay(150);
  }else{
    lcd.write((byte)0);
    delay(150);
  }
  lcd.clear();
}
