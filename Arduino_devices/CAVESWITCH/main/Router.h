 /*
  Router.h - Object for routing UDP requests 
*/
#ifndef GYROSCOPE_h
#define GYROSCOPE_h
#include "Arduino.h"
#include "StrUtils.h"
#include "Device.h"
#include "Config.h"

#ifdef SMARTSWITCH
  #include "Smartswitch.h"
#endif

class Smartswitch;

class Router
{
  public:
    Router();
    void init();
    void process(char * request);
  private:

    #ifdef SMARTSWITCH
      Smartswitch * _ss;
    #endif
};

#endif
