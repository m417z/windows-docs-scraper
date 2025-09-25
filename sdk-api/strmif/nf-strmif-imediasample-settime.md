# IMediaSample::SetTime

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetTime` method sets the stream times when this sample should begin and finish.

## Parameters

### `pTimeStart` [in]

Pointer to a variable that contains the start time of the sample.

### `pTimeEnd` [in]

Pointer to a variable that contains the stop time of the sample.

## Return value

Returns S_OK, or **HRESULT** value indicating the cause of the error.

## Remarks

Both time values are relative to the stream time. For more information, see [Time and Clocks in DirectShow](https://learn.microsoft.com/windows/desktop/DirectShow/time-and-clocks-in-directshow).

To invalidate the stream times, set *pTimeStart* and *pTimeEnd* to **NULL**. This will cause the [IMediaSample::GetTime](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediasample-gettime) method to return VFW_E_SAMPLE_TIME_NOT_SET.

For more information about stream times, see [Time and Clocks in DirectShow](https://learn.microsoft.com/windows/desktop/DirectShow/time-and-clocks-in-directshow).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaSample Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediasample)