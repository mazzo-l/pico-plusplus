#include "PWM.h"

#include <cmath>

PWM::PWM(const Pin &pin, float freq) {
    mFrequency = freq;
    gpio_set_function(pin.gpio, GPIO_FUNC_PWM);
    mSlice = pwm_gpio_to_slice_num(pin.gpio);
    mChannel = pwm_gpio_to_channel(pin.gpio);
    mClickDiv = ceilf(CLOCK_FREQUENCY / (4096.0f * mFrequency)) / 16.0f;
    pwm_set_clkdiv(mSlice, mClickDiv);
}

void PWM::start() const {
    pwm_set_enabled(mSlice, true);
}

void PWM::stop() const {
    pwm_set_enabled(mSlice, false);
}

void PWM::duty(float ns) const {
    auto duty = (ns / 1000000000.0f) / (1.0f / mFrequency);
    auto wrap = (uint16_t) ((CLOCK_FREQUENCY / mClickDiv) / mFrequency - 1);
    auto level = (uint16_t) ((float) wrap * duty);
    pwm_set_wrap(mSlice, wrap);
    pwm_set_chan_level(mSlice, mChannel, level);
}
