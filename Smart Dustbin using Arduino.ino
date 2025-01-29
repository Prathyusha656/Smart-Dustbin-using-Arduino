#include <Servo.h>

// Pin configuration
const int trigPin = 9;    // Trigger pin for ultrasonic sensor
const int echoPin = 10;   // Echo pin for ultrasonic sensor
const int servoPin = 6;   // Servo motor control pin

Servo servoMotor;         // Servo object for controlling the lid

// Function to calculate distance from ultrasonic sensor
long getDistance() {
  digitalWrite(trigPin, LOW);  // Ensure trigPin is LOW
  delayMicroseconds(2);        // Short delay

  digitalWrite(trigPin, HIGH); // Send a pulse to trigger sensor
  delayMicroseconds(10);       // Pulse duration
  digitalWrite(trigPin, LOW);  // End pulse
  
  long duration = pulseIn(echoPin, HIGH);  // Measure the pulse duration
  long distance = duration * 0.0344 / 2;  // Calculate distance in cm
  return distance;
}

void setup() {
  // Initialize pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialize servo motor
  servoMotor.attach(servoPin);
  servoMotor.write(0);  // Start with lid closed

  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  long distance = getDistance();  // Get distance from ultrasonic sensor

  // Print the distance to serial monitor (for debugging)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If object is detected within 15 cm, open the lid
  if (distance > 0 && distance < 15) {
    servoMotor.write(90);  // Open the lid (90 degrees)
    delay(3000);           // Keep lid open for 3 seconds
    servoMotor.write(0);   // Close the lid (0 degrees)
  }

  delay(500);  // Wait for a short time before next sensor reading
}
