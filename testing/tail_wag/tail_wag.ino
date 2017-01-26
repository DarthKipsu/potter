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
  // TODO:
  // Use millis() instead of delay so the board does not wait until
  // done and can maintain cencor activity.
  // example: https://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
  
  for (int i = 0; i <= degrees / 2; i += 5) {
    tail.write(90 - i);
    delay(5 * speed);
  }
  for (int i = 0; i <= degrees; i += 5) {
    tail.write(90 - degrees / 2 + i);
    delay(5 * speed);
  }
  for (int i = degrees / 2; i >= 0; i -= 5) {
    tail.write(90 + i);
    delay(5 * speed);
  }
}

