# IMediaSeeking::GetDuration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetDuration** method gets the duration of the stream.

## Parameters

### `pDuration` [out]

Receives the duration, in units of the current time format.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method gets the duration of the stream at normal playback speed. Changing the playback rate does not affect the duration.

The duration is expressed in the current time format. The default time format is [REFERENCE_TIME](https://learn.microsoft.com/windows/desktop/DirectShow/reference-time) units (100 nanoseconds). To change time formats, use the [IMediaSeeking::SetTimeFormat](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-settimeformat) method.

Depending on the source format, the duration might not be exact. For example, if the source contains a variable bit-rate (VBR) stream, the method might return an estimated duration.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaSeeking Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediaseeking)