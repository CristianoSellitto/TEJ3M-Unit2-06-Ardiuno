/*
  Created by Cristiano S
  Created in March 2023

  Uses a distance sensor to find the distance of an object in centimeters
*/

int trigPin = 2;
int echoPin = 3;
float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Set trigPin as an output
  pinMode(echoPin, INPUT);  // Set echoPin as an input
  Serial.begin(9600);       // Begin the serial monitor
}

void loop() {
  digitalWrite(trigPin, LOW); // Send a signal
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); // Receive a signal
  distance = (duration*.0343) / 2;   // Calculate distance
  // Print to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);
}
