 /*
  Wifi.h - Wfi driver object
*/
#include "Device.h"

#ifdef SMARTSWITCH
  #include "Smartswitch.h"
#endif

Device::Device(const char * name) {
  device_name = name;
}

/* Initialize function */
void Device::init(){
  
}
