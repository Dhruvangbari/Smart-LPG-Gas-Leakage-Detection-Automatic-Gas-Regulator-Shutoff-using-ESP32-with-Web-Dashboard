
# LPG Gas Leakage Detection using ESP32
Smart LPG Gas Leakage Detection System using ESP32

This project is an IoT-based gas safety system designed to detect LPG gas leakage and automatically shut off the gas regulator to prevent accidents. The system uses an ESP32 microcontroller, MQ-2 gas sensor, and servo motor to detect dangerous gas levels and close the gas regulator automatically.

It also features a real-time web dashboard for monitoring gas levels and an SMS alert system using a GSM module to notify users immediately when a gas leak occurs.
LPG gas leakage detection using MQ-2 sensor

Automatic gas regulator shutoff using servo motor

Buzzer and LED alarm for immediate warning

ESP32 web dashboard for live monitoring

Manual gas shutoff button from dashboard

SMS alert notification using GSM module

Real-time gas value monitoring

WiFi-enabled IoT system


| Component                   | Quantity    |
| --------------------------- | ----------- |
| ESP32 Development Board     | 1           |
| MQ-2 Gas Sensor             | 1           |
| SG90 Servo Motor            | 1           |
| Buzzer                      | 1           |
| LED                         | 1           |
| SIM800L / SIM900 GSM Module | 1           |
| Jumper Wires                | As required |
| Breadboard                  | 1           |
| Power Supply                | 5V          |




| Device      | ESP32 Pin |
| ----------- | --------- |
| MQ2 Sensor  | GPIO34    |
| Servo Motor | GPIO13    |
| Buzzer      | GPIO26    |
| LED         | GPIO27    |
| GSM TX      | GPIO16    |
| GSM RX      | GPIO17    |



LPG Gas
   │
MQ2 Gas Sensor
   │
ESP32 Controller
   │
 ┌───────────────┬───────────────┬───────────────┐
 │               │               │
Servo Motor     Alarm        Web Dashboard
Gas Shutoff     Buzzer       Live Monitoring
                    │
                 GSM Module
                    │
                SMS Alert



                The MQ-2 sensor continuously monitors gas concentration.

Sensor data is read by the ESP32.

If gas level exceeds the safety threshold:

Buzzer and LED activate.

Servo motor rotates to close the gas regulator.

SMS alert is sent to the user.

Dashboard status changes to DANGER.

When gas levels return to normal, the system resets.


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
