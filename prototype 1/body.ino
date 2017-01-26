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

bool initialized;

enum State: byte {
  STANDING,
};

State state;

void setup() {
  rf_elbow.attach(12);
  rf_knee.attach(13);
  lf_elbow.attach(9);
  lf_knee.attach(8);
  lb_elbow.attach(10);
  lb_knee.attach(11);
  rb_elbow.attach(7);
  rb_knee.attach(6);

  pinMode(tiltSensor, INPUT);
  pinMode(crashLed, OUTPUT);
  
  state = STANDING;
  initialized = false;
  digitalWrite(crashLed, HIGH);

  while (!initialized) {
    if (shouldInitialize()) {
      initialize();
    } 
  }
}

void loop() {
  delay(2000);
  stand();
}

bool shouldInitialize() {
  return !initialized && digitalRead(tiltSensor) == LOW;
}

void initialize() {
  stand();
  state = STANDING;
  digitalWrite(crashLed, LOW);
  initialized = true;
  delay(1000);
}

void stand() {
  lf_elbow.write(80);
  lf_knee.write(20);
  rf_elbow.write(90);
  rf_knee.write(20);
  
  rb_elbow.write(90);
  rb_knee.write(20);
  lb_elbow.write(90);
  lb_knee.write(20);
}

void raiseLeftFrontFoot() {
  int elbow = 70;
  int knee = 20;
  for (int i = 0; i < 50; i++) {
    lf_elbow.write(elbow + i);
    lf_knee.write(knee + i);
    delay(15);
  }
}

