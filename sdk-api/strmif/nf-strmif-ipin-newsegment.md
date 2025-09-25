# IPin::NewSegment

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `NewSegment` method notifies the pin that media samples received after this call are grouped as a segment, with a common start time, stop time, and rate.

Applications should not call this method. This method is called by other filters.

## Parameters

### `tStart`

Start time of the segment, relative to the original source, in 100-nanosecond units.

### `tStop`

End time of the segment, relative to the original source, in 100-nanosecond units.

### `dRate`

Rate at which this segment should be processed, as a percentage of the original rate.

## Return value

Returns S_OK if successful, or an **HRESULT** value indicating the cause of the error.

## Remarks

A source filter (or parser filter) calls this method at the start of each new stream and after each seek operation. It calls the method on the input pin of the downstream filter, after delivering the previous batch of data and before calling [IMemInputPin::Receive](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imeminputpin-receive) with any new data. The downstream filter propagates the `NewSegment` call downstream.

Filters can use segment information to process samples. For example, with some formats it is impossible to reconstruct a delta frame without the next key frame. Therefore, if the stop time occurs on a delta frame, the source filter must send some additional frames. The decoder filter determines the final frame based on the segment information. The segment rate is used to render continuous data sources, such as audio data. For example, the audio renderer uses the sampling rate and the segment rate to render the audio data correctly.

## See also

[Data Flow in the Filter Graph](https://learn.microsoft.com/windows/desktop/DirectShow/data-flow-in-the-filter-graph)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IPin Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin)