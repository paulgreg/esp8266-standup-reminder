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

int state = 0;
int minutes = 0;

void loop() {
  minutes++;
  if (state == 0) {
    delay(MINUTE - SECOND);
    if (minutes < 60) blink(SECOND);
    else state = 1;
  }
  if (state == 1) {
    if (minutes < 120) blinkRepeat(60, SECOND);
    else state = 2;
  }
  if (state == 2) {
     digitalWrite(LED, LOW);
     ESP.deepSleep(0);
  }
}
