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
  step_forward(2);
}

void stand() {
  back_leg_right.write(90);
  back_leg_left.write(90);
  front_leg_right.write(90);
  front_leg_left.write(90);
}

void step_forward(int steps) {
  for (int step = 0; step < steps; step++) {
    for (int i = 0; i < 30; i++) {
      step_with_left_leg(i);
      delay(10);
    }
    delay(100);
    for (int i = 30; i > 0; i--) {
      step_with_left_leg(i);
      delay(10);
    }
    stand();
    for (int i = 0; i < 30; i++) {
      step_with_right_leg(i);
      delay(10);
    }
    delay(100);
    for (int i = 30; i > 0; i--) {
      step_with_right_leg(i);
      delay(10);
    }
    stand();
    delay(50);
  }
}

/** Moves left front and right back leg forwards to given degrees and
/*  withdraws the other two legs to the same degree. **/
void step_with_left_leg(int degree) {
  lift_front_leg_left(degree);
  lift_back_leg_right(degree);
  withdraw_front_leg_right(degree);
  withdraw_back_leg_left(degree);
}

/** Moves right front and left back leg forwards to given degrees and
/*  withdraws the other two legs to the same degree. **/
void step_with_right_leg(int degree) {
  lift_front_leg_right(degree);
  lift_back_leg_left(degree);
  withdraw_front_leg_left(degree);
  withdraw_back_leg_right(degree);
}

void lift_front_leg_right(int degree) {
  front_leg_right.write(90 + degree);
}

void lift_front_leg_left(int degree) {
  front_leg_left.write(90 - degree);
}

void lift_back_leg_right(int degree) {
  back_leg_right.write(90 + degree);
}

void lift_back_leg_left(int degree) {
  back_leg_left.write(90 - degree);
}

void withdraw_front_leg_right(int degree) {
  front_leg_right.write(90 - degree);
}

void withdraw_front_leg_left(int degree) {
  front_leg_left.write(90 + degree);
}

void withdraw_back_leg_right(int degree) {
  back_leg_right.write(90 - degree);
}

void withdraw_back_leg_left(int degree) {
  back_leg_left.write(90 + degree);
}

