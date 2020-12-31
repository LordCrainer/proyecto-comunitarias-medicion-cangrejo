// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)

int val;
float distance = 0;

boolean displayOnLCD(byte positionX, byte positionY, String message)
{
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    { // Address 0x3C for 128x64
        Serial.println(F("SSD1306 allocation failed"));
        // for (;;)
        //;
    }
    //display

    delay(2000);
    display.clearDisplay();
    return true; 
}


void displayOnScreen(byte cursorX, byte cursoY, String message, byte textSize=1, byte color=1, )
{
    display.setTextSize(textSize);
    display.setTextColor(color);
    display.setCursor(0, 0);
    display.print(message);
}

void displayClear() {
    display.clearDisplay();
}

displayOnScreen(0, 30, "Medida" + disntace + " cm,", 2, WHITE);
displayClear();
displayOnScreen(0, 30, "Medida" + disntace + " cm", 2, WHITE);
