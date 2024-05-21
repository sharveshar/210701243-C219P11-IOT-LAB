#include <Servo.h>


const int trigPin = 11;
const int echoPin = 12;

const int servoPin = 6;

Servo gateServo;

const int distanceThreshold = 10;

void setup() {

  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  
  gateServo.attach(servoPin);

  gateServo.write(0); // 0 degrees
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < distanceThreshold) {
    
    gateServo.write(90);
    Serial.println("Gate Open");
  } else {
   
    gateServo.write(0);
    Serial.println("Gate Closed");
  }


  delay(1000);
}
