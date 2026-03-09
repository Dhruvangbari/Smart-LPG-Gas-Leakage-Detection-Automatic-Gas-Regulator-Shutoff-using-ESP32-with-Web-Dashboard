
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <Servo.h>
#include <HardwareSerial.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

#define GAS_SENSOR 34
#define BUZZER 26
#define LED 27
#define SERVO_PIN 13

int gasValue = 0;
int threshold = 350;

bool alertSent = false;

Servo regulatorServo;
AsyncWebServer server(80);

HardwareSerial sim800(1);
String phoneNumber = "+91XXXXXXXXXX";

String statusText = "SAFE";

void sendSMS(String message)
{
  sim800.println("AT+CMGF=1");
  delay(1000);

  sim800.print("AT+CMGS=\"");
  sim800.print(phoneNumber);
  sim800.println("\"");

  delay(1000);

  sim800.print(message);
  delay(500);

  sim800.write(26);
}

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>LPG Gas Monitor</title>
<style>
body{font-family:Arial;text-align:center;background:#111;color:white}
.card{background:#1f1f1f;padding:20px;margin:20px;border-radius:10px}
.value{font-size:40px}
button{padding:15px;font-size:18px;border:none;background:red;color:white;border-radius:8px}
.safe{color:lime}
.danger{color:red}
</style>
</head>
<body>
<h2>🔥 LPG Gas Leakage Monitor</h2>

<div class="card">
Gas Value
<div id="gas" class="value">0</div>
</div>

<div class="card">
Status
<div id="status" class="value safe">SAFE</div>
</div>

<div class="card">
<button onclick="closeGas()">Close Gas Regulator</button>
</div>

<script>
setInterval(function(){
fetch("/data")
.then(response => response.json())
.then(data => {
document.getElementById("gas").innerHTML = data.gas;
let st = document.getElementById("status");
st.innerHTML = data.status;
if(data.status == "DANGER"){st.className="value danger";}
else{st.className="value safe";}
});
},1000);

function closeGas(){
fetch("/close");
}
</script>

</body>
</html>
)rawliteral";

void setup(){

Serial.begin(115200);

pinMode(BUZZER,OUTPUT);
pinMode(LED,OUTPUT);

regulatorServo.attach(SERVO_PIN);
regulatorServo.write(0);

WiFi.begin(ssid,password);
while(WiFi.status()!=WL_CONNECTED){delay(500);}

sim800.begin(9600, SERIAL_8N1, 16, 17);
delay(3000);
sim800.println("AT");

server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
request->send_P(200,"text/html",index_html);
});

server.on("/data", HTTP_GET, [](AsyncWebServerRequest *request){
String json="{";
json += "\"gas\":" + String(gasValue) + ",";
json += "\"status\":\"" + statusText + "\"";
json += "}";
request->send(200,"application/json",json);
});

server.on("/close", HTTP_GET, [](AsyncWebServerRequest *request){
regulatorServo.write(90);
request->send(200,"text/plain","Gas Closed");
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

if(!alertSent){
sendSMS("ALERT! LPG Gas Leakage Detected. Regulator Closed Automatically.");
alertSent=true;
}

}
else{
digitalWrite(BUZZER,LOW);
digitalWrite(LED,LOW);
regulatorServo.write(0);
statusText="SAFE";
alertSent=false;
}

delay(1000);
}
