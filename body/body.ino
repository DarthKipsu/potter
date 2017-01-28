#include <Servo.h>
Servo back_leg_right;
Servo back_leg_left;
Servo front_leg_right;
Servo front_leg_left;

void setup() {
  back_leg_right.attach(2);
  back_leg_left.attach(3);
  front_leg_right.attach(12);
  front_leg_left.attach(13);
}

void loop() {
  stand();
  delay(2000);
  turn_left(5);
  delay(1000);
  turn_right(5);
}

