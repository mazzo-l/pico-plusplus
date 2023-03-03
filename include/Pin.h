#ifndef PICOPP_PIN_H
#define PICOPP_PIN_H

#include "pico/stdlib.h"

enum class PinMode {
    IN = 0, OUT = 1,
};

class Pin {
public:
    /// Handle to the underlying gpio number
    unsigned int gpio;

    Pin(unsigned int gpio_, PinMode mode = PinMode::OUT);

    void high() const;

    void low() const;

    /// Sets pin to high if it's low and vice-versa
    void toggle() const;

    [[nodiscard]] int state() const;
};

/// Output pin connected to user led
const Pin LED_PIN = Pin(25, PinMode::OUT);

/// Input pin: high if VBUS is present, else low
const Pin VBUS_SENSE = Pin(24, PinMode::IN);

#endif //PICOPP_PIN_H
