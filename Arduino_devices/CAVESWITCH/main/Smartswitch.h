 /*
  Smartswitch.h
*/
#ifndef SMARTSWITCH_h
#define SMARTSWITCH_h
#include "Arduino.h"
#include "Config.h"
#include <ESP8266WiFi.h>
#include <WiFiUDP.h>
#include "Device.h"



class Smartswitch {
  public:
    Smartswitch(const char * name);
    void processRoute(char * function, char * param);
    int isNamedBy(char * name);
    void init();
    const char * device_name;
  private:
    void Shot(char * param);
    void Pernament(char * param);
    void setOutput();
    int outputState;
};

#endif
