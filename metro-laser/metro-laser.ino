#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <SD.h>
#include <SPI.h>

#include "env.h"

#include "./config/lcd.hpp"

#include "./src/modules/sd/service.hpp"
#include "./src/modules/lcd-oled/service.hpp"

#include "./src/utils/conversion.hpp"
#include "./src/utils/date/service.hpp"

// SENSOR
#define sensor A1 // Sharp IR GP2Y0A41SK0F (4-30cm, analog)

void setup()
{
  pinModeSD(SAVE_BOTON, INPUT);
  Wire.begin();
  Serial.begin(115200);
  Date dateTime;
  // DS3231 setea la hora y fecha
  dateTime.year = 20;
  dateTime.month = 1;
  dateTime.day = 7;
  dateTime.dayOfWeek=4;
  dateTime.hour = 0;
  dateTime.minute = 0;
  dateTime.second = 0;
  setDS3231time(dateTime); 
  // displayInitSD();

  /////////////////////////////////////////////////////////////////
  // setDS3231time();
  // readDS3231time();
}

void loop()
{
  Date tiempo = readDS3231time();
  float sum = 0;
  for (int i = 0; i < 16; i++)
  {
    sum += analogRead(sensor);
  }

  // 5v
  float volts = sum / 16 * 0.0048828125; // value from sensor * (5/1024)
  float distance = 13 * pow(volts, -1);  // worked out from datasheet graph

  //Almacenar los datos en la SD
  int val = digitalRead(SAVE_BOTON);
  // escribirSD();

  // displayTime();

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("METROLASER");
  display.setCursor(0, 30);
  display.print("Medida: ");
  display.print(distance, 2);
  display.print(" cm");
  delay(1000);

  //  Serial.print("Medida: "); Serial.print(distance,2); Serial.print(" cm");
  //  Serial.println();
  //  if ((distance) > 30.00 && (distance) < 3.00){
  //  Serial.println("Colocar bien la base");
  //  }
}
