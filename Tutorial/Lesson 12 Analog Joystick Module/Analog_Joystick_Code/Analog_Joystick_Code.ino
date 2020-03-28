

// Arduino pin numbers
const int SW_pin = 3; // input for detecting whether the jotstick/button is pressed
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output

void setup() {
  pinMode(SW_pin, INPUT);      //setup SW input
  digitalWrite(SW_pin, HIGH);  //reading button state:1=not pressed,0=pressed
  Serial.begin(9600);          //Seput serical connection for print out to console
}
     //print out values
void loop() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
  delay(2000);
}
