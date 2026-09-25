# Smart Dustbin 🗑️

## Automated Smart Waste Management System Using Arduino

Smart Dustbin is an embedded automation project developed using Arduino to create a touch-free waste disposal system. The system uses ultrasonic sensors, servo motor control, LCD display, buzzer, LED indicator, and push button functionality to monitor waste level and automate dustbin operations.

The main goal of this project is to improve hygiene, reduce direct human contact with waste, and demonstrate a practical application of embedded systems and sensor-based automation.

---

## Project Overview

Traditional dustbins require manual lid opening and regular checking of waste levels. This project introduces an automated waste management solution where the dustbin can detect users, control the lid automatically, monitor waste capacity, and provide alerts when the bin becomes full.

The system provides:

- Automatic lid opening and closing
- Real-time waste level monitoring
- LCD-based waste percentage display
- Full waste detection and warning system
- Manual override functionality

---

## Features

### Automatic Lid Control

- Uses an ultrasonic proximity sensor to detect nearby objects.
- Controls the dustbin lid using a servo motor.
- Provides touch-free waste disposal.

### Waste Level Monitoring

- Measures waste level using an ultrasonic sensor.
- Converts sensor distance data into waste percentage.
- Displays real-time waste information on a 16x2 I2C LCD display.

### Full Waste Detection System

When the waste level reaches the maximum threshold:

- LCD displays a full waste warning message.
- LED indicator turns ON.
- Buzzer provides an alert.
- Automatic lid opening is disabled.

### Manual Override System

- Push button allows manual lid operation.
- Useful for cleaning and maintenance purposes.

---

## Hardware Components

| Component | Purpose |
|-----------|---------|
| Arduino Board | Main controller of the system |
| Ultrasonic Sensor | Waste level measurement |
| Ultrasonic Sensor | Object/proximity detection |
| Servo Motor | Automatic lid control |
| 16x2 I2C LCD Display | Waste level information display |
| Buzzer | Full waste alert |
| LED Indicator | Warning indication |
| Push Button | Manual lid control |

---

## Software Requirements

### Development Environment

- Arduino IDE

### Programming Language

- Embedded C/C++

### Libraries Used

- Wire.h
- LiquidCrystal_I2C.h
- NewPing.h
- Servo.h

---

## Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| Waste Level Sensor Trigger | 7 |
| Waste Level Sensor Echo | 6 |
| Buzzer | 4 |
| Proximity Sensor Trigger | 9 |
| Proximity Sensor Echo | 10 |
| Servo Motor | 2 |
| Push Button | 5 |
| LED Indicator | 3 |

---

## Working Principle

### 1. Waste Level Detection

The ultrasonic sensor measures the distance between the sensor and the waste surface.

The measured distance is converted into a percentage value and displayed on the LCD screen.

Example:

```
Waste Level: 60%
||||||||||
```

---

### 2. Automatic Lid Operation

The proximity sensor continuously checks for nearby objects.

When a person approaches:

1. The ultrasonic sensor detects the object.
2. Arduino processes the input signal.
3. The servo motor opens the lid.
4. After disposal, the lid closes automatically.

The automatic lid system works only when the waste level is below the maximum limit.

---

### 3. Full Bin Protection

When the waste level reaches the defined limit:

- LCD displays:

```
Locked Waste Full
Please clean 1st
```

- LED indicator turns ON.
- Buzzer starts alerting.
- Automatic lid operation is locked.

---

### 4. Manual Operation

A push button is included for manual control.

When the button is pressed:

- The lid opens.
- User can manually dispose waste.
- The lid closes automatically after the configured delay.

---

## Project Structure

```
Smart-Dustbin/
│
├── Smart_Dustbin.ino
│
├── README.md
│
└── Hardware Components
    ├── Arduino Board
    ├── Ultrasonic Sensors
    ├── Servo Motor
    ├── LCD Display
    ├── Buzzer
    ├── LED Indicator
    └── Push Button
```

---

## System Workflow

```
START
  |
  |
Initialize Sensors and Modules
  |
  |
Measure Waste Level
  |
  |
Display Waste Percentage
  |
  |
Check Waste Condition
  |
  |-------------------------
  |                         |
Full Waste             Space Available
  |                         |
LED + Buzzer          Check Proximity
Lid Locked                  |
                            |
                    Object Detected
                            |
                       Open Lid
                            |
                       Close Lid
```

---

## Technologies Used

- Arduino Programming
- Embedded Systems
- Sensor-Based Automation
- Ultrasonic Sensor Processing
- Servo Motor Control
- Real-Time Monitoring System

---

## Project Objectives

- Develop an automated waste management system.
- Reduce direct human contact with waste.
- Improve hygiene and convenience.
- Apply embedded programming concepts.
- Demonstrate real-world sensor-based automation.

---

## Applications

- Smart Homes
- Hospitals
- Educational Institutions
- Offices
- Public Waste Management Systems

---

## Future Improvements

- IoT-based remote monitoring
- Mobile application integration
- Cloud-based data storage
- Multiple smart dustbin management
- AI-based waste classification

---

## Demo Video

YouTube Demo:

https://youtu.be/-uunxcqqJjo

---

## Author

**Md Sakib Khan**

---

## License

This project is licensed under the MIT License.
