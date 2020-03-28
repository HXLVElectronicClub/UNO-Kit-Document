const int LedPin=8;//the led attach to
void setup() 
{ 
    pinMode(LedPin,OUTPUT);//initialize the LedPin as an output
} 
void loop() 
{ 
    int i;
    while(1) 
    { 
       i=analogRead(5);//Read the simulation 5 voltage value 
       if(i>1000)//If it's greater than 512 (2.5v)
       { 
          digitalWrite(LedPin,HIGH);//turn led on
       } 
       else
       { 
          digitalWrite(LedPin,LOW);//turn led off
       } 
    } 
} 

