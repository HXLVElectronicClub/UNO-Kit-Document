
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

//declare variables
float tempC;
float tempF;
int tempPin = 0;

void setup(){
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("Temp1=");
  lcd.setCursor(0, 1);
  lcd.print("Temp2=");
}

void loop(){
  tempC = analogRead(tempPin);           //read the value from the sensor
  tempC = (5.0 * tempC * 100.0)/1024.0;  //convert the analog data to temperature
  tempF = ((tempC*9)/5) + 32;            //convert celcius to farenheit

  // print result to lcd display
  lcd.setCursor(6, 0);
  lcd.print(tempC,1);
  lcd.print("'C");

  lcd.setCursor(6, 1);
  lcd.print(tempF,1);
  lcd.print("'F");

  // sleep...
  delay(1000);
}

