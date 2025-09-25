# IAMClockAdjust::SetClockDelta

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetClockDelta` method adjusts the clock time.

## Parameters

### `rtDelta` [in]

Specifies the amount by which to adjust the clock, as a [REFERENCE_TIME](https://learn.microsoft.com/windows/desktop/DirectShow/reference-time) value. A positive value moves the clock forward, and a negative value moves the clock backward.

## Return value

Returns S_OK or an **HRESULT** error code.

## Remarks

The time values returned by [IReferenceClock::GetTime](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ireferenceclock-gettime) are monotonically increasing. If you set the clock back, **GetTime** continues to report the old time until the internal clock catches up.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMClockAdjust Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamclockadjust)