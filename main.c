// Adding Libraries
#include <IRremote.h>
#include <Servo.h>

// Declaring Variables
Servo sensorServo;
Servo ejectServos;

struct SensorStructure {const int TRIG = 1; const int ECHO = 2; };
struct SensorStructure Sensors; // Global Variable

struct MotorsStructure {
  const int LFM = 3; const int LBM = 4; const int RFM = 5;
  const int RBM = 6; const int RS = A2; const int LS = A1; 
}; 
const struct MotorsStructure Motors;

struct AnglesStructures {
  const int right = 90; const int foward = 0; const int left = 270; const int backward = 120; 
}; 
struct AnglesStructures Angles; // Global variable
  
struct DistancesStructure {
  float distF; float distL; float distR; float distB; 
}; 
struct DistancesStructure Distances; // Global variable

void setup() { 
  // Seting Up Pins
  pinMode(Sensors.TRIG, OUTPUT);
  pinMode(Sensors.ECHO, INPUT);
  pinMode(Motors.LFM, OUTPUT);
  pinMode(Motors.LBM, OUTPUT);
  pinMode(Motors.RFM, OUTPUT);
  pinMode(Motors.RBM, OUTPUT);
  pinMode(Motors.RS, OUTPUT);
  pinMode(Motors.LS, OUTPUT);
  sensorServo.attach(7);
  ejectServos.attach(8);

  //Introduction
  Serial.println("Science Fair!");
  Serial.println("with Ardiuno R3");
  Serial.println("Starting in 3 . .");
  Serial.println("2 . .");
  Serial.println("1 . .");
  
  //starting monitor
  Serial.begin(9600);
}

void loop() {
  
  //Declaring variables
  char direction = 'X';
  const float safeDistance = 3.0f ;
  static float distance;
  bool sensorSafe;
 
  sensorSafe = SensorAct(distance, safeDistance);
  MotorAct(direction);
}
 
bool SensorAct(float distance, float safe) {
  //Declaring variables
  static float duration = 0;
  bool sensorSafe = false; // default value of false
  
  Distances.distF = distance;
 
  // Activating Sensor, sending sound pulse
  digitalWrite(Sensors.TRIG, LOW);
  digitalWrite(Sensors.TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sensors.TRIG, LOW); 

  //receiving duration until pulse recived, converting duration - distance
  duration = pulseIn(Sensors.ECHO, HIGH);
  distance = duration * 0.034 / 2;

  if  (distance >= safe) {
    
    sensorServo.write(Angles.right);
    
    digitalWrite(Sensors.TRIG, LOW);
    digitalWrite(Sensors.TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(Sensors.TRIG, LOW); 
    
    duration = pulseIn(Sensors.ECHO, HIGH);
    Distances.distR = duration * 0.034 / 2;

    sensorServo.write(Angles.left);
    
    digitalWrite(Sensors.TRIG, LOW);
    digitalWrite(Sensors.TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(Sensors.TRIG, LOW); 
    
    duration = pulseIn(Sensors.ECHO, HIGH);
    Distances.distL = duration * 0.034 / 2;
    
    sensorServo.write(Angles.backward);

    digitalWrite(Sensors.TRIG, LOW);
    digitalWrite(Sensors.TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(Sensors.TRIG, LOW); 
    
    duration = pulseIn(Sensors.ECHO, HIGH);
    
    Distances.distB = duration * 0.034 / 2;
    
  }

}
void MotorAct(char direction) {
  float MS;
  switch (direction) {
    case 'l': // left
      digitalWrite(Motors.RFM, HIGH);
      digitalWrite(Motors.LBM, HIGH);
      break;
    case 'r': // right
      digitalWrite(Motors.RBM, HIGH);
      digitalWrite(Motors.LFM, HIGH);
      break;
   case 'f': // forward
      digitalWrite(Motors.RFM, HIGH);
      digitalWrite(Motors.LFM, HIGH);
      break;
    case 'b': // back
      digitalWrite(Motors.RBM, HIGH);
      digitalWrite(Motors.LBM, HIGH);
      break;
    case 'X': // testing
      // This only happens when running tests
      printf("Received an X");
      break;
    default:
      analogWrite(Motors.RS, MS);
      analogWrite(Motors.LS, MS);
      break;
  }

  // do whatever else I want here.
  
}