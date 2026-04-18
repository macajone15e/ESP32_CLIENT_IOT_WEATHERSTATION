#include <Arduino.h>
#include "config.hpp"
#include "WiFiManager.hpp"

void setup() {
  Serial.begin(115200);
  setupWiFi();
  delay(5000);
  Serial.println("Starting...");
}

void loop() {
  loopWiFi();
}
