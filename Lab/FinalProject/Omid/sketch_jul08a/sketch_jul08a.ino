/* Create a WiFi access point and provide a web server on it.
  ESP8266 Arduino example
*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "ESPap";
const char *password = "yasaman";

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
   connected to this access point to see it.
*/
void handleRoot() {
  server.send(200, "text/html", returnHTML());
}

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}
char incomingByte[10];
String incomingString;
void loop() {
  //Serial.print("sdfsdfsdf");
 // if (Serial.available() > 0) {
    // read the incoming byte:
    //incomingString = Serial.readString();
    incomingString.toCharArray(incomingByte,10);
   // Serial.print("navid: ");
    Serial.println(incomingByte);
 // }
  server.handleClient();
}
   
char* returnHTML() {
  char temp[1500];
  snprintf(temp , 1500 , "<h1>Microprocessor final project</h1> <br> <h2>Temperature : 27 <\h2>" );
  return temp;
}
