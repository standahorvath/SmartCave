/* ========================================== */
/* SMARTCAVE Project                          */
/* Device: CAVESWITCH                         */
/* Description: This device listen to UDP and */
/*              switching on/off power output */
/* Version: 1.0                               */
/* ========================================== */

#include "Config.h"
#include "Wifi.h"
#include "Router.h"
#include "Device.h"

#ifdef SMARTSWITCH
  #include "Smartswitch.h"
#endif

Wifi   * wifi;
Router * router;


WiFiUDP udp_client;


void setup() {

  serialInit();
  
  wifi    = new Wifi();
  router  = new Router();

  wifi->init();
  router->init();
  
}

void loop() {
  
  wifi->listen_udp(router);
  
}

// Init Serial comunication
void serialInit(){
  // Serial comunication
  Serial.begin(9600);
}
