#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "index_htm.h"

const char * AP_SSID = "ESP32 5.05 jailbreak server";

const IPAddress AP_IP( 192, 168, 4, 1 );

const uint8_t BUILTIN_LED = 2;

AsyncWebServer server( 80 );

void setup()
{
  Serial.begin( 115200 );
  Serial.println();
  btStop();

  // setup access point
  WiFi.mode( WIFI_AP );
  WiFi.softAP( AP_SSID );
  WiFi.onEvent( WiFiEvent );

  static const char * HTML_HEADER = "text/html";

  //setup webserver
  server.on( "/", HTTP_GET, [] ( AsyncWebServerRequest * request )
  {
    AsyncWebServerResponse *response = request->beginResponse_P( 200, HTML_HEADER, index_htm, index_htm_len );
    request->send( response );
  });

  server.onNotFound( []( AsyncWebServerRequest * request )
  {
    request->send( 404, HTML_HEADER, "404 not found" );
  });

  server.begin();
}

void loop() {}

void WiFiEvent( WiFiEvent_t event )
{
  switch ( event )
  {
    case SYSTEM_EVENT_AP_START:
      WiFi.softAPConfig ( AP_IP, AP_IP, IPAddress( 255, 255, 255, 0 ) );
      Serial.print( "1. Connect your PS4 to '" );
      Serial.print( AP_SSID );
      Serial.println( "' WiFi access point." );
      Serial.println();
      Serial.print( "2. Browse to 'http://");
      Serial.print( WiFi.softAPIP() );
      Serial.println( "/' to jailbreak your PS4 5.05." );
      pinMode( BUILTIN_LED, OUTPUT );
      digitalWrite( BUILTIN_LED, HIGH );
      break;
    default:
      break;
  }
}
