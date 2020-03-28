#define E1 5 // Enable Pin for motor
#define I1 3 // Control pin 1 for motor 
#define I2 4 // Control pin 2 for motor 

int i;
 
void setup() {
  //---set pin direction
  pinMode(E1,OUTPUT);
  pinMode(I1,OUTPUT);
  pinMode(I2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
 
//---back and forth example
    Serial.println("One way, then reverse");
    digitalWrite(E1,HIGH); // enable on
    for (i=0;i<5;i++) {
    digitalWrite(I1,HIGH); //one way
    digitalWrite(I2,LOW);
    delay(1000);
    digitalWrite(I1,LOW);  //reverse
    digitalWrite(I2,HIGH);
    delay(1000);
  }
  digitalWrite(E1,LOW); // disable
    delay(3000);
      for (i=0;i<5;i++) {
    digitalWrite(I1,HIGH); //one way
    digitalWrite(I2,LOW);
    delay(1000);
    digitalWrite(I1,LOW);  //reverse
    digitalWrite(I2,HIGH);
    delay(1000);
  }
    digitalWrite(E1,LOW); // disable
    delay(3000);
}
   
