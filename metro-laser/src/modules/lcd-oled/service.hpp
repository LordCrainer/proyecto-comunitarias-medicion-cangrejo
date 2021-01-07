#include "./interface.hpp"

void displayTime(String data, int cursorX, int cursorY, int colorText)
{
    display.setCursor(70, 10);
    // retrieve data from DS3231
    Date tiempo = readDS3231time();
    // send it to the oled display
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

void setLCD(IConfigLCD config)
{
    display.setCursor(config.cursor.x, config.cursor.y);
    display.setTextColor(config.text.color);
    display.setTextSize(config.text.sizeText);
}

void printLCD(String data)
{
    display.print(data);
}

void clearLCD()
{
    display.clearDisplay();
}

void showLCD()
{
    display.display();
}

void displayOnLCD()
{
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
}