#include <DHT.h>
#include <VARSTEP_ultrasonic.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define trigger_pin 4
#define echo_pin 3

DHT dht(DHTPIN, DHTTYPE);
VARSTEP_ultrasonic ultra(trigger_pin, echo_pin);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();
  float photo = analogRead(A0);
  float rotary = analogRead(A1);
  float distance = ultra.distance_cm();
  Serial.print(temp);
  Serial.print("-");
  Serial.print(humidity);
  Serial.print("-");
  Serial.print(photo);
  Serial.print("-");
  Serial.print(rotary);
  Serial.print("-");
  Serial.print(distance);
  Serial.print(",");
  delay(1000);
}
