

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "Dialog";
const char *password = "";

ESP8266WebServer server(80);

/* J http://192.168.4.1 in a web browser*/
char HTML[] = "<html><body><form action='/action_page.php'>   First name:<br>  <input type='text' name='firstname' value=""><br>  Last name:<br><input type='text' name='lastname' value=""><br><br><input type='button' onclick='alert('Hello World!')' value='Click Me!'> <a href=\"http://192.168.4.1/1\">  submit </a></form></body></html> ";
//impor
void handleRoot() {
	server.send(200, "text/html",HTML );//impo
}

 void Page1()
 {
  server.send(200, "text/html", "<h1>now you are in 2</h1>");//impo
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
  server.on("/1",Page1);//impo
	server.begin();
	Serial.println("HTTP server started");
}

void loop() {
	server.handleClient();
  
}
