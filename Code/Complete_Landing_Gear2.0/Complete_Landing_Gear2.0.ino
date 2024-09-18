#include  <Servo.h>

const int channel6Pin = 2; // Connect Ch6 to digital pin 2
const int channel5Pin = 3; // Connect Ch5 to digital pin 3
const int channel4Pin = 13; // Connect Ch4 to digital pin 13

int steeringValue = 0; //180 deg servo rotations for rotating the landing gear
int channel5Value = 0; //landing gear value (correlates to a switch)
int rudderValue = 0; //rudder value (correlates to the left stick lateral movement)

Servo frontRightServo; // front right leg rotation
Servo frontLeftServo; // front left leg rotation
Servo backLeftServo; // back left leg rotation
Servo backRightServo; //back right leg rotation

Servo backLeftLAC; // back left linear actuator
Servo backRightLAC; // back right linear actuator
Servo frontLeftLAC; // front left linear actuator
Servo frontRightLAC; // front right linear actuator

bool canRotate = true; // boolean that lets middle setting of rotation gear's for loop occur

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  frontRightServo.attach(9);     // attaches the servo on pin 9 to the servo object at front right from pilot's perspective
  frontLeftServo.attach(10);    // attaches the servo on pin 10 to the servo object at front left from pilot's perspective
  backLeftServo.attach(11);    // attaches the servo on pin 11 to the servo object at back left from pilot's perspective
  backRightServo.attach(12);    // attaches the servo on pin 12 to the servo object at back right from pilot's perspective
  
  backLeftLAC.attach(7);        // attaches the linear actuator on pin 7 to the servo object at back left from pilot's perspective
  backRightLAC.attach(6);        // attaches the linear actuator on pin 6 to the servo object at back right from pilot's perspective
  frontLeftLAC.attach(5);        // attaches the linear actuator on pin 5 to the servo object at front left from pilot's perspective
  frontRightLAC.attach(4);        // attaches the linear actuator on pin 4 to the servo object at front right from pilot's perspective

}

void loop() {
  // put your main code here, to run repeatedly:
  steeringValue = pulseIn(channel6Pin, HIGH); // Read pulse duration for Ch6
  channel5Value = pulseIn(channel5Pin, HIGH); // Read pulse duration for Ch5
  rudderValue = pulseIn(channel4Pin, HIGH); //Read pulse duration for Ch4

  /*Serial.print("Channel 6:");
  Serial.println(steeringValue);
  Serial.print("\tChannel 5:");
  Serial.println(channel5Value);
  Serial.print("Can it rotate: ");
  Serial.println(canRotate); */
  Serial.print("Channel 4:");
  Serial.println(rudderValue);

  //Steering
  if ((steeringValue > 1200 && steeringValue < 1600) && canRotate){ //C switch middle position
    /*for (int i = frontRightServo.read(), j = frontLeftServo.read(); i != 115 && j != 65;){
    frontRightServo.write(i); //end goal: 0 / 115
    frontLeftServo.write(180-i); //end goal: 180 / 65
    backLeftServo.write(180-i); //end goal: 180 / 65
    backRightServo.write(i); //end goal: 0 /115
    if (i > 115)
      i--;
    else if (i < 115)
      i++;
    if (j > 65)
      j--;
    else if (j < 65);
      j++;
    delay(30);
    }
    canRotate = false;*/
  } else if (steeringValue < 1200){ //C switch highest position
//    frontRightServo.write(45);
//    frontLeftServo.write(135);
//    backLeftServo.write(165);
//    backRightServo.write(55);
    frontRightServo.write(20);
    frontLeftServo.write(165);
    backLeftServo.write(25);
    backRightServo.write(15);
  } else { //C switch lowest position
    frontRightServo.write(110);
    frontLeftServo.write(72);
    backLeftServo.write(115);
    backRightServo.write(100);
  }

  if (steeringValue <= 1200 || steeringValue >= 1600)
      canRotate = true;
    // Linear Actuators
  if (channel5Value > 1850) {
    backLeftLAC.writeMicroseconds(1200);
    backRightLAC.writeMicroseconds(1200);
    frontLeftLAC.writeMicroseconds(1200);
    frontRightLAC.writeMicroseconds(1200);
  } else if ((channel5Value > 1450) && (channel5Value < 1500)) {
    backLeftLAC.writeMicroseconds(1550);
    backRightLAC.writeMicroseconds(1590);
    frontLeftLAC.writeMicroseconds(1790);
    frontRightLAC.writeMicroseconds(1800);
  } else if(channel5Value < 1200)  {
    backLeftLAC.writeMicroseconds(1795);
    backRightLAC.writeMicroseconds(1785);
    frontLeftLAC.writeMicroseconds(1800);
    frontRightLAC.writeMicroseconds(1775);
  }

  //makeshift rudders
  int smoothedRuddValue = map(rudderValue, 1000, 2100, 10, 21);

  if (smoothedRuddValue > 18)
    smoothedRuddValue = 21;
  
  int sentRuddValue = map(smoothedRuddValue,10,21,50,95);
  int sentRuddValueInvert = map(smoothedRuddValue, 10,21,40,0);

  if (steeringValue >= 1200) {
  frontRightServo.write(sentRuddValue+45);
  frontLeftServo.write(sentRuddValue+10);
  }
  
  Serial.println(smoothedRuddValue);
  Serial.println(sentRuddValue);
  Serial.println(sentRuddValueInvert);
}
