#pragma once
#include <Arduino.h>
#include <Adafruit_SSD1306.h>

extern Adafruit_SSD1306 display;


void setupMonitor();

void displayData(String date, float temperature, float humidity, float altitude, bool carbonMonoxide);