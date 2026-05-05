#pragma once
#include <Arduino.h>

// Function to setup the wifi part if wifi isn't connected it create the network to link a wifi network
void setupWiFi();

// Function to run in a loop the wifi process
void loopWiFi();

// Function to get the ESP32 MacAddress
String getMacAddress();

