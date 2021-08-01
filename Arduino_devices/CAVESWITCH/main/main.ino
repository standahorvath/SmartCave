/* ========================================== */
/* SMARTCAVE Project                          */
/* Device: CAVESWITCH                         */
/* Description: This device listen to UDP and */
/*              switching on/off power output */
/* Version: 1.0                               */
/* ========================================== */


#include <ESP8266WiFi.h>
#include <WiFiUDP.h>

#define UDP_PORT 4210;

const char* WIFI_NAME = ""; // Set wifi name
const char* WIFI_PASS = ""; // Set wifi pass
const char* DEVICE_NAME = "CAVE_SWITCH";  // Device name

WiFiUDP udp_client;


void setup() {
  
  serialInit();
  wifiInit();

}

void loop() {
  
  listenUDP();
  
}

// Check new packet UDP
void listenUDP(){
  int packetSize = Udp.parsePacket();
  if (packetSize) {

    
       Serial.print("Received packet of size ");

        Serial.println(packetSize);
    
        Serial.print("From ");
    
        IPAddress remoteIp = Udp.remoteIP();
    
        Serial.print(remoteIp);
    
        Serial.print(", port ");
    
        Serial.println(Udp.remotePort());
    
        // read the packet into packetBufffer
    
        int len = Udp.read(packetBuffer, 255);
    
        if (len > 0) {
    
          packetBuffer[len] = 0;
    
        }
    
        Serial.println("Contents:");
    
        Serial.println(packetBuffer);
    
        // send a reply, to the IP address and port that sent us the packet we received
    
        Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    
        Udp.write(ReplyBuffer);
    
        Udp.endPacket();

    
  }
}

// Init UDP
void udpInit(){
  Client.begin(UDP_PORT);
}

// Init Serial comunication
void serialInit(){
  // Serial comunication
  Serial.begin(9600);
}

// Init local wifi
void wifiInit(){
    // Wifi connect
  WiFi.begin(WIFI_NAME, WIFI_PASS);

  Serial.print("Connecting to WIFI.");

  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }
  
  Serial.print("Connected to  ");
  Serial.println(nazevWifi);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  long rssi = WiFi.RSSI();

  Serial.print("signal strength (RSSI):");

  Serial.print(rssi);

  Serial.println(" dBm");
}
