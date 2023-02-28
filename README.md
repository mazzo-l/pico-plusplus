# pico-plusplus
A high-level C++ wrapper around the Raspberry Pi Pico C/C++ SDK

This library aims at abstracting away the lowest-level C-style functions with an easy-to-use, modern object-oriented approach, making it easier, especially for beginners coming from MicroPython, to program for the RP2040 using C++. 

This library is usable, but still a work in progress.

# Quick-start
1. Set up a working C/C++ project with the Raspberry Pi C/C++ SDK following the instructions in the [Getting started with the Raspberry Pi Pico](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)
2. Clone the repository in your project folder
`
git clone https://github.com/mazzo-l/pico-plusplus.git`. In alternative you can download the zip file and extract it, in this case you might want to rename the folder to a sensible name like "pico-plusplus"
3. In your project's `CMakeLists.txt` add the following line:
```cmake
add_subdirectory(pico-plusplus)
```
4. Add `picopp` to `target_link_libraries`
```cmake
target_link_libraries(yourTarget picopp)
```
# Usage guide
The pico-plusplus library comprises of:
- Pin.h: A Pin class used to interface with the GPIOs
- PWM.h: A PWM class aimed to simplify the process of setting up a PWM pin
- Servo.h: A Servo class that internally uses PWM to rotate a servo
- I2C.h: An I2C class for setting up and using an I2C slice

More headers and functionality to come.


The functions are pretty much self-explanatory and generally well-commented. In case of doubt, please refer to the [Raspberry Pi Pico C/C++ SDK documentation](https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-c-sdk.pdf)

# Example program
An example program showing a simple led blinking

```cpp
#include "Pin.h"

int main(int, char**) {
    while (true){
        // LED_PIN is a constant referring to the onboard led. It's equivalent to Pin(25)
        LED_PIN.toggle();
        sleep_ms(500);
    }
}
```
