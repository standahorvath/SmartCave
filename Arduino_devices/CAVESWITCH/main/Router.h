 /*
  Router.h - Object for routing UDP requests 
*/
#ifndef GYROSCOPE_h
#define GYROSCOPE_h
#include "Arduino.h"
#include "StrUtils.h"
#include "Device.h"
#include "Config.h"
#include <WiFiUDP.h>

#ifdef SMARTSWITCH
  #include "Smartswitch.h"
#endif

#ifdef DISCOVER
  #include "Discover.h"
#endif

class Smartswitch;
class Discover;

class Router
{
  public:
    Router();
    void init(WiFiUDP udp);
    void process(char * request);
  private:

    #ifdef SMARTSWITCH
      Smartswitch * _ss;
    #endif

    #ifdef DISCOVER
      Discover * _d;
    #endif
};

#endif
