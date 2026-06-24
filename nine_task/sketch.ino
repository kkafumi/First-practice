#define GREEN_PIN 5
#define RED_PIN 9
#define PHOTO_PIN A0

const unsigned long OpenDuration = 4000;  // время прохода человека
bool DoorOpen = false;

void setup() {
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);

  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(RED_PIN, HIGH);
  Serial.begin(115200);  // запустить связь на скорости 115200 бод
}

void loop() {
  int photo_value = analogRead(PHOTO_PIN);  // считываем данные с фоторезистора
  if ((!DoorOpen) && photo_value > 512) {   // дверь закрыта и человек стоит
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    DoorOpen = true;
    Serial.println("DOOR IS OPEN");
    delay(OpenDuration);
    photo_value = analogRead(PHOTO_PIN);  // после ожидания проверяем ушёл ли человек
    if (photo_value > 512) {
      Serial.println("DOOR IS STILL OPEN");
    } else {
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(RED_PIN, HIGH);
      DoorOpen = false;
      Serial.println("DOOR IS CLOSED");
    }
  }
  if (DoorOpen && photo_value <= 512) {  // дверь открылась на прошлом шаге, но человек ушёл только сейчас
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(RED_PIN, HIGH);
    DoorOpen = false;
    Serial.println("DOOR IS CLOSED");
  }
}
