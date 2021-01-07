// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)

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
  display.print(tiempo.day, DEC);
  display.print("/");
  display.print(tiempo.month, DEC);
  display.print("/");
  display.print(tiempo.year, DEC);
  display.println();
  display.display();
}