volatile int IN1;  // for forward of left side
volatile int IN2;  //  for backward of left side
volatile int IN3;  // for forward of right side
volatile int IN4;  //  for backward of right side
volatile int s1;   // s1 is leftest sensor
volatile int s2;
volatile int s3;
volatile int s4;
volatile int s5;  // s5 is rightest sensor
volatile int E12;
volatile int E34;
volatile int counter;

void left_side_forward(int speed) {
  // Left
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  analogWrite(E12, speed);
}

void right_side_forward(int speed) {
  // Right
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
  analogWrite(E34, speed * 0.86);
}

void left_side_backward(int speed) {
  // Left
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  analogWrite(E12, speed);
}

void right_side_backward(int speed) {
  // Right
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
  analogWrite(E34, speed);
}

void forward(int speed) {
  left_side_forward(speed);
  right_side_forward(speed);
}

void stop() {
  left_side_forward(0);
  right_side_forward(0);
}

void left(int speed, int numOfOffSensors) {
  if (numOfOffSensors < 2) {
    left_side_forward((speed * (2 - numOfOffSensors)) / 2);
    right_side_forward(speed);
  } else {
    left_side_backward((speed * (numOfOffSensors - 2)) / 2);
    right_side_forward(speed);
  }
}

void right(int speed, int numOfOffSensors) {
  if (numOfOffSensors < 2) {
    left_side_forward(speed);
    right_side_forward((speed * (2 - numOfOffSensors)) / 2);
  } else {
    left_side_forward(speed);
    right_side_backward((speed * (numOfOffSensors - 2)) / 2);
  }
}

void setup() {
  IN1 = 13;
  IN2 = 12;
  IN3 = 11;
  IN4 = 6;

  E12 = 9;
  E34 = 10;

  s1 = 2;
  s2 = 3;
  s3 = 4;
  s4 = 5;
  s5 = 7;

  counter = 0;

  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(E12, OUTPUT);
  pinMode(E34, OUTPUT);

  Serial.begin(9600);  // open the serial port at 9600 bps:
}

void loop() {
  //Serial.print("s1 ");
  //Serial.println(digitalRead(s1));
  //Serial.print("s2 ");
  //Serial.println(digitalRead(s2));
  //Serial.print("s3 ");
  //Serial.println(digitalRead(s3));
  //Serial.print("s4 ");
  //Serial.println(digitalRead(s4));
  //Serial.print("s5 ");
  //Serial.println(digitalRead(s5));
  if(counter < 5) {
    delay(1000);
    counter += 1;
  } else {
      if (
    digitalRead(s1) == 1 && digitalRead(s2) == 0 && digitalRead(s3) == 0 && digitalRead(s4) == 0 && digitalRead(s5) == 1) {
    forward(115);
    delay(50);
  }
  if (
    digitalRead(s1) == 1 && digitalRead(s2) == 0 && digitalRead(s3) == 0 && digitalRead(s4) == 1 && digitalRead(s5) == 1) {
    left(200 * 2 / 3, 1);
    delay(50);
  }
  if (
    digitalRead(s1) == 1 && digitalRead(s2) == 0 && digitalRead(s3) == 1 && digitalRead(s4) == 1 && digitalRead(s5) == 1) {
    left(200 * 2 / 3, 2);
    delay(50);
  }
  if (
    digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 1 && digitalRead(s4) == 1 && digitalRead(s5) == 1) {
    left(200 * 1 / 3, 3);
    delay(50);
  }
  if (
    digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 1 && digitalRead(s4) == 1 && digitalRead(s5) == 0) {
    left(200 * 2 / 3, 4);
    delay(50);
  }
  if (
    digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 0 && digitalRead(s4) == 0 && digitalRead(s5) == 1) {
    left(200 * 2 / 3, 4);
    delay(100);
  }
  if (
    digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 0 && digitalRead(s4) == 1 && digitalRead(s5) == 1) {
    left(200 * 2 / 3, 4);
    delay(100);
  }
  if (
    digitalRead(s1) == 1 && digitalRead(s2) == 1 && digitalRead(s3) == 0 && digitalRead(s4) == 0 && digitalRead(s5) == 1) {
    right(200 * 2 / 3, 1);
    delay(50);
  }
  if (
    digitalRead(s1) == 1 && digitalRead(s2) == 1 && digitalRead(s3) == 1 && digitalRead(s4) == 0 && digitalRead(s5) == 1) {
    right(200 * 2 / 3, 2);
    delay(50);
  }
  if (
    digitalRead(s1) == 1 && digitalRead(s2) == 1 && digitalRead(s3) == 1 && digitalRead(s4) == 0 && digitalRead(s5) == 0) {
    right(200 * 2 / 3 , 3);
    delay(50);
  }
  if (
    digitalRead(s1) == 0 && digitalRead(s2) == 1 && digitalRead(s3) == 1 && digitalRead(s4) == 0 && digitalRead(s5) == 0) {
    right(200 * 2 / 3, 4);
    delay(50);
  }
  if (
    digitalRead(s1) == 1 && digitalRead(s2) == 0 && digitalRead(s3) == 0 && digitalRead(s4) == 0 && digitalRead(s5) == 0) {
    right(200 * 2 / 3, 4);
    delay(100);
  }
  if (
    digitalRead(s1) == 1 && digitalRead(s2) == 1 && digitalRead(s3) == 0 && digitalRead(s4) == 0 && digitalRead(s5) == 0) {
    right(200 * 2 / 3, 4);
    delay(100);
  }
  if (
    digitalRead(s1) == 0 && digitalRead(s2) == 0 && digitalRead(s3) == 0 && digitalRead(s4) == 0 && digitalRead(s5) == 0) {
    stop();
  }
  }
}
