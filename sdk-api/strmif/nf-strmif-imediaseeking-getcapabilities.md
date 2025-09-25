# IMediaSeeking::GetCapabilities

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetCapabilities` method retrieves all the seeking capabilities of the stream.

## Parameters

### `pCapabilities` [out]

Pointer to a variable that receives a bitwise combination of [AM_SEEKING_SEEKING_CAPABILITIES](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-am_seeking_seeking_capabilities) flags.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

This method returns information on all the seeking capabilities of the stream. Examine *pCapabilities* by performing a separate bitwise-AND operation on each AM_SEEKING_SEEKING_CAPABILITIES value you are interested in.

| C++ |
| --- |
| ``` DWORD dwCaps = 0; pMediaSeeking->GetCapabilities(&dwCaps);<br><br>if (dwCaps & AM_SEEKING_CanGetCurrentPos)  {     // The stream can seek to the current position. } if (dwCaps & AM_SEEKING_CanPlayBackwards)  {     // The stream can play backward. } ``` |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaSeeking Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediaseeking)