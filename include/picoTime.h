#ifndef PICOPP_PICOTIME_H
#define PICOPP_PICOTIME_H

#include "pico/stdlib.h"
#include "pico/time.h"

class AbsoluteTime {
private:
    absolute_time_t mHandle{};
    AbsoluteTime(absolute_time_t handle) : mHandle(handle) {}

public:
    AbsoluteTime() = default;

    // Get the underlying handle to absolute_time_t
    absolute_time_t getHandle() const { return mHandle; }

    /// Convert an AbsoluteTime into a number of microseconds since boot
    unsigned long int toMicrosecondsSinceBoot() const;

    /// Convert an AbsoluteTime into a number of millliseconds since boot
    unsigned long int toMilllisecondsSinceBoot() const;
    
    /// Return a representation of the current time
    static AbsoluteTime getCurrent();

    /// Return a timestamp value obtained by adding a number of microseconds to another timestamp
    AbsoluteTime delayedByMicroseconds(unsigned long int us) const;

    /// Return a timestamp value obtained by adding a number of milliseconds to another timestamp
    AbsoluteTime delayedByMilliseconds(unsigned long int ms) const;

    /// Return the difference in microseconds between two timestamps. NOTE: consider using the '-' operator
    static unsigned long int absoluteTimeDiff(const AbsoluteTime& t1, const AbsoluteTime& t2);

    /// Return the difference in microseconds between two timestamps
    unsigned long int operator- (const AbsoluteTime& other) const;
};

namespace time
{
    /// @brief Wait for the given number of milliseconds before returning.
    /// @param ms the number of milliseconds to sleep (1ms = 10e-3s)
    void sleepMilliseconds(unsigned long int ms);

    /// @brief Wait for the given number of microseconds before returning
    /// @param us the number of microseconds to sleep (1us = 10e-6s)
    void sleepMicroseconds(unsigned long int us);

    /// @brief Wait for the given number of seconds before returning
    /// @param s the number of seconds to sleep
    void sleepSeconds(float s);
}

#endif // PICOPP_PICOTIME_H