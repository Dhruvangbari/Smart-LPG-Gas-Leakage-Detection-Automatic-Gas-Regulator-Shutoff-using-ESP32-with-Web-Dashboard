
# LPG Gas Leakage Detection using ESP32

## Features
- LPG Gas detection using MQ2 sensor
- Automatic gas regulator shutoff using servo motor
- Buzzer and LED alert
- Web dashboard monitoring
- SMS alert using SIM800L GSM module

## Hardware Required
- ESP32
- MQ2 Gas Sensor
- SG90 Servo Motor
- Buzzer
- LED
- SIM800L GSM module

## Pin Connections
MQ2 -> GPIO34
Servo -> GPIO13
Buzzer -> GPIO26
LED -> GPIO27
SIM800 TX -> GPIO16
SIM800 RX -> GPIO17

## Usage
1. Install required Arduino libraries:
   - ESPAsyncWebServer
   - AsyncTCP
   - Servo

2. Update WiFi credentials and phone number in code.

3. Upload firmware to ESP32.

4. Open Serial Monitor to see ESP32 IP address.

5. Open the IP address in browser to access dashboard.
