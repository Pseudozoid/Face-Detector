#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

void setup() {
  lcd_1.begin(16, 2);
  lcd_1.setBacklight(1);
  Serial.begin(9600);
  lcd_1.print("Waiting...");
}

void loop() {
  if (Serial.available()) {
    String message = Serial.readStringUntil('\n');
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print(message);
  }
}
