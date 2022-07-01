add_library(picopp I2C.cpp Pin.cpp PWM.cpp Servo.cpp)
target_include_directories(picopp PUBLIC include)
target_link_libraries(picopp hardware_pwm pico_stdlib hardware_i2c hardware_spi)