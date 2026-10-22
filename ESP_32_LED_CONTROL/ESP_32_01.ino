#include <WiFi.h>

WiFiServer server;

void setup() {
  pinMode(12, OUTPUT);
  pinMode(15, OUTPUT);

  const String ssid = "Nova 160";
  const String password = "KALIFNx312#";

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(12, HIGH);
    delay(500);
    digitalWrite(12, LOW);
    delay(500);
  }

  digitalWrite(12, HIGH);

  Serial.begin(115200);
  // Serial.println(WiFi.localIP());        // 192.168.8.151

  server = WiFiServer(80);
  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    String request = client.readStringUntil('\r');
    Serial.println(request);

    if(request.indexOf("/on") != -1){
       digitalWrite(15, HIGH);
    }
     if(request.indexOf("/off") != -1){
       digitalWrite(15, LOW);
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type:text/html");
    client.println();
  }
}
