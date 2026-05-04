#include <Arduino.h>
#include "../../include/config.hpp"
#include "NTPManager.hpp"
#include <WiFiUdp.h>
#include <WiFiManager.h>

extern const String NTP_SERVER_EU;
extern const String NTP_TIMEZONE_LOCATION;
extern const int NTP_REFRESH;
extern const int NTP_SYNC_TIMEOUT;


WiFiUDP ntpUDP;
Timezone timeZone;
bool ntpOk = false;

void setupNTP()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("NTP: No WiFi connected or WiFi not ready, skipping NTP setup");
    return;
  }
  setDebug(INFO);
  setServer(NTP_SERVER_EU);
  setInterval(NTP_REFRESH);
  waitForSync(NTP_SYNC_TIMEOUT);
  timeZone.setLocation(NTP_TIMEZONE_LOCATION);
  Serial.println("UTC:" + UTC.dateTime());
  Serial.println("Local time: " + timeZone.dateTime());
  ntpOk = true;
}

void loopNTP()
{
  if (!ntpOk)
  {
    setupNTP();
    if (!ntpOk)
      return;
  }
  events();
}

String getTimestamp()
{
  return timeZone.dateTime("YmdHis");
}