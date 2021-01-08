float accumAnalogRead(byte maxInteration, const uint8_t pin)
{
    float sum = 0;
    for (byte i = 0; i < maxInteration; i++)
    {
        sum += analogRead(pin);
    }
    return sum;
}