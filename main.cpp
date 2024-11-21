int blue = 30;
int green = 31;

int LMspeed = 11;
int LMdir = 13;
int RMspeed = 3;
int RMdir = 12;

int trigPin = 48;
int echoPin = 49;
long duration, distance;

void setup() {
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);

  pinMode(LMspeed, OUTPUT);
  pinMode(LMdir, OUTPUT);
  pinMode(RMspeed, OUTPUT);
  pinMode(RMdir, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  forward(60);
  if (checkDistance() <= 40) {
    Rturn();
    digitalWrite(blue, HIGH);
    delay(1000);
    digitalWrite(blue, LOW);
  }

  for (int i = 0; i < 2; i++) {
    greenBlink();
  }

  // Halt the robot
  while (true) {
    delay(1000);
  }
}

long checkDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.034; // cm
  return distance;
}

void Rturn() {
  analogWrite(LMspeed, 255);
  digitalWrite(LMdir, LOW);
  analogWrite(RMspeed, 0);
  digitalWrite(RMdir, LOW);
  delay(500);
}

void greenBlink() {
  digitalWrite(green, HIGH);
  delay(1000);
  digitalWrite(green, LOW);
  delay(1000);
}

void forward(int speed) {
  analogWrite(LMspeed, speed);
  digitalWrite(LMdir, LOW);
  analogWrite(RMspeed, speed);
  digitalWrite(RMdir, LOW);
  delay(1000);
}
