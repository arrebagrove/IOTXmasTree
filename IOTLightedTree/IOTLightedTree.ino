#include "Resources\Pin3.h"
#include "MKR1000ServerLib.h"

RESTServer myRESTfulServer(80);

String SSIDName = "Your SSID Name";
String WiFiPassword = "Your WiFi password";

void setup() {
  // put your setup code here, to run once:
  myRESTfulServer.addRESTResource(new Pin3());
  myRESTfulServer.start(SSIDName, WiFiPassword);
  String ipAddress = myRESTfulServer.getIPAddress();
  Serial.println(ipAddress);
}

void loop() {
  // put your main code here, to run repeatedly:
  myRESTfulServer.processRequest();
}
