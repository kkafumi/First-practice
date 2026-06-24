#define GREEN_PIN 5
#define RED_PIN 9
#define PHOTO_PIN A0

const unsigned long OpenDuration = 4000;

void setup() {
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);

  digitalWrite(GEEN_PIN, LOW);
  digitalWrite(RED_PIN, HIGH);
  Serial.begin(115200);
}

void loop() {
  if (analogRead(PHOTO_PIN) > 512) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    Serial.println("DOOR IS OPEN");
    delay(OpenDuration);
  } else {
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(RED_PIN, HIGH);
    Serial.println("DOOR IS CLOSED");
  }
}
