
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <Servo.h>

#define GAS_SENSOR 34
#define BUZZER 26
#define LED 27
#define SERVO_PIN 13

int gasValue = 0;
int threshold = 350;

Servo regulatorServo;
AsyncWebServer server(80);
String statusText = "SAFE";

void setup(){
Serial.begin(115200);
pinMode(BUZZER,OUTPUT);
pinMode(LED,OUTPUT);

regulatorServo.attach(SERVO_PIN);
regulatorServo.write(0);

server.on("/data", HTTP_GET, [](AsyncWebServerRequest *request){
String json="{";
json += "\"gas\":" + String(gasValue) + ",";
json += "\"status\":\"" + statusText + "\"";
json += "}";
request->send(200,"application/json",json);
});

server.begin();
}

void loop(){
gasValue = analogRead(GAS_SENSOR);

if(gasValue > threshold){
digitalWrite(BUZZER,HIGH);
digitalWrite(LED,HIGH);
regulatorServo.write(90);
statusText="DANGER";
}
else{
digitalWrite(BUZZER,LOW);
digitalWrite(LED,LOW);
regulatorServo.write(0);
statusText="SAFE";
}

delay(1000);
}
