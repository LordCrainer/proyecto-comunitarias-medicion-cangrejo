// FUNCIONES DE LA SD

void pinModeSD(uint8_t boton, uint8_t input)
{
  pinMode(boton, input);
}

boolean initSD(byte val)
{
  if (!SD.begin(10))
  { //Condicion por si falla la inicializacion de la tarjeta SD
    display.setCursor(0, 0);
    display.println("INSERTAR SD     ");
    delay(3000);
    Serial.println(F("No se pudo inicializar"));
    return true;
  }
  return false;
}

boolean displayInitSD(byte val)
{
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    // for (;;)
    //;
  }
  delay(2000);
  display.clearDisplay();
  return true;
}

boolean escribirSD(String data, String filename = "datalog.txt")
{
  File myFile;
  myFile = SD.open(filename, FILE_WRITE); //abrimos  el archivo
  if (myFile)
  {
    myFile.print(data);
    myFile.close(); // close the file
    delay(1000); // slow down serial port
    return true;
  }
  return false;
}