# Smart LPG Gas Leakage Detection System using ESP32

## Project Overview

This project is an IoT-based LPG gas leakage detection system built using the ESP32 microcontroller and MQ-2 gas sensor. The system continuously monitors gas levels and automatically shuts of
f the gas regulator using a servo motor wh
en a dangerous gas leak is detected.



The system also provides LED and buzzer alerts and displays real-time data on a web dashboard hosted by the ESP32.

This project improves safety in homes, kitchens, restaurants, and industrial environments where LPG gas is used.

---

## Features

- LPG gas leakage detection using MQ-2 sensor
- Automatic gas regulator shutoff using servo motor
- LED indicator for visual alert
- Buzzer alarm for emergency warning
- Real-time web dashboard monitoring
- Live gas level visualization
- WiFi-based IoT monitoring using ESP32
- Expandable for cloud and mobile alerts

---

## Hardware Components

ESP32 DevKit V1  
MQ-2 Gas Sensor  
SG90 Servo Motor  
Active Buzzer  
LED  
220Ω Resistor  
Breadboard  
Jumper Wires  
5V Power Supply  

---

## Pin Configuration

MQ-2 Sensor  → GPIO34  
Servo Motor  → GPIO13  
Buzzer       → GPIO26  
LED          → GPIO27  

---

## System Architecture

LPG Gas  
   │  
MQ-2 Gas Sensor  
   │  
ESP32 Controller  
   │  
 ├── Servo Motor → Automatic Gas Shutoff  
 ├── Buzzer → Alarm Alert  
 └── LED → Visual Warning  

        │  
        │  
   Web Dashboard  
        │  
Real-Time Monitoring  

---

## Working Principle

1. The MQ-2 gas sensor continuously monitors LPG gas concentration.
2. Sensor values are read by the ESP32.
3. If gas levels exceed the safety threshold:
   - The buzzer turns ON.
   - The LED turns ON.
   - The servo motor rotates to close the gas regulator.
4. The web dashboard updates the gas status to "DANGER".
5. When gas levels return to safe range, the system resets automatically.

---

## Web Dashboard

The ESP32 hosts a local web server that displays gas sensor data.

Open the ESP32 IP address in a browser:

http://ESP32-IP-ADDRESS

The dashboard shows:

Gas value  
System status (SAFE / DANGER)  
Live gas monitoring  

---

## Installation

1. Install Arduino IDE.

2. Install required libraries:

ESPAsyncWebServer  
AsyncTCP  
Servo  

3. Upload the firmware to ESP32.

4. Connect ESP32 to WiFi.

5. Open the ESP32 IP address in a web browser to view the dashboard.

---

## Applications

Smart kitchen safety systems  
Industrial gas monitoring  
Restaurant gas safety  
Home automation safety systems  
LPG storage monitoring  

---

## Future Improvements

SMS or Telegram alerts  
Firebase cloud monitoring  
Mobile application dashboard  
Gas leak history graph  
AI-based leak prediction  

---

## License

This project is open-source and available under the MIT License.
