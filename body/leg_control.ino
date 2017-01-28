/** Makes the robot stand in upright position */
void stand() {
  back_leg_right.write(90);
  back_leg_left.write(90);
  front_leg_right.write(90);
  front_leg_left.write(90);
}

/** Moves the robot forwards given number of steps */
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

void turn_left(int steps) {
  for (int step = 0; step < steps; step++) {
    withdraw_front_leg_left(20);
    for (int i = 0; i < 30; i++) {
      lift_back_leg_right(i);
      lift_back_leg_left(i);
      withdraw_front_leg_right(i);
      delay(2);
    }
    delay(100);
    for (int i = 30; i > 0; i--) {
      lift_back_leg_right(i);
      lift_back_leg_left(i);
      withdraw_front_leg_right(i);
      delay(2);
    }
    for (int i = 0; i < 30; i++) {
      lift_front_leg_right(i);
      withdraw_back_leg_right(i);
      withdraw_back_leg_left(i);
      delay(2);
    }
    delay(100);
    for (int i = 30; i > 0; i--) {
      lift_front_leg_right(i);
      withdraw_back_leg_right(i);
      withdraw_back_leg_left(i);
      delay(2);
    }
    stand();
    delay(10);
  }
}

void turn_right(int steps) {
  for (int step = 0; step < steps; step++) {
    withdraw_front_leg_right(20);
    for (int i = 0; i < 30; i++) {
      lift_back_leg_right(i);
      lift_back_leg_left(i);
      withdraw_front_leg_left(i);
      delay(2);
    }
    delay(100);
    for (int i = 30; i > 0; i--) {
      lift_back_leg_right(i);
      lift_back_leg_left(i);
      withdraw_front_leg_left(i);
      delay(2);
    }
    for (int i = 0; i < 30; i++) {
      lift_front_leg_left(i);
      withdraw_back_leg_right(i);
      withdraw_back_leg_left(i);
      delay(2);
    }
    delay(100);
    for (int i = 30; i > 0; i--) {
      lift_front_leg_left(i);
      withdraw_back_leg_right(i);
      withdraw_back_leg_left(i);
      delay(2);
    }
    stand();
    delay(10);
  }
}

/** Makes the robot sit down */
void sit() {
  stand();
  lift_back_leg_right(90);
  lift_back_leg_left(90);
  withdraw_front_leg_right(40);
  withdraw_front_leg_left(40);
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

