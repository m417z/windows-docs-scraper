# IAMVideoControl::GetCurrentActualFrameRate

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetCurrentActualFrameRate` method retrieves the actual frame rate, expressed as a frame duration in 100-nanosecond units. USB (Universal Serial Bus) and IEEE 1394 cameras may provide lower frame rates than requested because of bandwidth availability. This is only available during video streaming.

## Parameters

### `pPin` [in]

Pointer to the pin to retrieve the frame rate from.

### `ActualFrameRate` [out]

Pointer to the frame rate in frame duration in 100-nanosecond units.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVideoControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideocontrol)