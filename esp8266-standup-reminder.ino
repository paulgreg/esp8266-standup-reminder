#define LED 15
#define BUTTON 13

#define SECOND 1000
#define MINUTE 60 * SECOND
#define HOUR 60 * MINUTE

void blink(int d) {
  digitalWrite(LED, HIGH);
  delay(d);
  digitalWrite(LED, LOW);
  delay(d);
}

void blinkRepeat(int nb, int d) {
  for(int i = 0; i < nb; i++) blink(d);
}

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  blinkRepeat(5, 100);
}

int minutes = 0;

void loop() {
  delay(MINUTE);
  minutes++;
  if (minutes > 120) {
    digitalWrite(LED, LOW);
    ESP.deepSleep(0);
  } else if (minutes > 60) {
    digitalWrite(LED, HIGH);
  } else {
    blink(SECOND);
  }
}
