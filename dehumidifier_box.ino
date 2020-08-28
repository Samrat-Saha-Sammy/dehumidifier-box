/* 
 DeHumidifier Box
 By: Samrat Saha
 Date: August 28th, 2020
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

 Hardware Connections (Breakoutboard to Arduino):
 -VCC = 3.3V
 -GND = GND
 -SDA = A4 (use inline 330 ohm resistor if your board is 5V)
 -SCL = A5 (use inline 330 ohm resistor if your board is 5V)
 */
 
#include <Wire.h>
#include "SparkFunHTU21D.h"
#include <LiquidCrystal_I2C.h> // @todo Remove Later

HTU21D myHumidity;
LiquidCrystal_I2C lcd(0x27, 16, 2);  // @todo Remove Later

void setup() {
  Serial.begin(9600);

  myHumidity.begin();
  lcd.begin(); // @todo Remove Later
  lcd.backlight(); // @todo Remove Later
}

void loop() {
  float humd = myHumidity.readHumidity();
  float temp = myHumidity.readTemperature();

  Serial.print(" Temperature:");
  Serial.print(temp, 1);
  Serial.print("C");
  Serial.print(" Humidity:");
  Serial.print(humd, 1);
  Serial.print("%");

  lcd.print(temp); 
  lcd.print("°");

  lcd.setCursor(1, 0);
  lcd.print(humd); 
  lcd.print("%");
  
  Serial.println();
  delay(3000);
}
