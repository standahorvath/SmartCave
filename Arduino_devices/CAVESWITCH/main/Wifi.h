 /*
  Wifi.h - Wfi driver object
*/
#ifndef WIFI_h
#define WIFI_h
#include "Arduino.h"
#include "Config.h"
#include "Router.h"
#include <ESP8266WiFi.h>
#include <WiFiUDP.h>


class Wifi
{
  public:
    Wifi();
    void init();
    void process();
    void listen_udp(Router * router);
  private:
  WiFiUDP _udp;
  char * _udp_buffer;
};

#endif
