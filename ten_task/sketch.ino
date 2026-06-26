#include <Servo.h>

#define SERVO_PIN 3

Servo servop;

void setup() {
  servop.attach(SERVO_PIN);
  Serial.begin(115200);
}

void loop() {
  if(Serial.available()){
    String str = Serial.readStringUntil('\n');
    int number = str.toInt();
    if (number >= 0 && number <= 180){
      int current_angle = servop.read();
      for(int i = current_angle; i <= number; ++i){
        servop.write(i);
        delay(15);
      }
    }
  }
}
