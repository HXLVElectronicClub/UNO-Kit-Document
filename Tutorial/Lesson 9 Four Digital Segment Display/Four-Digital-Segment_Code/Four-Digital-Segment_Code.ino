int latch=9;  //74HC595  pin 9 STCP
int clock=10; //74HC595  pin 10 SHCP
int data=8;   //74HC595  pin 8 DS
//Refer Table 7-Segment Decoding
unsigned char table[]=
{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c
,0x39,0x5e,0x79,0x71,0x00};
//initialize the digital pin  as an outout
void setup() {
  pinMode(latch,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(data,OUTPUT);
}
//Latch the data
void Display(unsigned char num)
{
  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,table[num]);
  digitalWrite(latch,HIGH);  
}
void loop() {
  Display(1);
  delay(2000);//delay 2 sencond
  Display(2);
  delay(2000);//delay 2 sencond
  Display(3);
  delay(2000);//delay 2 sencond
  Display(4);
  delay(2000);//delay 2 sencond
  Display(5);
  delay(2000);//delay 2 sencond
  Display(6);
  delay(2000);//delay 2 sencond
  Display(7);
  delay(2000);//delay 2 sencond
  Display(8);
  delay(2000);//delay 2 sencond
  Display(9);
  delay(2000);//delay 2 sencond
  Display(10);
  delay(2000);//delay 2 sencond
  Display(11);
  delay(2000);//delay 2 sencond
  Display(12);
  delay(2000);//delay 2 sencond
  Display(13);
  delay(2000);//delay 2 sencond
  Display(14);
  delay(2000);//delay 2 sencond
  Display(15);
  delay(2000);//delay 2 sencond
}
