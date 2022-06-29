#ifndef PICOPP_PWM_H
#define PICOPP_PWM_H

#include "Pin.h"
#include "hardware/pwm.h"

/// RP2040's clock frequency
constexpr float CLOCK_FREQUENCY = 125000000.0f; // Hz

class PWM {
public:
    PWM(const Pin &pin, float freq);

    PWM() = default;

    /// Start the PWM slice
    void start() const;

    /// Stop the PWM slice
    void stop() const;

    /// Start a duty cycle
    void duty(float ns) const;

private:
    float mFrequency;
    unsigned int mSlice;
    unsigned int mChannel;
    float mClickDiv;
};


#endif //PICOPP_PWM_H
