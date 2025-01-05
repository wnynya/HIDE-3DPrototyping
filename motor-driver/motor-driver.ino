#define dirPin 2
#define stepPin 3

void setup() {
  Serial.begin(9600);

  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);

  digitalWrite(dirPin, LOW);
}

int n = 64;
void loop() {
  int a = analogRead(A0);
  n = map(a, 0, 1023, 0, 127);
  /*if (Serial.available() > 0) {
    int b = Serial.read();
    if (b > 0) {
      n = b;
    }
  }*/
  int d = map(n, 0, 127, 1, 30);
  step(8, d);
}

void step(int times, int d) {
  for(int i = 0; i < times; i++) {
    digitalWrite(stepPin, HIGH);
    delay(d);
    digitalWrite(stepPin, LOW);
    delay(d);
  }
}