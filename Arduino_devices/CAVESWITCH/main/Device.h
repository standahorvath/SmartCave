 /*
  Wifi.h - Wfi driver object
*/
#ifndef DEVICE_h
#define DEVICE_h
#include "Arduino.h"
#include "Config.h"
#include "Router.h"
#include <ESP8266WiFi.h>
#include <WiFiUDP.h>

#ifdef SMARTSWITCH
  #include "Smartswitch.h"
#endif


class Device
{
  public:
    Device(const char * name);

    virtual void processRoute(char * function, char * param) = 0;
    void init();
    const char * device_name;
  private:
};

#endif
