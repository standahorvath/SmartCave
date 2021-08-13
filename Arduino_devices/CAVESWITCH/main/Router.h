 /*
  Router.h - Object for routing UDP requests 
*/
#ifndef GYROSCOPE_h
#define GYROSCOPE_h
#include "Arduino.h"

class Router
{
  public:
    Router();
    void init();
    void process(char * request);
  private:
};

#endif
