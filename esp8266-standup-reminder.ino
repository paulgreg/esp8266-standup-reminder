#define LED 15

#define SECOND 1000
#define MINUTE 60 * SECOND
#define HOUR 60 * MINUTE

#define ALARM_1 1 * HOUR
#define ALARM_2 2 * HOUR
#define SLEEP   3 * HOUR


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
  Serial.begin(115200);
  Serial.println("Standup Reminder");
  pinMode(LED, OUTPUT);
  blinkRepeat(5, 100);
}

int state = 0;
int minutes = 0;

void loop() {
  Serial.printf("minutes: %i\n", minutes);
  if (state == 0) {
    if (minutes < ALARM_1) {
      Serial.println("blink one second");
      blink(SECOND);
      delay(MINUTE - SECOND);
    } else {
      Serial.println("set state 1");
      state = 1;
    }
  } else if (state == 1) {
    if (minutes < ALARM_2) {
      Serial.println("turn on LED");
      digitalWrite(LED, HIGH);
      delay(MINUTE);
    } else {
      Serial.println("set state 2");
      state = 2;
    }
  } else if (state == 2) {
     if (minutes < SLEEP) {
      Serial.println("blink for one minute");
      blinkRepeat(60, SECOND);
    } else {
      Serial.println("set state 3");
      state = 3;
    }
  } else if (state == 3) {
     Serial.println("state 3 - sleeping now");
     digitalWrite(LED, LOW);
     ESP.deepSleep(0);
  }
  minutes++;
}
