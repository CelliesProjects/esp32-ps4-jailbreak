#include <SPIFFS.h>  
#include <WiFi.h>
#include <DNSServer.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

//don't forget to upload the data folder to SPIFFS!!

IPAddress apIP( 192,168,4,1 );

DNSServer dnsServer;
AsyncWebServer server(80);

void setup()
{
  Serial.begin(115200);
  Serial.println();
  btStop();

  SPIFFS.begin();
  // setup access point
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig (apIP, apIP, IPAddress( 255, 255, 255, 0 ) );
  WiFi.softAP("ESP32 5.05 jailbreak server");

  //setup dns server to send all traffic to esp32
  dnsServer.start( 53, "*", apIP);

  //setup webserver
  server.serveStatic( "/", SPIFFS, "/" );

  server.begin();

  Serial.print( "Browse to 'http://");
  Serial.print( WiFi.softAPIP() );
  Serial.print( "/index.html' to jailbreak your PS4 5.05." );
}

void loop() {
  dnsServer.processNextRequest();
}
