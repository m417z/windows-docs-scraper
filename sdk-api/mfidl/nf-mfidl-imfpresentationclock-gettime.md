# IMFPresentationClock::GetTime

## Description

Retrieves the latest clock time.

## Parameters

### `phnsClockTime` [out]

Receives the latest clock time, in 100-nanosecond units. The time is relative to when the clock was last started.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_CLOCK_NO_TIME_SOURCE** | The clock does not have a presentation time source. Call [IMFPresentationClock::SetTimeSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationclock-settimesource). |

## Remarks

This method does not attempt to smooth out jitter or otherwise account for any inaccuracies in the clock time.

## See also

[IMFPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationclock)

[MFTIME](https://learn.microsoft.com/windows/desktop/medfound/mftime)

[Presentation Clock](https://learn.microsoft.com/windows/desktop/medfound/presentation-clock)