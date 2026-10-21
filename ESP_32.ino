#include <WiFi.h>

WiFiServer server;

void setup() {

  Serial.begin(115200);

  const String ssid = "Nova 160";
  const String password = "KALIFNx312#";

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {  //3 means connected
    Serial.print(".");
    delay(500);
  }

  Serial.println("Connected");
  Serial.println(WiFi.localIP());

  //connecting with server
  server = WiFiServer(80);
  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();

    client.println("<html>");

    client.println("<head>");
    client.println("<title>ESP 32</title>");
    client.println("</head>");

    client.println("<body>");
    client.println("<h1>Hello! I'm ESP32</h1>");
    client.println("</body>");

    client.println("</html>");

    client.stop();
  }
}
