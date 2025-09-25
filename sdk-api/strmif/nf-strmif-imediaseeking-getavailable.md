# IMediaSeeking::GetAvailable

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetAvailable` method retrieves the range of times in which seeking is efficient.

## Parameters

### `pEarliest` [out]

Pointer to a variable that receives the earliest time for efficient seeking.

### `pLatest` [out]

Pointer to a variable that receives the latest time for efficient seeking.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOTIMPL** | Method is not supported. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

This method is intended primarily for seeking in media streams that might have excessive latency, such as streams being sent over a network. The returned values indicate cached data that has already arrived, which can be easily seeked. It is assumed that seeking to values beyond these returned parameters will cause a delay while the application waits for the data to arrive.

All time values are expressed in the current time format. The default time format is [REFERENCE_TIME](https://learn.microsoft.com/windows/desktop/DirectShow/reference-time) units (100 nanoseconds). To change time formats, use the [IMediaSeeking::SetTimeFormat](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-settimeformat) method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaSeeking Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediaseeking)