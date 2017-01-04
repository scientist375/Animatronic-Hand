//Science week project - Animatronic hand @JNSIBDP
// Code written by Angad_Daryani (Github @scientist375) on 22/2/2015 @ 1:26am
// Program size :5,504 bytes.

#include <Servo.h> //import servo library

//create objects of Servo with name of individual finger
Servo thumb; 
Servo index;
Servo middle;
Servo ring;
Servo pinky;

//Define pin numbers of flex sensors of every finger.P.S- These are the arduino's analog input pins
const int thumbf = 0; 
const int indexf = 1;
const int middlef = 2;
const int ringf = 3;
const int pinkyf = 4;


void setup() 
{ 
  //Set up baud rate at 9600
  Serial.begin(9600);
  
  //use attach function to define digital output pins per servo
  thumb.attach(9);
  index.attach(10);
  middle.attach(11);
  ring.attach(12);
  pinky.attach(13);
} 


void loop() 
{ 
  //create variables for storing the analog input values from individual flex sensors. Ik the names are long.
  int thumbposition,indexposition,middleposition,ringposition,pinkyposition;
  //create variables for storing the angle movement values values (0 to π) of individual servos. Ik the names are long.
  int tservoposition,iservoposition,mservoposition,rservoposition,pservoposition;
 
  //read the analog input values of individual flex sensors. These will be from 0 to 1023.

  thumbposition = analogRead(thumbf);
  indexposition = analogRead(indexf);
  middleposition = analogRead(middlef);
  ringposition = analogRead(ringf);
  pinkyposition = analogRead(pinkyf);
  
  
  tservoposition = map(thumbposition, 600, 900, 0, 180); // map vals of Ai between 600-900 to angle of servo between 0-180
  tservoposition = constrain(tservoposition, 0, 180); // restrict movement of servo from 0-180
  iservoposition = map(indexposition, 600, 900, 0, 180);
  iservoposition = constrain(iservoposition, 0, 180);
  mservoposition = map(middleposition, 600, 900, 0, 180);
  mservoposition = constrain(mservoposition, 0, 180);
  rservoposition = map(ringposition, 600, 900, 0, 180);
  rservoposition = constrain(rservoposition, 0, 180);
  pservoposition = map(pinkyposition, 600, 900, 0, 180);
  pservoposition = constrain(pservoposition, 0, 180);

  // Move servo to that position
  thumb.write(tservoposition);
  index.write(iservoposition);
  middle.write(mservoposition);
  ring.write(rservoposition);
  pinky.write(pservoposition);

  // just for our information, we'll print the values that we are getting as input along with the angle the servo has moved to.
  Serial.print("Thumbreading");
  Serial.print(" | ");
  Serial.print("Indexreading");
  Serial.print(" | ");
  Serial.print("Middlereading");
  Serial.print(" | ");
  Serial.print("Ringreading");
  Serial.print(" | ");
  Serial.print("Pinkyreading");
  Serial.println();
  
  
  Serial.print("     ");
  Serial.print(thumbposition);
  Serial.print("     | ");
  Serial.print("     ");
  Serial.print(indexposition);
  Serial.print("     | ");
  Serial.print("     ");
  Serial.print(middleposition);
  Serial.print("     | ");
  Serial.print("     ");
  Serial.print(ringposition);
  Serial.print("     | ");
  Serial.print("     ");
  Serial.print(pinkyposition);
  Serial.println();
  
  Serial.print("TServoPostion");
  Serial.print(" | ");
  Serial.print("IServoPosition");
  Serial.print(" | ");
  Serial.print(" MServoPosition");
  Serial.print(" | ");
  Serial.print("RServoPosition");
  Serial.print(" | ");
  Serial.print("PServoPosition");
  Serial.println();
  
  Serial.print("     ");
  Serial.print(tservoposition);
  Serial.print("     | ");
  Serial.print("     ");
  Serial.print(iservoposition);
  Serial.print("     | ");
  Serial.print("     ");
  Serial.print(mservoposition);
  Serial.print("     | ");
  Serial.print("     ");
  Serial.print(rservoposition);
  Serial.print("     | ");
  Serial.print("     ");
  Serial.print(pservoposition);
  Serial.println();
  delay(20);  // wait 20milliseconds between servo updates
}
