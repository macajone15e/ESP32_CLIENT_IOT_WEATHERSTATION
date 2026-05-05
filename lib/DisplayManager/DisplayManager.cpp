#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "../../include/config.hpp"
#include "DisplayManager.hpp"

extern const u_int8_t i2c_Address;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int OLED_RESET;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);;

void setupMonitor() {
    Wire.begin(SDA_PIN, SCL_PIN);

    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
        Serial.println(F("SSD1306 non trouvé !"));
        for(;;);
    }
    display.display();
    delay(2000);
    display.clearDisplay();
}

void displayData(String date, float temperature, float pressure, float altitude, bool carbonMonoxide) {

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 0);
    display.print(date);

    display.setCursor(0, 10);
    display.print("Temperature : "); 
    display.print(temperature, 1);
    display.println(" C");
        
    display.setCursor(0,30);
    display.print("Pressure : ");
    display.print(pressure, 1);
    display.println(" hPa");

    display.setCursor(0,40);
    display.print("Altitude : ");
    display.print(altitude, 1);
    display.println(" m");

    display.setCursor(0,50);
    display.print("Carbonmonoxide ? :");
    display.print(carbonMonoxide ? "Yes" : "NO");


    display.display();
  
}