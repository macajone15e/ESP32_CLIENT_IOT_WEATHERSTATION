#include <Arduino.h>
#include <SensorsManager.hpp>
#include <BMP280Controller.hpp>
#include "../../include/config.hpp"

void setupSensors() {
  setupBMP280();
}

void loopSensors() {
  loopBMP280();
}