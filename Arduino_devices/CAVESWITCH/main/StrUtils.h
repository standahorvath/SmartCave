 /*
  Wifi.h - Wfi driver object
*/
#ifndef STRUTILS_h
#define STRUTILS_h
#include "Arduino.h"

int char_count_in_string(char * str, char c);
int get_position_of_char(char * str, char c, int index);
int get_string_count(char * str);
char * copy_str(char * source, int start, int length);

#endif
