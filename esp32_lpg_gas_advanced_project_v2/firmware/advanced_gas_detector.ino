#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <Servo.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

#define GAS_SENSOR 34
#define BUZZER 26
#define LED 27
#define SERVO_PIN 13

int gasValue = 0;
int threshold = 350;

bool gasClosed = false;

Servo regulatorServo;
AsyncWebServer server(80);

String systemStatus = "SAFE";

void setup() {

Serial.begin(115200);

pinMode(BUZZER, OUTPUT);
pinMode(LED, OUTPUT);

regulatorServo.attach(SERVO_PIN);
regulatorServo.write(0);

WiFi.begin(ssid, password);

Serial.print("Connecting to WiFi");

while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}

Serial.println("");
Serial.println("Connected");

Serial.print("ESP32 IP Address: ");
Serial.println(WiFi.localIP());

server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){

String page = "<h2>LPG Gas Monitoring</h2>";
page += "Gas Value: " + String(gasValue) + "<br>";
page += "Status: " + systemStatus + "<br><br>";
page += "<a href='/close'>Close Gas</a><br>";
page += "<a href='/open'>Open Gas</a>";

request->send(200, "text/html", page);

});

server.on("/data", HTTP_GET, [](AsyncWebServerRequest *request){

String json = "{";
json += "\"gas\":";
json += gasValue;
json += ",";
json += "\"status\":\"";
json += systemStatus;
json += "\"";
json += "}";

request->send(200, "application/json", json);

});

server.on("/close", HTTP_GET, [](AsyncWebServerRequest *request){

regulatorServo.write(90);
gasClosed = true;

request->send(200, "text/plain", "Gas Closed");

});

server.on("/open", HTTP_GET, [](AsyncWebServerRequest *request){

regulatorServo.write(0);
gasClosed = false;

request->send(200, "text/plain", "Gas Opened");

});

server.begin();
}

void loop() {

gasValue = analogRead(GAS_SENSOR);

Serial.println(gasValue);

if (gasValue > threshold) {

digitalWrite(BUZZER, HIGH);
digitalWrite(LED, HIGH);

regulatorServo.write(90);

gasClosed = true;

systemStatus = "DANGER";

}
else {

digitalWrite(BUZZER, LOW);
digitalWrite(LED, LOW);

if(!gasClosed){
regulatorServo.write(0);
}

systemStatus = "SAFE";

}

delay(1000);

}
