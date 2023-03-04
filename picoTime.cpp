#include "picoTime.h"

inline unsigned long int AbsoluteTime::toMicrosecondsSinceBoot() const
{
    return to_us_since_boot(mHandle);
}

inline unsigned long int AbsoluteTime::toMilllisecondsSinceBoot() const
{
    return to_ms_since_boot(mHandle);
}

inline AbsoluteTime AbsoluteTime::getCurrent()
{
    return AbsoluteTime(get_absolute_time());
}

inline AbsoluteTime AbsoluteTime::delayedByMicroseconds(unsigned long int us) const
{
    return AbsoluteTime(delayed_by_us(mHandle, us));
}

inline AbsoluteTime AbsoluteTime::delayedByMilliseconds(unsigned long int ms) const
{
    return AbsoluteTime(delayed_by_ms(mHandle, ms));
}

inline unsigned long int AbsoluteTime::absoluteTimeDiff(const AbsoluteTime &t1, const AbsoluteTime &t2)
{
    return absolute_time_diff_us(t1.getHandle(), t2.getHandle());
}

unsigned long int AbsoluteTime::operator-(const AbsoluteTime &other) const
{
    return absolute_time_diff_us(mHandle, other.getHandle());
}

namespace time
{

    void sleepMilliseconds(unsigned long int ms)
    {
        sleep_ms(ms);
    }

    void sleepMicroseconds(unsigned long int us)
    {
        sleep_us(us);
    }

    void sleepSeconds(float s)
    {
        sleepMilliseconds(static_cast<unsigned long int>(s * 1000.0f));
    }
}