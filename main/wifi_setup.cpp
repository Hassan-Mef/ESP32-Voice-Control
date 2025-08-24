#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "wifi_setup.h"
#include "devices.h"

// WiFi credentials
const char* ssid = "ASUS";
const char* password = "shadjee1978";

AsyncWebServer server(80);

void onWiFiEventHandler(WiFiEvent_t event) {
    if (event == ARDUINO_EVENT_WIFI_STA_GOT_IP) {
        Serial.print("WiFi connected! IP: ");
        Serial.println(WiFi.localIP());

        // Setup routes
        server.on("/led/on", HTTP_GET, [](AsyncWebServerRequest *request){
            ledOn();
            request->send(200, "text/plain", "LED turned ON");
        });

        server.on("/led/off", HTTP_GET, [](AsyncWebServerRequest *request){
            ledOff();
            request->send(200, "text/plain", "LED turned OFF");
        });

        server.begin();
        Serial.println("HTTP server started");

    } else if (event == ARDUINO_EVENT_WIFI_STA_DISCONNECTED) {
        Serial.println("WiFi lost connection, retrying…");
        WiFi.reconnect();
    }
}

void initWiFi() {
    WiFi.mode(WIFI_STA);
    WiFi.onEvent(onWiFiEventHandler);
    WiFi.begin(ssid, password);
}
