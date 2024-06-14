#include <Arduino.h>

#define SENSOR_PIN 34
#define PUMPA_PIN 16

uint16_t sensorValue = 0;

void setup(){
  Serial.begin(9600);
  
  pinMode (SENSOR_PIN, INPUT);
  pinMode (PUMPA_PIN, OUTPUT);
  
  delay(1000);
}

void loop()
{
  sensorValue = analogRead(SENSOR_PIN);

  if (sensorValue < 819)
  {
    while (sensorValue < 1500) { 
      analogWrite(PUMPA_PIN,80);
      sensorValue = analogRead(SENSOR_PIN);
      delay(10);
      Serial.printf("Trenutna vlaznost je: %d i pumpa je ukljucena\n", sensorValue );
      delay(10);
    }
  }else
  {
    Serial.printf("Trenutna vlaznost je: %d i pumpa je ISKLJUCENA\n", sensorValue );
    analogWrite(PUMPA_PIN,0);
  }
  delay(100);
}
