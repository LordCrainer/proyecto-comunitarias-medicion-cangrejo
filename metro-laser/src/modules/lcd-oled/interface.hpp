struct ITextLCD {
    byte color;
    byte sizeText;
};

struct ICursorLCD {
    int x;
    int y;
};

struct IConfigLCD {
    ICursorLCD cursor;
    ITextLCD text;
};