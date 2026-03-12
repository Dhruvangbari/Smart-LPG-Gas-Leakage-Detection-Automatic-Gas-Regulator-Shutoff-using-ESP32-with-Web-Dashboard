# Smart LPG Gas Leakage Detection & Automatic Gas Regulator Shutoff using ESP32

An IoT-based LPG gas leakage detection system that automatically shuts off the gas regulator when a leak is detected.  
The system uses an **ESP32 microcontroller**, **MQ-2 gas sensor**, **servo motor**, **LED**, and **buzzer** to detect gas leaks and prevent accidents.  


A built-in **web dashboard** allows users to monitor gas levels in real time through WiFi.

---

# Key Features

• LPG gas leak detection using MQ-2 sensor  
• Automatic gas regulator shutoff using servo motor  
• LED indicator for visual warning  
• Buzzer alarm for emergency alerts  
• ESP32 WiFi-based web dashboard  
• Real-time gas level monitoring  
• Manual gas shutoff control from dashboard  
• Expandable for cloud monitoring and mobile alerts  

---

# Hardware Components

| Component | Quantity |
|--------|--------|
ESP32 DevKit V1 | 1
MQ-2 Gas Sensor | 1
SG90 Servo Motor | 1
Active Buzzer | 1
LED | 1
220Ω Resistor | 1
Breadboard | 1
Jumper Wires | As required
5V Power Supply | 1

---

# Pin Configuration

| Component | ESP32 Pin |
|-----------|-----------|
MQ-2 Sensor | GPIO34
Servo Motor | GPIO13
Buzzer | GPIO26
LED | GPIO27

---

# System Architecture

```
LPG Gas Environment
        │
        ▼
MQ-2 Gas Sensor
        │
        ▼
ESP32 Microcontroller
        │
 ┌──────┼─────────┬──────────┐
 │      │         │          │
Servo   Buzzer    LED     Web Server
Motor   Alarm   Indicator   (WiFi)
 │
 ▼
Gas Regulator Shutoff
```

---

# Working Principle

1. The **MQ-2 gas sensor continuously monitors LPG gas concentration** in the environment.
2. Sensor values are read by the **ESP32 microcontroller**.
3. If gas levels exceed a predefined **threshold value**:
   - The **buzzer activates**
   - The **LED turns ON**
   - The **servo motor rotates to close the gas regulator**
4. The ESP32 web dashboard updates the system status to **DANGER**.
5. When gas levels return to normal, the system resets automatically.

---

# Web Dashboard

The ESP32 hosts a **local web server** that displays real-time gas sensor data.

Open the ESP32 IP address in a browser:

```
http://ESP32-IP-ADDRESS
```

Dashboard displays:

• Gas sensor value  
• System status (SAFE / DANGER)  
• Gas regulator state  
• Manual gas control buttons  

---

# API Endpoints

The ESP32 provides REST endpoints for integration with dashboards or mobile apps.

### Get Gas Data
```
/data
```

Example response:

```json
{
 "gas": 320,
 "status": "SAFE"
}
```

### Close Gas Regulator
```
/close
```

### Open Gas Regulator
```
/open
```

---

# Installation

### 1 Install Arduino IDE

Download Arduino IDE and install ESP32 board support.

### 2 Install Required Libraries

Install these libraries from Arduino Library Manager:

```
ESPAsyncWebServer
AsyncTCP
Servo
```

### 3 Clone Repository

```
git clone https://github.com/yourusername/lpg-gas-leak-detection-esp32.git
```

### 4 Configure WiFi

Edit the firmware file and update:

```
YOUR_WIFI_NAME
YOUR_WIFI_PASSWORD
```

### 5 Upload Firmware

Upload the code to the ESP32 using Arduino IDE.

### 6 Open Dashboard

Open the ESP32 IP address in a browser to view the dashboard.

---

# Project Structure

```
lpg-gas-leak-detection
│
├── firmware
│   └── esp32_gas_detector.ino
│
├── web-dashboard
│   ├── index.html
│   ├── style.css
│   └── script.js
│
├── docs
│   └── project_overview.md
│
└── README.md
```

---

# Applications

• Smart kitchen safety systems  
• LPG storage monitoring  
• Industrial gas safety systems  
• Restaurants and hotels  
• Smart home automation  

---

# Future Improvements

• SMS or Telegram alerts  
• Firebase cloud monitoring  
• Mobile application dashboard  
• Gas leak history analytics  
• AI-based leak prediction  
• IoT cloud integration (MQTT / Blynk)

---

# Safety Notes

The MQ-2 gas sensor must be calibrated properly before use.  
This project is intended for **educational and research purposes** and should not replace certified gas safety equipment.

---

# License

This project is released under the **MIT License**.

---

# Author

Developed as an IoT safety project using ESP32.
