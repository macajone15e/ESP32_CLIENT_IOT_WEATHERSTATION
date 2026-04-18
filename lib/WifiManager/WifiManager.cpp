#include <Arduino.h>
#include "WiFiManager.hpp"
#include <WiFiManager.h>

WiFiManager WIFI;

void setupWiFi() {
  WiFi.mode(WIFI_STA);
  bool isWifiOk = false;
  uint8_t max_attemps = 3;
  Serial.println("WiFi: try to connect to saved network or start configuration portal");
  while (!isWifiOk && max_attemps > 0) {
    if (WIFI.autoConnect("ESP32_Weather_Station_Portal")) {
      Serial.println("WiFi: Connection established");
      isWifiOk = true;
    } else {
      max_attemps--;
      if (max_attemps == 0)
        Serial.println("WiFi: configuration portal running");
    }
  }
}

void loopWiFi() {
  WIFI.process();
}

String getMacAddress() {
  String temp = WiFi.macAddress();
  temp.replace(":", "");
  return temp;
}