/*servo motor driver board control
 * https://srituhobby.com
 */
 
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver srituhobby = Adafruit_PWMServoDriver();

#define servoMIN 150
#define servoMAX 600

byte servo = 0;

void setup() {
  Serial.begin(9600);
  srituhobby.begin();
  srituhobby.setPWMFreq(60);
}

void loop() {

  for (int pulse = servoMIN; pulse < servoMAX; pulse++) {
    srituhobby.setPWM(servo, 0, pulse);
  }
  delay(100);

  for (int pulse = servoMAX; pulse > servoMIN; pulse--) {
    srituhobby.setPWM(servo, 0, pulse);
  }
  delay(100);

  servo++;
  if (servo > 6) {
    servo = 0;
  }
}