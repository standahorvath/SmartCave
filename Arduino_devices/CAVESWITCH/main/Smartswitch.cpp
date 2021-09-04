 /*
  Smartswitch.h
*/
#include "Smartswitch.h"
#include "Device.h"
#include "string.h"
#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <WiFiUDP.h>

Smartswitch::Smartswitch(const char * name, WiFiUDP udp) {
  Smartswitch::device_name = name;
  Smartswitch::_udp = udp;
}

/* Initialize function */
void Smartswitch::init(){
  outputState = 0;
  pinMode(SMARTSWITCH_OUTPUT, OUTPUT);
  setOutput();
}

void Smartswitch::processRoute(char * function, char * param) {

  if(function != NULL){
    if(strcmp(function, "PERNAMENT") == 0) {
      Pernament(param);
    }
    if(strcmp(function, "SHOT") == 0) {
      Shot(param);
    }
  }

}

int Smartswitch::isNamedBy(char * name) {
  if(strcmp(name, device_name) == 0) {
    return 1; 
  } else {
    return 0;
  }
}
void Smartswitch::setOutput(){
  if(outputState == 1) {
      Serial.print("\n SETTING OUTPUT HIGH");
    digitalWrite(SMARTSWITCH_OUTPUT, HIGH);
  } else {
      Serial.print("\n SETTING OUTPUT LOW");
    digitalWrite(SMARTSWITCH_OUTPUT, LOW);
  }
}
void Smartswitch::Shot(char * param){
  int t_outputState = outputState;
  if(param != NULL){
    if(param[0] == 'O' && param[1] == 'N') {
      outputState = 1;
      setOutput();
      delay(300);
      outputState = t_outputState;
      setOutput();
    }
    if(param[0] == 'O' && param[1] == 'F' && param[1] == 'F') {
      outputState = 0;
      setOutput();
      delay(300);
      outputState = t_outputState;
      setOutput();
    }
  }
}

void Smartswitch::Pernament(char * param){
  if(param != NULL){

    if(param[0] == 'O' && param[1] == 'N') {
      outputState = 1;
      setOutput();
    }
    
    if(param[0] == 'O' && param[1] == 'F' && param[1] == 'F') {
      outputState = 0;
      setOutput();
    }
    
  }
}
