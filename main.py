"""
Rusty main.c into main.py translation
😭😭😭😭😭😭😭😭😢😢😢😢😢😢😞😞😞😞😟
"""



# Adding Libraries
#include <IRremote.h>
#include <Servo.h>

# Declaring Pins
class sensor():
	def __init__(self):
		self.TRIG = 1
		self.ECHO = 2

class motors():
	def __init__(self):
		self.lfm = 3
    self.lbm = 4 
  	self.rfm = 5
  	self.rbm = 6

sensorServo = Servo()
ejectServoF = Servo()
ejectServoB = Servo()


def setup():
	# Setting Up Pins
	pinMode(TRIG, OUTPUT)
  pinMode(ECHO, INPUT)
  pinMode(motors, OUTPUT)
  sensorServo.attach(7)
  ejectServos.attach(8)

  # Introduction
  Serial.println("Science Fair!")
  Serial.println("with Ardiuno R3")
  Serial.println("Starting in 3 . .")
  Serial.println("2 . .")
  Serial.println("1 . .")
  
  # Starting Monitor
  Serial.begin(9600)

def loop():
	pass