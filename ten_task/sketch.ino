#include <Servo.h>

#define SERVO_PIN 3

Servo servop;

bool IsNumber(String str) {
  if (str.length() == 0 || str.length() > 3) { //length не учитывает '\0'
    return false;
  }
  for (int i = 0; i < str.length(); ++i) {
    char symbol = str.charAt(i);
    if (symbol < '0' || symbol > '9') {
      return false;
    }
  }
  return true;
}

void setup() {
  servop.attach(SERVO_PIN);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available()) {
    String str = Serial.readStringUntil('\n');
    if (IsNumber(str)) {
      int number = str.toInt();
      if (number >= 0 && number <= 180) {
        int current_angle = servop.read();
        if (current_angle <= number) {
          for (int i = current_angle; i <= number; ++i) {
            servop.write(i);
            delay(15);
          }
        } else {
          for (int i = current_angle; i >= number; --i) {
            servop.write(i);
            delay(15);
          }
        }
      }
    }
  }
}
