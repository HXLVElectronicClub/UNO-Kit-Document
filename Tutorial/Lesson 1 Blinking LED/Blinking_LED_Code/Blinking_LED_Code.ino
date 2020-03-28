
int ledPin=8; //the pin of the LED
void setup()
{
    pinMode(ledPin,OUTPUT);//initialize digital pin LED_BUILTIN as an output.
}
void loop()
{  
    digitalWrite(ledPin,HIGH); //turn the LED on (HIGH is the voltage level)
    delay(1000); //wait for a second
    digitalWrite(ledPin,LOW); //turn the LED off by making the voltage LOW
    delay(1000); //wait for a second
} 
