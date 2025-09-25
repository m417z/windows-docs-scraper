# IReferenceClockTimerControl::SetDefaultTimerResolution

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetDefaultTimerResolution` method sets the minimum timer resolution.

## Parameters

### `timerResolution` [in]

Minimum timer resolution, in 100-nanosecond units. If the value is zero, the reference clock cancels its previous request.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |

## Remarks

The reference clock attempts to set the period of the timer to *timerResolution*. The actual period of the timer might differ, depending on the hardware. To find the minimum and maximum timer resolution, call the [timeGetDevCaps](https://learn.microsoft.com/windows/desktop/api/timeapi/nf-timeapi-timegetdevcaps) function. The reference clock sets the timer resolution is set by calling [timeBeginPeriod](https://learn.microsoft.com/windows/desktop/api/timeapi/nf-timeapi-timebeginperiod). If *timerResolution* is 0, the method cancels the previous timer request by calling [timeEndPeriod](https://learn.microsoft.com/windows/desktop/api/timeapi/nf-timeapi-timeendperiod). (When the reference clock is destroyed, it automatically cancels any previous request.)

If this method is not called, the reference clock sets the timer resolution to 1 millisecond. To get the best power management performance, it is recommended that you call this method with the value zero. This overrides the clock's default setting of 1 millisecond. If any filters in the graph require a higher timer resolution, they can call [timeBeginPeriod](https://learn.microsoft.com/windows/desktop/api/timeapi/nf-timeapi-timebeginperiod) individually. Typically only renderers should require a particular timer resolution.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IReferenceClockTimerControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ireferenceclocktimercontrol)