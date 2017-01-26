#include <Servo.h>
#include <Arduino.h>
Servo rf_elbow; // Right front elbow
Servo rf_knee;  // Right front knee
Servo lf_elbow; // Left front elbow
Servo lf_knee;  // Left front knee

Servo lb_elbow; // Left back elbow
Servo lb_knee;  // Left back knee
Servo rb_elbow; // Right back elbow
Servo rb_knee;  // Right back knee

const int tiltSensor = 53;
const int crashLed = 22;

enum State: byte {
  FALLEN,
  STANDING,
};

State state;

void setup() {
  lf_elbow.attach(12);
  lf_knee.attach(13);
  rf_elbow.attach(9);
  rf_knee.attach(8);
  rb_elbow.attach(10);
  rb_knee.attach(11);
  lb_elbow.attach(7);
  lb_knee.attach(6);

  pinMode(tiltSensor, INPUT);
  pinMode(crashLed, OUTPUT);
  
  state = FALLEN; // requires human to place the robot standing at first
}

void loop() {
  if (state == FALLEN && digitalRead(tiltSensor) == LOW) {
    stand();
    if (digitalRead(tiltSensor) == LOW) {
      state = STANDING;
    }
  } else if (digitalRead(tiltSensor) == HIGH) {
    state = FALLEN;
  }

  if (state == FALLEN) {
    digitalWrite(crashLed, HIGH);
  } else {
    digitalWrite(crashLed, LOW);
  }
}

void stand() {
  rf_elbow.write(70);
  rf_knee.write(20);
  lf_elbow.write(90);
  lf_knee.write(20);
  
  lb_elbow.write(80);
  lb_knee.write(20);
  rb_elbow.write(80);
  rb_knee.write(20);
}

