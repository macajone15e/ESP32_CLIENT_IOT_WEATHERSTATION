#pragma once
#include <ezTime.h>
extern Timezone timeZone;

// Function to setup NTP
void setupNTP();

// Function to loop NTP
void loopNTP();

// Functions to get the Timestamp to write it in the JSON or to display it on the screen
String getTimestamp();

String getFormattedTime();