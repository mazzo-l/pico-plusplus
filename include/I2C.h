#ifndef PICOPP_I2C_H
#define PICOPP_I2C_H

#include "hardware/i2c.h"
#include "Pin.h"

class I2C {
public:
    I2C(int16_t slice, Pin scl, Pin sda, long baudrate = 40000);
    I2C() = default;
    void write(uint8_t address, const uint8_t* src, size_t length, bool nostop) const;
    void read(uint8_t address, uint8_t* dst, size_t length, bool nostop) const;
private:
    i2c_inst* inst{};
};


#endif //PICOPP_I2C_H
