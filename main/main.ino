#include "wifi_setup.h"
#include "devices.h"

void setup() {
  Serial.begin(115200);

  // Initialize devices
  initDevices();

  // Start Wi-Fi + WebServer
  initWiFi();
}

void loop() {
  // Async server doesn’t need loop() handling
}
