#include <Servo.h>
Servo rf_elbow; // Right front elbow
Servo rf_knee;  // Right front knee

Servo lb_elbow; // Left back elbow
Servo lb_knee;  // Left back knee

void setup() {
  rf_elbow.attach(12);
  rf_knee.attach(13);
  lb_elbow.attach(10);
  lb_knee.attach(11);
}

void loop() {
  rf_elbow.write(90);
  rf_knee.write(0);
  lb_elbow.write(90);
  lb_knee.write(0);
  delay(2000);
  rf_elbow.write(150);
  rf_knee.write(90);
  lb_elbow.write(150);
  lb_knee.write(90);
  delay(500);
  rf_knee.write(0);
  lb_knee.write(0);
  delay(250);
  rf_elbow.write(45);
  lb_elbow.write(45);
  delay(500);
}
