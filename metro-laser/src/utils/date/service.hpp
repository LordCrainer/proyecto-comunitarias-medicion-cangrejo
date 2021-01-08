#include "./interface.hpp"

void setDS3231time(Date tiempo)
{
  // sets time and date data to DS3231
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0);                    // set next input to start at the seconds register
  Wire.write(decToBcd(tiempo.second));     // set seconds
  Wire.write(decToBcd(tiempo.minute));     // set minutes
  Wire.write(decToBcd(tiempo.hour));       // set hours
  Wire.write(decToBcd(tiempo.dayOfWeek));  // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(tiempo.day)); // set date (1 to 31)
  Wire.write(decToBcd(tiempo.month));      // set month
  Wire.write(decToBcd(tiempo.year));       // set year (0 to 99)
  Wire.endTransmission();
}



Date readDS3231time()
{
  Date tiempo;
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set DS3231 register pointer to 00h
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  // request seven bytes of data from DS3231 starting from register 00h
  tiempo.second = bcdToDec(Wire.read() & 0x7f);
  tiempo.minute = bcdToDec(Wire.read());
  tiempo.hour = bcdToDec(Wire.read() & 0x3f);
  tiempo.dayOfWeek = bcdToDec(Wire.read());
  tiempo.day = bcdToDec(Wire.read());
  tiempo.month = bcdToDec(Wire.read());
  tiempo.year = bcdToDec(Wire.read());
  return tiempo;
}

/*      myFile.print("Tiempo(ms)="); //Escribir los datos en el archivo creado en la SD
      myFile.print(millis());
      myFile.print(", MEDIDA [cm]=");
      myFile.print(distance);
      myFile.print(" cm ");
      myFile.print("Fecha y hora: ");
      myFile.print(day, DEC);
      myFile.print("/");
      myFile.print(month, DEC);
      myFile.print("/");
      myFile.print(year, DEC);
      myFile.print(" ");
      myFile.print(hour, DEC);
      myFile.print(":");
      myFile.print(minute, DEC);
      myFile.print(":");
      myFile.println(second, DEC);*/

/* display.setCursor(0, 0);
      display.print("GUARDADO...      ");
      delay(2000);
      Serial.print(F("Tiempo(ms)="));
      Serial.print(millis());
      Serial.print(", MEDIDA [cm]=");
      Serial.print(distance);
      Serial.print(" cm ");
      Serial.print("Fecha y hora: ");
      Serial.print(day, DEC);
      Serial.print("/");
      Serial.print(month, DEC);
      Serial.print("/");
      Serial.print(year, DEC);
      Serial.print(" ");
      Serial.print(hour, DEC);
      Serial.print(":");
      Serial.print(minute, DEC);
      Serial.print(":");
      Serial.println(second, DEC);*/