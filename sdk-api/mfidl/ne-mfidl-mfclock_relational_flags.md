# MFCLOCK_RELATIONAL_FLAGS enumeration

## Description

Defines properties of a clock.

## Constants

### `MFCLOCK_RELATIONAL_FLAG_JITTER_NEVER_AHEAD:0x1`

Jitter values are always negative. In other words, the time returned by [IMFClock::GetCorrelatedTime](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclock-getcorrelatedtime) might jitter behind the actual clock time, but will never jitter ahead of the actual time. If this flag is not present, the clock might jitter in either direction.

## See also

[MFCLOCK_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/mfidl/ns-mfidl-mfclock_properties)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)