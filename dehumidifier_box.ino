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
byte fill[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
}; // Fill Block
byte empty[] = {
  B00000,
  B00000,
  B00000,
  B00100,
  B00100,
  B00000,
  B00000,
  B00000
}; // Unfilled Block
int fanSpeed = 20;

void setup() {
  Serial.begin(9600);

  myHumidity.begin();
  lcd.begin(); // @todo Remove Later
  lcd.backlight(); // @todo Remove Later
  lcd.createChar(0, fill); 
  lcd.createChar(1, empty); 
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
  
  lcd.clear();

  lcd.print(temp); 
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(10,0); // Col / Row
  lcd.print(humd); 
  lcd.print("%");

  lcd.setCursor(0,1);
  for(int i=0; i< 16; i++) {
    
    lcd.setCursor(i,1);
    if(i < 5){
      lcd.write(0);
    } else {
      lcd.write(1);
    }
  }
  
  Serial.println();
  delay(3000);
}
