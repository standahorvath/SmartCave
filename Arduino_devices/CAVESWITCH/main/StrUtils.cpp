 /*
  Wifi.h - Wfi driver object
*/
#include "StrUtils.h"

int char_count_in_string(char * str, char c) {
  int count = 0;
  int index = 0;
  while(str[index] != '\0') {
    if(str[index] == c) count++;
    index++;
  }
  return count;
}

int get_position_of_char(char * str, char c, int index){
    
  int count = 0;
  int c_index = 0;
  while(str[c_index] != '\0') {
    if(str[c_index] == c){
       if(count == index) return c_index;
       count++; 
    } 
    c_index++;
  }
  
  return 0;
  
}

int get_string_count(char * str){
    int count = 0;
    int c_index = 0;
    while(str[c_index] != '\0') {
    c_index++;
    }
    return c_index - 1;
}

char * copy_str(char * source, int start, int length){
    char * t_string;
    t_string = (char*)malloc((sizeof(char) * length) + 1);
    for(int i = 0; i < length; i++){
      t_string[i] = source[i + start];
    }
    t_string[length] = '\0';
    return t_string;
}
