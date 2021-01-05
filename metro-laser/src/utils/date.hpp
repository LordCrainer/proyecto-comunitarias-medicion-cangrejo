void setDS3231time(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year)
{
  // sets time and date data to DS3231
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0);                    // set next input to start at the seconds register
  Wire.write(decToBcd(second));     // set seconds
  Wire.write(decToBcd(minute));     // set minutes
  Wire.write(decToBcd(hour));       // set hours
  Wire.write(decToBcd(dayOfWeek));  // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
  Wire.write(decToBcd(month));      // set month
  Wire.write(decToBcd(year));       // set year (0 to 99)
  Wire.endTransmission();
}

struct Date
{
  byte second;
  byte minute;
  byte hour;
  byte dayOfWeek;
  byte dayOfMonth;
  byte month; 
  byte year;
};

Date tiempo;

void readDS3231time(byte *second,
                    byte *minute,
                    byte *hour,
                    byte *dayOfWeek,
                    byte *dayOfMonth,
                    byte *month,
                    byte *year)
{
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set DS3231 register pointer to 00h
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  // request seven bytes of data from DS3231 starting from register 00h
  *second = bcdToDec(Wire.read() & 0x7f);
  *minute = bcdToDec(Wire.read());
  *hour = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month = bcdToDec(Wire.read());
  *year = bcdToDec(Wire.read());
}

/*      myFile.print("Tiempo(ms)="); //Escribir los datos en el archivo creado en la SD
      myFile.print(millis());
      myFile.print(", MEDIDA [cm]=");
      myFile.print(distance);
      myFile.print(" cm ");
      myFile.print("Fecha y hora: ");
      myFile.print(dayOfMonth, DEC);
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
      Serial.print(dayOfMonth, DEC);
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