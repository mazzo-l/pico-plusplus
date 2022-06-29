#include "Pin.h"

void Pin::high() const {
    gpio_put(gpio, true);
}

void Pin::low() const {
    gpio_put(gpio, false);
}

Pin::Pin(unsigned int gpio_, PinMode mode) {
    gpio = gpio_;
    gpio_init(gpio_);
    gpio_set_dir(gpio_, (int) mode);
}

int Pin::state() const {
    return gpio_get(gpio);
}

void Pin::toggle() const {
    gpio_put(gpio, !state());
}
