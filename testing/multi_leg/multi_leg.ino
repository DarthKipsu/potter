#include <Servo.h>
Servo rf_elbow; // Right front elbow
Servo rf_knee;  // Right front knee
Servo lf_elbow; // Left front elbow
Servo lf_knee;  // Left front knee

Servo lb_elbow; // Left back elbow
Servo lb_knee;  // Left back knee
Servo rb_elbow; // Right back elbow
Servo rb_knee;  // Right back knee

void setup() {
  rf_elbow.attach(12);
  rf_knee.attach(13);
  lf_elbow.attach(9);
  lf_knee.attach(8);
  lb_elbow.attach(10);
  lb_knee.attach(11);
  rb_elbow.attach(7);
  rb_knee.attach(6);
}

void loop() {
  rf_elbow.write(90);
  rf_knee.write(20);
  lf_elbow.write(90);
  lf_knee.write(20);
  lb_elbow.write(90);
  lb_knee.write(20);
  rb_elbow.write(90);
  rb_knee.write(20);
  delay(2000);
  rf_elbow.write(150);
  rf_knee.write(110);
  lf_elbow.write(60);
  lb_elbow.write(150);
  lb_knee.write(110);
  rb_elbow.write(60);
  delay(500);
  rf_knee.write(0);
  lb_knee.write(0);
  delay(250);
  rf_elbow.write(60);
  lf_elbow.write(150);
  lf_knee.write(110);
  lb_elbow.write(60);
  rb_elbow.write(150);
  rb_knee.write(110);
  delay(500);
  lf_knee.write(0);
  rb_knee.write(0);
  delay(250);
}
