const int led = 0;
const int pin = 2;
void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(pin, INPUT);
}

void loop() {
  int state = digitalRead(pin);
  digitalWrite(led, state);
  delay(1000);
}
