
#define E1 5 // Enable Pin for motor
#define I1 3 // Control pin 1 for motor 
#define I2 4 // Control pin 2 for motor 
 
void setup() {
 
    pinMode(E1, OUTPUT);
    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);
    
}
 
void loop() {
 
    analogWrite(E1, 153); // Run in half speed
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    delay(10000);
 
    // change direction
 
    digitalWrite(E1, LOW);
    delay(2000);
    
    analogWrite(E1, 255);  // Run in full speed
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    delay(10000);
}

