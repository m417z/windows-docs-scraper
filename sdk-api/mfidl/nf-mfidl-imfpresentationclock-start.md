# IMFPresentationClock::Start

## Description

Starts the presentation clock.

## Parameters

### `llClockStartOffset` [in]

Initial starting time, in 100-nanosecond units. At the time the **Start** method is called, the clock's [IMFPresentationClock::GetTime](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationclock-gettime) method returns this value, and the clock time increments from there. If the value is PRESENTATION_CURRENT_POSITION, the clock starts from its current position. Use this value if the clock is paused and you want to restart it from the same position.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_CLOCK_NO_TIME_SOURCE** | No time source was set on this clock. |

## Remarks

This method is valid in all states (stopped, paused, or running).

If the clock is paused and restarted from the same position (*llClockStartOffset* is PRESENTATION_CURRENT_POSITION), the presentation clock sends an [IMFClockStateSink::OnClockRestart](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclockstatesink-onclockrestart) notification. Otherwise, the clock sends an [IMFClockStateSink::OnClockStart](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclockstatesink-onclockstart) notification.

The presentation clock initiates the state change by calling [OnClockStart](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclockstatesink-onclockstart) or [OnClockRestart](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclockstatesink-onclockrestart) on the clock's time source. This call is made synchronously. If it fails, the state change does not occur. If the call succeeds, the state changes, and the clock notifies the other state-change subscribers by calling their **OnClockStart** or **OnClockRestart** methods. These calls are made asynchronously.

If the clock is already running, calling **Start** again has the effect of seeking the clock to the new *StartOffset* position.

## See also

[IMFPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationclock)

[Presentation Clock](https://learn.microsoft.com/windows/desktop/medfound/presentation-clock)