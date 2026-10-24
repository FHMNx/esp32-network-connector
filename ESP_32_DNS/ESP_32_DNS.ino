#include <WiFi.h>
#include <ESPmDNS.h>

const String ssid = "Nova 160";
const String password = "KALIFNx312#";

WiFiServer server = WiFiServer(80);

void setup() {

  pinMode(15, OUTPUT);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    //checking WiFi status
  }

  MDNS.begin("jiat");  // https://jiat.local/
  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  String request = client.readStringUntil('/r');

  if (request.indexOf("/on") != -1) {  // https://jiat.local/on
    digitalWrite(15, HIGH);
  }

  if (request.indexOf("/off") != -1) {  // https://jiat.local/off
    digitalWrite(15, LOW);
  }

  if (client) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");

    client.println();  // seperate header and body

    client.println("<style>");
    client.println("body { font-family: Arial, sans-serif; background: #111827; color: #f9fafb; display: flex; flex-direction: column; align-items: center; justify-content: center; height: 100vh; margin: 0; }");
    client.println("h1 { color: #60a5fa; margin-bottom: 20px; }");
    client.println("a { display: inline-block; text-decoration: none; background: #2563eb; color: white; padding: 12px 20px; margin: 8px; border-radius: 8px; font-weight: bold; }");
    client.println("a:hover { background: #1d4ed8; }");
    client.println("</style>");
    client.println("<body>");
    client.println("<h1>LED CONTROLLER!</h1>");
    client.println("<a href='/on'>Turn ON</a>");
    client.println("<a href='/off'>Turn OFF</a>");
    client.println("</body>");
  }
}
