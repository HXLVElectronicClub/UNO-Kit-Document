

int lightPin = 0; //Pin to pin AO on the Arduino
int latchPin = 11;//Pin 12 (RCLK) of the shift register to pin 11 on the Arduino – this will be referred to as the “latch pin”
int clockPin = 9;//Pin 11 (SRCLK) of the shift register to pin 9 on the Arduino – this will be referred to as the “clock pin”
int dataPin = 12;//Pin 12 (SER) of the shift register to pin 2 on the Arduino – this will be referred to as the “data pin”

int leds = 0;

void setup() 
{
  //The 'setup' function just sets the three pins we are using to be digital outputs.
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}
void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
//divide the raw reading by 57 rather than 114. In other words, we divideit by half as much as we did with the pot to split it into nine zones, from no LEDs lit to all eight lit.
//This extra factor is to account for the fixed 1 kΩ resistor. This means that when the photocell has a resistance of 1 kΩ (the same as the fixed resistor), the raw reading will be 1023 / 2 = 511. This will equate to all the LEDs being lit and then a bit (numLEDSLit) will be 8.
void loop() 
{
  int reading  = analogRead(lightPin);
  int numLEDSLit = reading / 57;  //1023 / 9 / 2
  if (numLEDSLit > 8) numLEDSLit = 8;
  leds = 0;   // no LEDs lit to start
  for (int i = 0; i < numLEDSLit; i++)
  {
    leds = leds + (1 << i);  // sets the i'th bit
  }
  updateShiftRegister();
}


