 /*
  Wifi.h - Wfi driver object
*/
#include "Wifi.h"

Wifi::Wifi() {

}

/* Initialize function */
void Wifi::init(){
    // Wifi connect
    WiFi.begin(WIFI_NAME, WIFI_PASS);
  
    Serial.print("Connecting to WIFI.");
  
    while (WiFi.status() != WL_CONNECTED) {
      delay(300);
      Serial.print(".");
    }
    
    Serial.print("Connected to  ");
    Serial.println(WIFI_NAME);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    
    long rssi = WiFi.RSSI();
  
    Serial.print("signal strength (RSSI):");
  
    Serial.print(rssi);
  
    Serial.println(" dBm");

    _udp.begin(UDP_PORT);

    _udp_buffer = new char[UDP_BUFFER_SIZE];
}
WiFiUDP Wifi::getUDP(){
  return _udp;
}
void Wifi::listen_udp(Router * router){
   int t_packetSize = _udp.parsePacket();
  if (t_packetSize) {

        IPAddress t_remoteIp = _udp.remoteIP();
        int t_remotePort = _udp.remotePort();
    
        int len = _udp.read(_udp_buffer, UDP_BUFFER_SIZE);
    
        if (len > 0) {
    
          _udp_buffer[len] = 0;
    
        }

        router->process(_udp_buffer);
        
        // send a reply, to the IP address and port that sent us the packet we received
    
        //Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    
        //Udp.write(ReplyBuffer);
    
        //Udp.endPacket();

  }
}

void Wifi::process(){
  
}
