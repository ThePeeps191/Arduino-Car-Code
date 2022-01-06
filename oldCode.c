 
  //adding libraries
#include <IRremote.h>
#include <Servo.h>

  //Declaring pins
const int TRIG =3;
const int ECHO = 2;
const int MOTORF = 4;
const int MOTORB = 5;

  //declaring global variables
int distance;

  //naming parts
Servo sensorServo;
Servo servo;

void setup() {

    //setting up pins
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  servo.attach(6);
  sensorServo.attach (1);
  
   //Introduction
  Serial.println("Science Fair!");
  Serial.println("with Ardiuno R3");
  Serial.println("Starting in 3 . .");
  Serial.println("2 . .");
  Serial.println("1 . .");
  
    //starting monitor
  Serial.begin(9600);

}
//Main code
void loop() {

  //Declaring variables
  static long duration = 0;

   // Activating Sensor, sending sound pulse
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  //receiving duration until pulse recived, converting duration - distance
  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;

  //Cheaking distance and moving safely
  MoveSafely(distance);
      
    }

}

//Semi-guidence movement system
struct MovementType {
  bool movedSafely = false;
  int moveDirection = 0; // 0 straight ahead, -1 left, 1 right
};

bool MoveSafely(int distance) {
  
  //declaring Variables
  bool movedSafely = false;
  const int safeDist = 5;
  int distRight;
  int distLeft;
  int right = 90;
  int left = 270;

  //checking if car is in safedist
  if(distance <= safeDist) {
  
    //checking distance right
    sensorServo.write(right);
    delay(100);
    distRight = distance;
  
    //checking distance left
    sensorServo.write(left);
    delay(100);
    distLeft = distance;
    
  } else {
    int safeMove = safeDist / 2
    
  
    //comparing right to left to see which is greater
    if(distRight >= distLeft) {
      moveDirection = 1; //turn left right 
      String moveFoward();
      movedSafely = true; //tell code that moved safely
      
      //turned right if greater distance and start driving
    } else { //comparing left to rightelse 
       moveDirection = -1; //turn left
       String moveForward();
       movedSafely = true;
       //turn left if greater distance and start driving   
    }//Return else statement
  } else {
    moveForward(); //move foward
  } //Return else statement
  
  return movedSafely;
}// Return MoveSafely








  //Prints data to the monitor
String serial(safeDist) {

int calc = distance - safeDist;
    //Prints current distance to next obstacle and how long until safeDist is reached
  Serial.println("Distance:", distance, "cm");
  Serial.println("Distance left:", calc, "cm");

    //Printing motor speed and how many rotations the motors have turned
  Serial.println("Motor Speed is:", mSpeed, "km/h");
  Serial.println("Motor rotations:", mRotations);
 }

 String moveForward() {
  Serial.println("not dont yet");
 }