#include <Servo.h>
Servo tail;

void setup() {
  tail.attach(3);
}

void loop() {
  wagTailSlow(2, 60);
  delay(500);
  wagTailSlow(3, 120);
  delay(2000);
}

void wagTailSlow(int speed, int degrees) {
  for (int i = 0; i < degrees / 2; i++) {
    tail.write(90 - i);
    delay(speed);
  }
  for (int i = 0; i < degrees; i++) {
    tail.write(90 - degrees / 2 + i);
    delay(speed);
  }
  for (int i = degrees / 2; i >= 0; i--) {
    tail.write(90 + i);
    delay(speed);
  }
}

