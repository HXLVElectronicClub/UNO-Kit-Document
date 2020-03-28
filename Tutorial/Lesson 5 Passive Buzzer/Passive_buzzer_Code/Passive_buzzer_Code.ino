//The purpose of the experiment is to generate eight different sounds, each sound
lasting 0.5 seconds: from Alto Do (262Hz), Re (294Hz), Mi (330Hz), Fa (349Hz), So
(392Hz), La (440Hz), Si (494Hz) to Treble Do (524Hz).
int Do = 262, Re = 294 , Mi = 330 , Fa = 349 , Sol = 392 , 
    La = 440 , Si = 494, Do2 = 524;
int buzz = 12; //Not necessarily a PWM pin, any digital pin will work!!! 
int wait = 0;
void setup()
{
  pinMode(buzz, OUTPUT);//initialize the buzzer pin as an output
}
void loop()
{
  
  wait = 500;
  tone(buzz, Do, wait);
  delay(1000);//wait for 1s
  tone(buzz, Re, wait);
  delay(1000);//wait for 1s
  tone(buzz, Mi, wait);
  delay(1000);//wait for 1s
  tone(buzz, Fa, wait);   
  delay(1000);//wait for 1s
  tone(buzz, Sol, wait);
  delay(1000);//wait for 1s
  tone(buzz, La, wait);
  delay(1000);//wait for 1s
  tone(buzz, Si, wait);
  delay(1000);//wait for 1s
  tone(buzz, Do2, wait);
  delay(1000);//wait for 1s
  
        noTone(buzz);
}

