# MFCLOCK_PROPERTIES structure

## Description

Defines the properties of a clock.

## Members

### `qwCorrelationRate`

The interval at which the clock correlates its clock time with the system time, in 100-nanosecond units. If the value is zero, the correlation is made whenever the [IMFClock::GetCorrelatedTime](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclock-getcorrelatedtime) method is called.

### `guidClockId`

The unique identifier of the underlying device that provides the time. If two clocks have the same unique identifier, they are based on the same device. If the underlying device is not shared between two clocks, the value can be **GUID_NULL**.

### `dwClockFlags`

A bitwise **OR** of flags from the [MFCLOCK_RELATIONAL_FLAGS](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfclock_relational_flags) enumeration.

### `qwClockFrequency`

The clock frequency in Hz. A value of **MFCLOCK_FREQUENCY_HNS** means that the clock has a frequency of 10 MHz (100-nanosecond ticks), which is the standard [MFTIME](https://learn.microsoft.com/windows/desktop/medfound/mftime) time unit in Media Foundation. If the [IMFClock::GetClockCharacteristics](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclock-getclockcharacteristics) method returns the **MFCLOCK_CHARACTERISTICS_FLAG_FREQUENCY_10MHZ** flag, the value of this field must be **MFCLOCK_FREQUENCY_HNS**.

### `dwClockTolerance`

The amount of inaccuracy that may be present on the clock, in parts per billion (ppb). For example, an inaccuracy of 50 ppb means the clock might drift up to 50 seconds per billion seconds of real time. If the tolerance is not known, the value is **MFCLOCK_TOLERANCE_UNKNOWN**. This constant is equal to 50 parts per million (ppm).

### `dwClockJitter`

The amount of jitter that may be present, in 100-nanosecond units. Jitter is the variation in the frequency due to sampling the underlying clock. Jitter does not include inaccuracies caused by drift, which is reflected in the value of **dwClockTolerance**.

For clocks based on a single device, the minimum jitter is the length of the tick period (the inverse of the frequency). For example, if the frequency is 10 Hz, the jitter is 0.1 second, which is 1,000,000 in [MFTIME](https://learn.microsoft.com/windows/desktop/medfound/mftime) units. This value reflects the fact that the clock might be sampled just before the next tick, resulting in a clock time that is one period less than the actual time. If the frequency is greater than 10 MHz, the jitter should be set to 1 (the minimum value).

If a clock's underlying hardware device does not directly time stamp the incoming data, the jitter also includes the time required to dispatch the driver's interrupt service routine (ISR). In that case, the expected jitter should include the following values:

| Value | Meaning |
| --- | --- |
| **MFCLOCK_JITTER_ISR** | Jitter due to time stamping during the device driver's ISR. |
| **MFCLOCK_JITTER_DPC** | Jitter due to time stamping during the deferred procedure call (DPC) processing. |
| **MFCLOCK_JITTER_PASSIVE** | Jitter due to dropping to normal thread execution before time stamping. |

## See also

[IMFClock::GetProperties](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclock-getproperties)

[MFTIME](https://learn.microsoft.com/windows/desktop/medfound/mftime)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)