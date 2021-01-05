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

// PARTE DE CÓDIGO PARA LA FECHA Y HORA

#define sensor A1 // Sharp IR GP2Y0A41SK0F (4-30cm, analog)

void setup()
{
  pinModeSD(SAVE_BOTON, INPUT);
  Wire.begin();
  Serial.begin(115200);

  // set the initial time here:
  // DS3231 seconds, minutes, hours, day, date, month, year
  setDS3231time(30, 9, 0, 6, 18, 12, 20); //setea la hora y fecha 
  // displayInitSD();

  //CÓDIGO PARA SD
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Iniciando ..."); //Mensajes iniciales
  delay(3000);
  display.clearDisplay();
  Serial.print(F("Iniciando SD ..."));
  initSD();
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("SD lista        ");
  display.display();
  delay(5000);
  display.clearDisplay();
  Serial.println(F("inicializacion exitosa"));
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
  val = digitalRead(SAVE_BOTON);
  // escribirSD();

  displayTime();

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

// PARTE DE CÓDIGO PARA LA FECHA Y HORA
void displayTime()
{
  // retrieve data from DS3231
  Date tiempo = readDS3231time();
  // send it to the oled display
  display.setCursor(70, 10);
  display.print(tiempo.hour, DEC);
  // convert the byte variable to a decimal number when displayed
  display.print(":");
  if (tiempo.minute < 10)
  {
    display.print("0");
  }
  display.print(tiempo.minute, DEC);
  display.print(":");
  if (tiempo.second < 10)
  {
    display.print("0");
  }
  display.print(tiempo.second, DEC);

  display.setCursor(70, 0);
  display.print(tiempo.dayOfMonth, DEC);
  display.print("/");
  display.print(tiempo.month, DEC);
  display.print("/");
  display.print(tiempo.year, DEC);
  display.println();
  display.display();
}
//////////////////////////////////////////////////////////////////////////////////////
