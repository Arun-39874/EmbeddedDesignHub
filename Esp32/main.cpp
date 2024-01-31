#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "Redminote10s" // Add your network credentials
#define STAPSK  "arunkumar1"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;


void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//

void setup(){
  OTAsetup();
  pinMode(2,OUTPUT);

  //-------------------//
  // Custom setup code //
  //-------------------//
}

void loop() {
  OTAloop();
  int A0 = 0;
  int A1 = 1;
  int A2 = 1;
  int A3 = 0;
  if (A0 == 0 && A1 == 1 && A2 == 1 && A3 == 0) {
    digitalWrite(2, HIGH);
  }
  else {
    digitalWrite(2, LOW);

  }
  //-------------------//
  // Custom loop code  //
  //-------------------//
}