#pragma once
#include <Arduino.h>

// ESP ID 
extern String mqttClientId;

// Setup 
void setupMQTT();

// Init MQTT connection
void mqttConnect();

// Publish data to MQTT broker on a topic
void mqttPublish(const char* topic, const String &payload);

// Get the client id for MQTT connection
String getClientId();


