 /*
  Discover.h
*/
#include "Discover.h"
#include "Device.h"
#include "string.h"
#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <WiFiUDP.h>

Discover::Discover(const char * name,WiFiUDP udp) {
  Discover::device_name = name;
  Discover::_udp = udp;
}

/* Initialize function */
void Discover::init(){
}

void Discover::processRoute(char * function) {
  if(function != NULL){
    if(strcmp(function, "DEVICE") == 0) {
      Device();
    }
  }
}

int Discover::isNamedBy(char * name) {
  if(strcmp(name, device_name) == 0) {
    return 1; 
  } else {
    return 0;
  }
}

void Discover::Device(){
    _udp.beginPacket(BROADCAST_IP, UDP_PORT);
    _udp.write("INFO|");
    _udp.write(device_name);
    _udp.endPacket();
}
