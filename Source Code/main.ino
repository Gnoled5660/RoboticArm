#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int pinsUp[]   = {2, 4, 6, 8, 10}; 
int pinsDown[] = {3, 5, 7, 9, 11};

int stopValue = 350;
int val = 50; 

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);

  for (int i = 0; i < 5; i++) {
    pinMode(pinsUp[i], INPUT_PULLUP);
    pinMode(pinsDown[i], INPUT_PULLUP);
  }

  for (int i = 0; i < 5; i++){
  pwm.setPWM(i, 0, stopValue);
  }
  
  delay(2000);
}

void loop() {
  for (int i = 0; i < 5; i++) {
    
    if (digitalRead(pinsUp[i]) == LOW) {
      pwm.setPWM(0, 0, stopValue + val);
    } 
    
    else if (digitalRead(pinsDown[i]) == LOW) {
      pwm.setPWM(0, 0, stopValue - val);
    }
    
  }

  delay(50);
}
