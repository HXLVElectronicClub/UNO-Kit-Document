
// define the LED digit patterns, from 0 - 13
// 1 = LED on, 0 = LED off, in this order:
//74HC595 pin     Q0,Q1,Q2,Q3,Q4,Q5,Q6,Q7 
byte seven_seg_digits[14] = { 
  B01111010,  // = D
  B10011100,  // = C
  B00111110,  // = B
  B11101110,  // = A
  B11100110,  // = 9
  B11111110,  // = 8
  B11100000,  // = 7
  B10111110,  // = 6
  B10110110,  // = 5
  B01100110,  // = 4
  B11110010,  // = 3
  B11011010,  // = 2
  B01100000,  // = 1
  B11111100,  // = 0
                                                  
 };
 
// connect to the ST_CP of 74HC595 (pin 9,latch pin)
int latchPin = 9;
// connect to the SH_CP of 74HC595 (pin 10, clock pin)
int clockPin = 10;
// connect to the DS of 74HC595 (pin 8)
int dataPin = 8;
 
void setup() {
  // Set latchPin, clockPin, dataPin as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
 
// display a number on the digital segment display
void sevenSegWrite(byte digit) {
  // set the latchPin to low potential, before sending data
  digitalWrite(latchPin, LOW);
     
  // the original data (bit pattern)
  shiftOut(dataPin, clockPin, LSBFIRST, seven_seg_digits[digit]);  
 
  // set the latchPin to high potential, after sending data
  digitalWrite(latchPin, HIGH);
}
 
void loop() {       
  // count from 14 to 0
  for (byte digit = 14; digit > 0; --digit) {
    delay(1000);
    sevenSegWrite(digit - 1); 
  }
   
  // suspend 4 seconds
  delay(5000);
}
