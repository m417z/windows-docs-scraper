# IMFPresentationClock::Stop

## Description

Stops the presentation clock. While the clock is stopped, the clock time does not advance, and the clock's [IMFPresentationClock::GetTime](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationclock-gettime) method returns zero.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_CLOCK_NO_TIME_SOURCE** | No time source was set on this clock. |
| **MF_E_CLOCK_STATE_ALREADY_SET** | The clock is already stopped. |

## Remarks

This method is valid when the clock is running or paused.

The presentation clock initiates the state change by calling [IMFClockStateSink::OnClockStop](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclockstatesink-onclockstop) on the clock's time source. This call is made synchronously. If it fails, the state change does not occur. If the call succeeds, the state changes, and the clock notifies the other state-change subscribers by calling their **OnClockStop** methods. These calls are made asynchronously.

## See also

[IMFPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationclock)

[Presentation Clock](https://learn.microsoft.com/windows/desktop/medfound/presentation-clock)