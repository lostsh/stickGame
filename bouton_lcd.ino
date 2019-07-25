#include <LiquidCrystal.h>
//ci dessou les pin relies aux pin du lcd
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop(){
  Serial.println(analogRead(A0));
  lcd.setCursor(0,0);
  if(analogRead(A0)==1023){
    lcd.print("Droite");
    delay(150);
  }
  if(analogRead(A1)==1023){
    lcd.print("Gauche");
    delay(150);
  }
  if(analogRead(A4)==1023){
    lcd.print("Bas");
    delay(150);
  }
  if(analogRead(A5)==1023){
    lcd.print("Haut");
    delay(150);
  }
  lcd.clear();
}
