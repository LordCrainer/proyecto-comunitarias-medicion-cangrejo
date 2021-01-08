struct ITextLCD {
    byte color;
    byte size;
};

struct ICursorLCD {
    int x;
    int y;
};

struct IConfigLCD {
    ICursorLCD cursor;
    ITextLCD text;
};