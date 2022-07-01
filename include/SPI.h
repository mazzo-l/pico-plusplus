#ifndef PICOPP_SPI_H
#define PICOPP_SPI_H

#include "hardware_spi"

class SPI
{
public:
    /// Initialize SPI slice
    SPI(int slice,
        const Pin &sck, const Pin &mosi, const Pin &miso,
        int baudrate, int polarity, int phase, int bits, int firstbit);

private:
    spi_inst_t* spi{};
};

#endif // PICOPP_SPI_H