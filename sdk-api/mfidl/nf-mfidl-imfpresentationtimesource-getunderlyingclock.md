# IMFPresentationTimeSource::GetUnderlyingClock

## Description

Retrieves the underlying clock that the presentation time source uses to generate its clock times.

## Parameters

### `ppClock` [out]

Receives a pointer to the clock's [IMFClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfclock) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NO_CLOCK** | This time source does not expose an underlying clock. |

## Remarks

A presentation time source must support stopping, starting, pausing, and rate changes. However, in many cases the time source derives its clock times from a hardware clock or other device. The underlying clock is always running, and might not support rate changes.

Optionally, a time source can expose the underlying clock by implementing this method. The underlying clock is always running, even when the presentation time source is paused or stopped. (Therefore, the underlying clock returns the MFCLOCK_CHARACTERISTICS_FLAG_ALWAYS_RUNNING flag in the [IMFClock::GetClockCharacteristics](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclock-getclockcharacteristics) method).

The underlying clock is useful if you want to make decisions based on the clock times while the presentation clock is stopped or paused.

If the time source does not expose an underlying clock, the method returns MF_E_NO_CLOCK.

## See also

[IMFPresentationTimeSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationtimesource)

[Presentation Clock](https://learn.microsoft.com/windows/desktop/medfound/presentation-clock)