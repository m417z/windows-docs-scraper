# IMediaSeeking::GetCurrentPosition

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetCurrentPosition` method retrieves the current position, relative to the total duration of the stream.

## Parameters

### `pCurrent` [out]

Pointer to a variable that receives the current position, in units of the current time format.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOTIMPL** | Method is not supported. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

This method returns the current position that playback has reached. The value includes adjustments for the playback rate and starting time. For example, if the start time is 5 seconds, the playback rate is 2.0, and you run the graph for four seconds, the current position is 5 + (4 x 2.0) = 13.0 seconds.

The returned value is expressed in units of the current time format. To determine the current time format, call the [GetTimeFormat](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-gettimeformat) method.

If the graph is paused or stopped, the current position is the point at which playback will resume.

The Filter Graph Manager calculates the position from the current stream time; it does not query the filters in the graph. For file playback, this yields an accurate result, because playback is synchronized to the stream time. For file writing, the results are not accurate. To get the current position in a file-writing graph, query the multiplexer filter. (Position is not relevant for live capture, however.)

The returned value is expressed in the current time format. The default time format is [REFERENCE_TIME](https://learn.microsoft.com/windows/desktop/DirectShow/reference-time) units (100 nanoseconds). To change time formats, use the [IMediaSeeking::SetTimeFormat](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-settimeformat) method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaSeeking Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediaseeking)