#pragma once
#include <Arduino.h>

// Debug 
const bool DebugMode = true;
// MQTT Configuration
const String mqttServer = "ADDRESS_IP";
const String mqttUser = "user";
const String mqttPassword = "password";
const int mqttPort = 1883;

// NTP Configuration
const String NTP_SERVER_EU = "europe.pool.ntp.org";
const String NTP_TIMEZONE_LOCATION = "Europe/Paris";
const int NTP_REFRESH = 3 * 60 * 60;
const int NTP_SYNC_TIMEOUT = 60;

// I2C Configuration
const int SDA_PIN = 8;
const int SCL_PIN = 9;

// MQ9 Configuration
const int MQ9_PIN = 36;

// BMP280 Configuration
const float tempTolerance = 0.1;
const int heartBeatTemp = 60;

// Display Configuration
const u_int8_t i2c_Address = 0x3C;
const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;
const int OLED_RESET = -1;