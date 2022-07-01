#include "SPI.h"

SPI::SPI(int slice,
         const Pin &sck, const Pin &mosi, const Pin &miso,
         int baudrate, int polarity, int phase, int bits, int firstbit)
{
    spi = slice == 0? spi0 : spi1;
    spi_init(spi, baudrate);
    spi_set_format(slice, bits, polarity, phase, firstbit);
    gpio_set_function(sck.gpio, GPIO_FUNC_SPI);
    gpio_set_function(mosi.gpio, GPIO_FUNC_SPI);
    gpio_set_function(miso.gpio, GPIO_FUNC_SPI);
}