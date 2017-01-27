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
  raise_left_front_leg();
}

void stand() {
  back_leg_right.write(90);
  back_leg_left.write(90);
  front_leg_right.write(90);
  front_leg_left.write(90);
}

void raise_left_front_leg() {
  for (int i = 0; i < 30; i++) {
    front_leg_left.write(90 - i);
    if (i % 5 == 0) {
      back_leg_left.write(90 - i / 5);
    }
    delay(10);
  }
  delay(500);
  for (int i = 30; i > 0; i--) {
    front_leg_left.write(90 - i);
    if (i % 5 == 0) {
      back_leg_left.write(90 - i / 5);
    }
    delay(10);
  }
}

