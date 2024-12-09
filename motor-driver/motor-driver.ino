#define dirPin 2
#define stepPin 3

void setup() {
  Serial.begin(9600);

  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);

  digitalWrite(dirPin, LOW);
}

void loop() {
  step(200, 10);
}

void step(int times, int d) {
  for(int i = 0; i < times; i++) {
    digitalWrite(stepPin, HIGH);
    delay(d);
    digitalWrite(stepPin, LOW);
    delay(d);
  }
}