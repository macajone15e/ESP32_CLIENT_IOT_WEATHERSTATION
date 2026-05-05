#include <Arduino.h>
#include <SensorsManager.hpp>
#include <BMP280Controller.hpp>
#include "../../include/config.hpp"
#include <I2CScanner.hpp>

void setupSensors() {
  if(DebugMode) {
    scanI2C();
  }
  setupBMP280();
}

void loopSensors() {
  loopBMP280();
}