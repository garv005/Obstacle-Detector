# Obstacle Avoidance Car with Ultrasonic Sensor and RGB LED

## Description

This project involves building a small autonomous car that moves forward and avoids obstacles using an ultrasonic sensor. When an obstacle is detected within 5 cm, the car stops, turns left, and continues moving. An RGB LED provides visual feedback, flashing red for distant obstacles and solid green when the path is clear. The car's status is also printed on the Serial Monitor.

## Features

- **Autonomous Movement:** The car moves forward and detects obstacles in its path.
- **Obstacle Avoidance:** When an obstacle is detected within 5 cm, the car stops and turns left.
- **RGB LED Feedback:** 
  - **Flashing Red:** For distant obstacles.
  - **Solid Red:** When an obstacle is exactly 5 cm away.
  - **Solid Green:** When the car is moving freely.
- **Serial Monitor Output:** Displays messages when an obstacle is detected or the car turns left.

## Components Used

- **Arduino (Uno/Other)**
- **HC-SR04 Ultrasonic Sensor**
- **RGB LED**
- **L298N DC Motor Driver Module**
- **DC Motors and Wheels**

## Setup Instructions

1. **Connect the HC-SR04 Ultrasonic Sensor** to the Arduino:
   - VCC → 5V
   - GND → GND
   - Trig → Pin 9
   - Echo → Pin 10

2. **Interface the L298N Motor Driver Module** to the Arduino:
   - IN1 → Pin 5
   - IN2 → Pin 6
   - IN3 → Pin 7
   - IN4 → Pin 8
   - ENA → 5V (or PWM pin for speed control)
   - ENB → 5V (or PWM pin for speed control)
   - Connect motors to the L298N motor driver.

3. **Connect the RGB LED** to the Arduino:
   - Red → Pin 3
   - Green → Pin 4
   - Blue → Pin 5 (optional, not used in this project)

4. **Upload the Arduino code** and monitor the Serial output for real-time updates on the car's behavior.

## Code Overview

- The Arduino code continuously checks the distance from the ultrasonic sensor.
- If an obstacle is detected within 5 cm, the car stops and turns left.
- The RGB LED changes colors based on the proximity of obstacles.
- The car continues to navigate around obstacles until the path is clear.

## Usage Instructions

- After uploading the code to the Arduino, the car will start moving forward and scanning for obstacles.
- When an obstacle is detected, it will stop, turn left, and keep moving.
- The RGB LED will provide real-time feedback based on the distance to obstacles.
