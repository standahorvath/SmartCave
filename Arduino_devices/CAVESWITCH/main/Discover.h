 /*
  Discover.h
*/
#ifndef Discover_h
#define Discover_h
#include "Arduino.h"
#include "Config.h"
#include <ESP8266WiFi.h>
#include <WiFiUDP.h>
#include "Device.h"



class Discover {
  public:
    Discover(const char * name, WiFiUDP udp);
    void processRoute(char * function);
    int isNamedBy(char * name);
    void init();
    const char * device_name;
  private:
    void Device();
    WiFiUDP _udp;
};

#endif
