#ifndef PICOPP_SERVO_H
#define PICOPP_SERVO_H

#include "PWM.h"
#include "Pin.h"

class Servo {
public:
    explicit Servo(const Pin& gpio);

    void rotate(float degrees);

private:
    PWM mPwm;

    static constexpr float angleToDuty(float angle);
};


#endif //PICOPP_SERVO_H
