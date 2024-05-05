#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver hexapodLeg1 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver hexapodLeg2 = Adafruit_PWMServoDriver(0x41);

#define servoMIN 150
#define servoMAX 600

// Pins mapping for leg servos under driver 1
const int legPins1[6][3] = {
  {0, 1, 2},  // Leg 1: Coxa, Femur, Tibia
  {3, 4, 5},  // Leg 2: Coxa, Femur, Tibia
  {6, 7, 8}   // Leg 3: Coxa, Femur, Tibia
};

// Pins mapping for leg servos under driver 2
const int legPins2[6][3] = {
  {0, 1, 2},  // Leg 4: Coxa, Femur, Tibia
  {3, 4, 5},  // Leg 5: Coxa, Femur, Tibia
  {6, 7, 8}   // Leg 6: Coxa, Femur, Tibia
};

void setup() {
  Serial.begin(9600);
  hexapodLeg1.begin();
  hexapodLeg1.setPWMFreq(60);

  hexapodLeg2.begin();
  hexapodLeg2.setPWMFreq(60);
}

// --------------------------Code Here!!!--------------------------------------------------------------------------------------------------------------------------->
void loop() {
  // Your main code logic here
  turn_robot();
}

// it will turn the robots body
void turn_robot() {
  int time_delay = 500;
  // Turn
  for (int i = 0; i < 3; i++) {
    moveLeg(hexapodLeg1, i, 45, 100, 15);
    moveLeg(hexapodLeg2, i, 45, 100, 15);
  }
  delay(time_delay);

  // Return
  for (int i = 0; i < 3; i++) {
    moveLeg(hexapodLeg1, i, 90, 100, 15);
    moveLeg(hexapodLeg2, i, 90, 100, 15);
  }
  delay(time_delay);

  // Return
  for (int i = 0; i < 3; i++) {
    moveLeg(hexapodLeg1, i, 135, 100, 15);
    moveLeg(hexapodLeg2, i, 135, 100, 15);
  }
  delay(time_delay);
}

// marching robot
void march_robot(){
  int time_delay = 500;
  // Return
  for (int i = 0; i < 3; i++) {
    moveLeg(hexapodLeg1, i, 90, 100, 15);
    moveLeg(hexapodLeg2, i, 90, 100, 15);
  }
  delay(time_delay);

  // Return
  for (int i = 0; i < 3; i++) {
    moveLeg(hexapodLeg1, i, 135, 100, 15);
    moveLeg(hexapodLeg2, i, 135, 100, 15);
  }
  delay(time_delay);
}

void moveLegMarch(Adafruit_PWMServoDriver &driver, int legIndex, int coxa, int femur, int tibia){
  for(int i = 0; i < 3; i++){
    driver.setPWM(legPins1[legIndex][i], 0, (i == 0)? angleToMicroseconds(coxa):(i ==1)?angleToMicroseconds(femur):angleToMicroseconds(tibia));
  }
}

// This wil make the leg to move for the rotating pitch
void moveLeg(Adafruit_PWMServoDriver &driver, int legIndex, int coxa, int femur, int tibia) {
  for (int i = 0; i < 3; i++) {
    driver.setPWM(legPins1[legIndex][i], 0, (i == 0) ? angleToMicroseconds(coxa) : (i == 1) ? angleToMicroseconds(femur) : angleToMicroseconds(tibia));
  }
}
  
int angleToMicroseconds(double angle) {
  double val = servoMIN + (((servoMAX - servoMIN) / 180.0) * angle);
  return (int)val;
}
