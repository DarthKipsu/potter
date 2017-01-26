#include <Servo.h>
Servo elbow;
Servo knee;

void setup() {
  elbow.attach(12);
  knee.attach(13);
}

void loop() {
  elbow.write(90);
  knee.write(0);
  delay(2000);
  elbow.write(180);
  knee.write(90);
  delay(500);
  knee.write(0);
  delay(250);
  elbow.write(45);
  delay(500);
}
