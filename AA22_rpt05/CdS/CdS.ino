#define CDS_INPUT 0 

const int ledPin = 13;
int threshold = 70;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(CDS_INPUT);
  int lux = int(luminosity(value));
  Serial.println(lux);

  if (lux >= threshold)
    digitalWrite(ledPin, LOW);
  else
    digitalWrite(ledPin, HIGH);
  
  delay(1000);
}

double luminosity(int RawADC0){
  double Yout = RawADC0 * 5.0 / 1023;
  double lux = (2500 / Yout - 500) / 10;

  return lux;
}
