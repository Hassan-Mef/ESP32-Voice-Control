#include "commands.h"


// extern AsyncWebServer server;

// void handleCommands() {
//   String path = server.uri();  // e.g. /led/on
//   Serial.print("Received request: ");
//   Serial.println(path);

//   executeCommand(path);

//   server.send(200, "text/plain", "OK");
// }

// void executeCommands(String command) {
//   if (command == "/led/on") {
//     ledOn();
//   } else if (command == "/led/off") {
//     ledOff();
//   } else {
//     Serial.println("Unknown command");
//   }
// }