// Convert normal decimal numbers to binary coded decimal

byte decToBcd(byte val)
{
  return ((val / 10 * 16) + (val % 10));
}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return ((val / 16 * 10) + (val % 16));
}

float promBitToVolts(float bit, byte n)
{
  return bit / 16 * 0.0048828125;
}

float calculateDistance(float volts)
{
  return 13 * pow(volts, -1);
}