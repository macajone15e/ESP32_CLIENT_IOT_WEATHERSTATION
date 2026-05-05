#include <Arduino.h>
#include <config.hpp>
#include <WiFiManager.hpp>
#include <MQTTManager.hpp>
#include <NTPManager.hpp>
#include <I2CScanner.hpp>
#include <DisplayManager.hpp>
#include <SensorsManager.hpp>
#include <JSONSerializer.hpp>

void setup() {
  Serial.begin(115200);
  setupI2C();
  setupWiFi();
  setupMQTT();
  setupNTP();
  mqttConnect();
  setupMonitor();
  setupSensors();
  delay(5000);
  Serial.println("Starting...");
}

void loop() {
  loopWiFi();
  loopNTP();
  loopMQTT();
  loopSensors();

  if(isSensorsChange){
    mqttPublish("Sensors", generateJson(getClientId(), getTimestamp(), temperature, altitude, pressure));
    displayData(getFormattedTime(), temperature, pressure, altitude, false);
    isSensorsChange = false;
  }
}