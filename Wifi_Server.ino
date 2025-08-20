#include <LittleFS.h>

#include <WiFi.h>         // ✅ must be included
#include <ESPAsyncWebServer.h>

const char* ssid     = "ASUS";
const char* password = "shadjee1978";

AsyncWebServer server(80);
const int ledPin = 5;

void handleRoutes() {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *req){
    req->send(200, "text/html",
      "<h1>ESP32 LED Control</h1>"
      "<button onclick=\"location.href='/on'\">ON</button>"
      "<button onclick=\"location.href='/off'\">OFF</button>");
  });

  server.on("/on", HTTP_GET, [](AsyncWebServerRequest *req){
    digitalWrite(ledPin, HIGH);
    req->send(200, "text/html", "<h1>LED is ON</h1><a href='/'>Go Back</a>");
  });

  server.on("/off", HTTP_GET, [](AsyncWebServerRequest *req){
    digitalWrite(ledPin, LOW);
    req->send(200, "text/html", "<h1>LED is OFF</h1><a href='/'>Go Back</a>");
  });
}

void onWiFiEvent(WiFiEvent_t event) {
  if (event == ARDUINO_EVENT_WIFI_STA_GOT_IP) {
    Serial.print("WiFi connected! IP: ");
    Serial.println(WiFi.localIP());
    handleRoutes();
    server.begin();                 // ✅ start server only after GOT_IP
    Serial.println("HTTP server started");
  } else if (event == ARDUINO_EVENT_WIFI_STA_DISCONNECTED) {
    Serial.println("WiFi lost connection, retrying…");
    WiFi.reconnect();
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.mode(WIFI_STA);
  WiFi.onEvent(onWiFiEvent);
  WiFi.begin(ssid, password);

  Serial.println("Connecting to WiFi…");
}

void loop() {
  // nothing; async + event-driven
}
