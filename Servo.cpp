#include "Servo.h"

Servo::Servo(const Pin &gpio) : mPwm(PWM(gpio, 50.0f)) {
    mPwm.start();
}

constexpr float Servo::angleToDuty(float angle) {
    return (float) (int) ((2.0f / 180.0f * (angle + 90.0f) + 0.5f) * 1000000.0f);
}

void Servo::rotate(float degrees) {
    mPwm.duty(angleToDuty(degrees));
}
