#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// initialize lcd
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// keypad configuration
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {13, 12, 14, 27}; // connect to row
byte colPins[COLS] = {26, 25, 33, 32}; // connect to column

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(115200);
  lcd.init();                      
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Pocket Engineer");
  lcd.setCursor(0, 1);
  lcd.print("Ready!");
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    Serial.print("Pressed: ");
    Serial.println(key);
    lcd.setCursor(0, 1);
    lcd.print("Key: ");
    lcd.print(key);
    lcd.print("   ");
  }
}