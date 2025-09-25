# IMediaSeeking::SetRate

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetRate` method sets the playback rate.

## Parameters

### `dRate` [in]

Playback rate. Must not be zero.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The specified rate was zero or a negative value. (See Remarks.) |
| **E_NOTIMPL** | Not implemented. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_UNSUPPORTED_AUDIO** | Audio device or filter does not support this rate. |

## Remarks

The playback rate is expressed as a ratio of the normal speed. Thus, 1.0 is normal playback speed, 0.5 is half speed, and 2.0 is twice speed. For audio streams, changing the rate also changes the pitch.

Negative values indicate reverse playback. Most filters do not support negative playback, but instead return an error code if the *dRate* parameter is negative.

When an application calls this method on the Filter Graph Manager, the Filter Graph Manager does the following:

1. Calls the [IMediaSeeking::GetCurrentPosition](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-getcurrentposition) method. This call returns the current position as calculated by the Filter Graph Manager.
2. Stops the filter graph (if the graph is paused or running).
3. Calls the [IMediaSeeking::SetPositions](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-setpositions) method on the filters, with the current position as the start time. This has the effect of resetting the stream time to zero.
4. Calls the `SetRate` method on the filters, with the new rate.
5. Resumes the filter graph, if it was paused or running.

If an error occurs in step 4, the Filter Graph Manager tries to restore the previous rate.

Filters should respond to rate changes as follows:

**Parser and source filters:** The filter that originates the timestamps responds to the `SetRate` call. This is usually a parser filter, such as the [AVI Splitter Filter](https://learn.microsoft.com/windows/desktop/DirectShow/avi-splitter-filter), but it might be a source filter. After any seek or rate change, the filter should call the [IPin::NewSegment](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-newsegment) method with the new settings. After a rate change, it should adjust its timestamps accordingly. Because a rate change is preceded by a seek, timestamps restart from zero, so the filter can simply divide by the rate to calculate the new timestamps.

**Decoder filters:** Decoders should not act on `SetRate` calls other than to pass them upstream. Instead, they should respond to the **NewSegment** call that the upstream parser issues. When a decoder filter receives new segment information, it should store the values and pass the **NewSegment** call downstream. Some decoders need to generate extra timestamps by interpolating their input; they should take rate changes into account when doing so.

**Renderers:** Video renderers can typically ignore rate changes, because the incoming frames already have the correct time stamp. Audio renderers must modify their playback rate, because audio decoders typically do not make rate-change conversions.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaSeeking Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediaseeking)