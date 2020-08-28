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

HTU21D myHumidity;

void setup() {
  Serial.begin(9600);
  Serial.println("HTU21D Example!");

  myHumidity.begin();
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

  Serial.println();
  delay(3000);
}
