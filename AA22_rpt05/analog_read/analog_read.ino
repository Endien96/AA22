/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Attach the center pin of a potentiometer to pin A0, 
  and the outside pins to +5V and ground.
*/

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.print("AA21, Present V : ");
  Serial.println(sensorValue * 5 / 1023.0);
  
  delay(500);        // 2 Hz sampling
}
