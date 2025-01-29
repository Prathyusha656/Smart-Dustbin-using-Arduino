# Smart Dustbin Using Arduino
## 📌 Project Overview
The Smart Dustbin is an automated, touchless waste disposal system that opens its lid automatically when it detects a person approaching. This improves hygiene by eliminating the need for physical contact.

The system uses an ultrasonic sensor (HC-SR04) to detect motion and a servo motor to control the lid’s movement. The entire project is controlled using an Arduino Uno.

## 📂 Project Folder Structure

/Smart-Dustbin
   ├── /Code             # Arduino sketch (.ino file)
   ├── /Schematics       # Circuit diagrams
   ├── /Documentation    # Project Report
   ├── README.md         # Project details for GitHub

## 🛠️ Components Required
Component	Quantity	Description
Arduino Uno	1	Microcontroller board to control the system
Ultrasonic Sensor (HC-SR04)	1	Detects objects within a certain range
Servo Motor (SG90)	1	Controls the movement of the dustbin lid
Jumper Wires	As needed	For making connections
9V Battery & Holder	1	Power source for Arduino
Dustbin (Plastic Container)	1	The main body for waste collection
## ⚙️ Working Principle
🔹 How It Works
Ultrasonic Sensor Detection:

The HC-SR04 ultrasonic sensor continuously measures the distance of nearby objects.
If an object (such as a hand) is detected within 15 cm, the sensor sends a signal to Arduino.
Servo Motor Activation:

When the object is detected, the servo motor rotates to open the dustbin lid.
Auto-close Mechanism:

After 3 seconds, the servo closes the lid automatically to prevent exposure.
Standby Mode:

The system resets and waits for the next motion detection.
## 📜 Arduino Code
This is an optimized and well-structured Arduino code for smooth and efficient operation. 🚀

#include <Servo.h>

// Define Pins
const int trigPin = 9;
const int echoPin = 10;
Servo servoMotor;

// Function to measure distance
int getDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);
    int distance = duration * 0.034 / 2;
    return distance;
}

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    servoMotor.attach(6);
    servoMotor.write(0);  // Start with the lid closed
    Serial.begin(9600);
}

void loop() {
    int distance = getDistance();

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Open lid if object detected within 15 cm
    if (distance > 0 && distance < 15) {
        servoMotor.write(90);  // Open the lid
        delay(3000);           // Wait 3 seconds
        servoMotor.write(0);   // Close the lid
    }

    delay(500);
}
🔹 Code Explanation
✔️ getDistance() Function: Measures the distance using the ultrasonic sensor.
✔️ Setup (setup()): Initializes pins and sets the servo motor to its default position (closed).
✔️ Loop (loop()): Continuously checks the distance and opens/closes the dustbin lid accordingly.

## 🔌 Circuit Diagram
🔹 Wiring Connections
Component	Arduino Pin
HC-SR04 Ultrasonic Sensor	
VCC	5V
GND	GND
Trig	Pin 9
Echo	Pin 10
Servo Motor (SG90)	
VCC	5V
GND	GND
Signal	Pin 6

### Circuit Diagram
![Circuit Diagram](/Schematics/image.png)

## 🚀 How to Build & Run
🔹 Step-by-Step Guide
1️⃣ Assemble the Circuit

Connect the ultrasonic sensor and servo motor to the Arduino Uno as per the wiring diagram.
Attach the servo motor to the dustbin lid.
### 2️⃣ Upload the Code

Open Arduino IDE and upload the provided sketch.
### 3️⃣ Power the System

Use a 9V battery or USB power supply.
### 4️⃣ Test the Functionality

Place your hand near the sensor and check if the lid opens automatically.
Wait for 3 seconds to see if it closes by itself.
## 📌 Applications
✔️ Smart Home Automation – Can be used in homes for hygienic waste disposal.
✔️ Hospitals & Clinics – Reduces the risk of cross-contamination.
✔️ Public Places – Touchless operation improves cleanliness.
✔️ Restaurants & Offices – Provides a modern and automated waste disposal solution.

## 🔗 Additional Resources
📘 Arduino Official Documentation
📘 HC-SR04 Ultrasonic Sensor Guide
📘 Servo Motor Control with Arduino

## 📌 Future Enhancements
🔹 Add IoT Connectivity – Send data to a smartphone app.
🔹 Battery Efficiency – Use a low-power mode for longer battery life.
🔹 Voice Control – Integrate with Google Assistant or Alexa.

## 📢 Conclusion
The Smart Dustbin is a simple yet effective automation project that reduces human contact with waste, improving hygiene and convenience. With minor enhancements, it can be a fully automated waste management system.