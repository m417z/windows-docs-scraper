# MFCLOCK_CHARACTERISTICS_FLAGS enumeration

## Description

Contains flags that describe the characteristics of a clock. These flags are returned by the [IMFClock::GetClockCharacteristics](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclock-getclockcharacteristics) method.

## Constants

### `MFCLOCK_CHARACTERISTICS_FLAG_FREQUENCY_10MHZ:0x2`

The clock times returned by the [IMFClock::GetCorrelatedTime](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclock-getcorrelatedtime) method are in units of 100 nanoseconds. If this flag is absent, call [IMFClock::GetProperties](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclock-getproperties) to get the clock frequency. The clock frequency is given in the **qwClockFrequency** member of the [MFCLOCK_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/mfidl/ns-mfidl-mfclock_properties) structure returned by that method.

### `MFCLOCK_CHARACTERISTICS_FLAG_ALWAYS_RUNNING:0x4`

The clock is always running. If this flag is present, the clock cannot be paused or stopped. If this flag is absent, call the [IMFClock::GetState](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclock-getstate) method to get the current state.

### `MFCLOCK_CHARACTERISTICS_FLAG_IS_SYSTEM_CLOCK:0x8`

The clock times are generated from the system clock.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)