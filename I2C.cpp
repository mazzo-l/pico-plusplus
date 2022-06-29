#include "I2C.h"

I2C::I2C(int16_t slice, Pin scl, Pin sda, long baudrate) {
    inst = slice == 0 ? i2c0 : i2c1;
    i2c_init (inst, baudrate);
    gpio_set_function (scl.gpio, GPIO_FUNC_I2C);
    gpio_set_function (sda.gpio, GPIO_FUNC_I2C);
    gpio_pull_up (scl.gpio);
    gpio_pull_up (sda.gpio);
}

void I2C::write(uint8_t address, const uint8_t* src, size_t length, bool nostop) {
    i2c_write_blocking (inst, address, src, length, nostop);
}

void I2C::read(uint8_t address, uint8_t *dst, size_t length, bool nostop) {
    i2c_read_blocking (inst, address, dst, length, nostop);
}
