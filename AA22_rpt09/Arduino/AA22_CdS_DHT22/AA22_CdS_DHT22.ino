#include "DHT.h"

#define CDS_INPUT 1
#define DHT22_INPUT 2

#define DHTTYPE DHT22

DHT dht(DHT22_INPUT, DHTTYPE);

void setup() {
  Serial.begin(9600);

  dht.begin();
}

void loop() {
  int cds_value = analogRead(CDS_INPUT);
  int lux = int(luminosity(cds_value));
  
  float temp = dht.readTemperature();
  float humid = dht.readHumidity();
  
  if( isnan(lux) || isnan(temp) || isnan(humid) ) {
    Serial.println("Fail to read from DHT");
  } else {
    Serial.print(temp);
    Serial.print(',');
    
    Serial.print(lux);
    Serial.print(',');
    
    Serial.println(humid);
  }
  delay(500);
}

double luminosity (int RawADC0){
  double Vout=RawADC0*5.0/1023.0;
  double lux=(2500/Vout-500)/10.0;  
  
  return lux;
}
