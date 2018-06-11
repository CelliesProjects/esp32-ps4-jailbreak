#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "index_htm.h"

const char * AP_SSID = "ESP32 5.05 jailbreak server";

IPAddress apIP( 192, 168, 4, 1 );

AsyncWebServer server( 80 );

bool accessPointIsStarted = false;

void setup()
{
  Serial.begin( 115200 );
  Serial.println();
  btStop();

  // setup access point
  WiFi.mode( WIFI_AP );
  WiFi.softAP( "ESP32 5.05 jailbreak server" );

  WiFi.onEvent( WiFiEvent );

  //setup webserver
  server.on( "/", HTTP_GET, [] ( AsyncWebServerRequest * request )
  {
    AsyncWebServerResponse *response = request->beginResponse_P( 200, "text/html", index_htm, index_htm_len );
    request->send( response );
  });

  server.onNotFound( []( AsyncWebServerRequest * request )
  {
    request->send( 404 );
  });

  server.begin();

  while ( !accessPointIsStarted )
  {
    delay(10);
  };

  Serial.println( "Ready." );
  Serial.print( "Browse to 'http://");
  Serial.print( WiFi.softAPIP() );
  Serial.println( "/' to jailbreak your PS4 5.05." );
}

void loop() {}

void WiFiEvent( WiFiEvent_t event )
{
  switch ( event )
  {
    case SYSTEM_EVENT_AP_START:
      WiFi.softAPConfig ( apIP, apIP, IPAddress( 255, 255, 255, 0 ) );
      accessPointIsStarted = true;
      break;
    default:
      break;
  }
}
