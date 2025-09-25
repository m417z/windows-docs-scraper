# IMediaFilter::Run

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Run` method runs the filter.

## Parameters

### `tStart`

Reference time corresponding to stream time 0.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_FALSE** | Transition is not complete. |
| **S_OK** | Success. Transition is complete. |

## Remarks

When a filter is running, it can receive, process, and deliver samples. Source filters generate new samples, and renderer filters render them.

The state transition might be asynchronous. If the method returns before the transition completes, the return value is S_FALSE.

Stream time is calculated as the current reference time minus *tStart*. To calculate when a media sample should be rendered, the renderer compares the time stamp with the current stream time. Thus, a media sample with a time stamp of zero should be rendered at time *tStart*. For more information, see [Time and Clocks in DirectShow](https://learn.microsoft.com/windows/desktop/DirectShow/time-and-clocks-in-directshow).

When an application calls the [IMediaControl::Run](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-run) method, the Filter Graph Manager calls `IMediaFilter::Run` on each filter. It sets the value of *tStart* slightly in the future, to account for graph latency.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaFilter Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediafilter)