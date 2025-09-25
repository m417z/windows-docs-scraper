# IAMClockSlave::SetErrorTolerance

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetErrorTolerance` method sets the audio renderer's rate-matching tolerance.

## Parameters

### `dwTolerance` [in]

Specifies the maximum tolerance, in milliseconds. The value must be from 1 to 1000, inclusive.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure. |
| **S_OK** | Success. |
| **VFW_E_NOT_STOPPED** | The filter graph is not stopped. |

## Remarks

Changing the tolerance has no effect unless the audio renderer is matching rates with a different clock. If the audio renderer is the reference clock, the audio is always synchronized to the clock (by definition).

This method fails if the filter graph is not stopped.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMClockSlave Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamclockslave)