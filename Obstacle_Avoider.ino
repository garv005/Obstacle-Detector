int m11 = 5;  // Motor 1 forward
int m12 = 4;  // Motor 1 backward
int m21 = 7;  // Motor 2 forward
int m22 = 8;  // Motor 2 backward
long duration;
int distance;
int trigPin = 3, echoPin = 2;
int redLED = 9;  // Red LED for stop
int greenLED = 10;  // Green LED for moving

void setup() {
  Serial.begin(9600);

  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(redLED, OUTPUT);  // Red LED pin
  pinMode(greenLED, OUTPUT);  // Green LED pin
}

void loop() {
  // Measure distance using the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Convert time to distance (cm)
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 50) {
    moveForward();
    digitalWrite(greenLED, HIGH);  // Turn on Green LED when moving
    digitalWrite(redLED, LOW);     // Turn off Red LED
  } 
  else {
    stopCar();
    digitalWrite(greenLED, LOW);   // Turn off Green LED when stopped
    digitalWrite(redLED, HIGH);    // Turn on Red LED when stopped
    delay(500); // Brief pause before turning
    turnLeft();
    delay(500); // Turning duration
  }
}

void moveForward() {
  digitalWrite(m11, HIGH);
  digitalWrite(m12, LOW);
  digitalWrite(m21, HIGH);
  digitalWrite(m22, LOW);
}

void stopCar() {
  digitalWrite(m11, LOW);
  digitalWrite(m12, LOW);
  digitalWrite(m21, LOW);
  digitalWrite(m22, LOW);
}

void turnLeft() {
  digitalWrite(m11, LOW);
  digitalWrite(m12, HIGH); // Reverse left motor
  digitalWrite(m21, HIGH);
  digitalWrite(m22, LOW);  // Right motor forward
}
