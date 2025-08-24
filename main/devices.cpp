#include <Arduino.h>
#include "devices.h"


const int LED_PIN = 2;

void initDevices() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void ledOn() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED turned ON");
}

void ledOff() {
  digitalWrite(LED_PIN, LOW);
  Serial.println("LED turned OFF");
}
