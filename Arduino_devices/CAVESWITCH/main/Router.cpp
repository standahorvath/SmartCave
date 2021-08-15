 /*
  Router.h - Object for routing UDP requests
*/
#include "Router.h"
#include "StrUtils.h"
#include "Device.h"

#ifdef SMARTSWITCH
  #include "Smartswitch.h"
#endif

Router::Router() {

}

/* Inicializační funkce */
void Router::init(){

  #ifdef SMARTSWITCH
    _ss = new Smartswitch("PC_01");
    _ss->init();
  #endif
  
}
/* 
 *  Router request process
 *  Request examples:
 *  SMARTSWITCH|SHOT|PC_SWITCH|ON
 *  SMARTSWITCH|PERMANENT|LIGHT_SWITCH|ON
 */
void Router::process(char * request){
  
  int count_commands = char_count_in_string(request, '|') + 1;
  int request_length = get_string_count(request);
  char * router_object = NULL;
  char * router_function = NULL;
  char * router_device_name = NULL;
  char * router_parameter = NULL;
  int lenth_first_word = 0;
  int lenth_second_word = 0;
  int lenth_third_word = 0;
  int lenth_fourth_word = 0;
  

  if(count_commands > 0) {
    lenth_first_word = get_position_of_char(request, '|', 0);
    if(lenth_first_word == 0) lenth_first_word = request_length;
    router_object = copy_str(request, 0, lenth_first_word);
  }

  if(count_commands > 1) {
    lenth_second_word = get_position_of_char(request, '|', 1);
    if(lenth_second_word == 0) {
      lenth_second_word = request_length;
    }
    router_function = copy_str(request, lenth_first_word + 1,  lenth_second_word - lenth_first_word - 1);
  }

  if(count_commands > 2) {
    lenth_third_word = get_position_of_char(request, '|', 2);
    if(lenth_third_word == 0) {
      lenth_third_word = (lenth_first_word + lenth_second_word + 2);
    }
    router_device_name = copy_str(request, lenth_second_word + 1, lenth_third_word - lenth_second_word - 1);
    
    
  }

  if(count_commands > 3) {
    lenth_fourth_word = get_position_of_char(request, '|', 3);
    if(lenth_fourth_word == 0) {
      lenth_fourth_word = (lenth_first_word + lenth_second_word + lenth_third_word + 3);
    }

    router_parameter = copy_str(request, lenth_third_word + 1, lenth_fourth_word);
  }

  #ifdef DEBUG
  
    Serial.print("\n Command count: ");
    Serial.print(count_commands);
    
    if(router_object != NULL) {
      Serial.print("\n Router object: ");
      Serial.print(router_object);
    }
  
    if(router_function != NULL) {
      Serial.print("\n Function: ");
      Serial.print(router_function);
    }
  
    if(router_device_name != NULL) {
      Serial.print("\n Device name: ");
      Serial.print(router_device_name);
    }
  
    if(router_parameter != NULL) {
      Serial.print("\n Parameter: ");
      Serial.print(router_parameter);
    }

  #endif

    #ifdef SMARTSWITCH
      if(router_device_name != NULL && _ss->isNamedBy(router_device_name)){
        _ss->processRoute(router_function, router_parameter);
      }
    #endif


  if(router_object != NULL) {
    free(router_object);
  }
  if(router_function != NULL) {
    free(router_function);
  }
  if(router_device_name != NULL) {
    free(router_device_name);
  }
  if(router_parameter != NULL) {
    free(router_parameter);
  }
  
  
}
