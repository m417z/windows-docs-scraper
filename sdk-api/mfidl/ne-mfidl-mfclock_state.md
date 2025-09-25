# MFCLOCK_STATE enumeration

## Description

Defines the state of a clock.

## Constants

### `MFCLOCK_STATE_INVALID:0`

The clock is invalid. A clock might be invalid for several reasons. Some clocks return this state before the first start. This state can also occur if the underlying device is lost.

### `MFCLOCK_STATE_RUNNING`

The clock is running. While the clock is running, the time advances at the clock's frequency and current rate.

### `MFCLOCK_STATE_STOPPED`

The clock is stopped. While stopped, the clock reports a time of 0.

### `MFCLOCK_STATE_PAUSED`

The clock is paused. While paused, the clock reports the time it was paused.

## See also

[IMFClock::GetState](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclock-getstate)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)