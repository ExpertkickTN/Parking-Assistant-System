#include <Wire.h>
#include <LiquidCrystal.h> 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distancem;
void setup() {
  lcd.begin(16, 2); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
byte Bell[] = {
  B00100,
  B01110,
  B01110,
  B01110,
  B11111,
  B00000,
  B00100,
  B00000
};

void loop() {
  lcd.createChar(1, Bell);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distancem = duration * 0.034 / 2 / 100;
  
  lcd.clear(); 
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distancem);
  lcd.print(" m");

  if (distancem < 0.5) {
    lcd.setCursor(0, 1);
    lcd.print("STOP Be careful");
    lcd.write(byte(1));
  }

  delay(10);
}
