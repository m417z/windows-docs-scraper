# IMediaFilter::Pause

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Pause** method pauses the filter.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_FALSE** | Transition is not complete. |
| **S_OK** | Success. Transition is complete. |

## Remarks

When a filter is paused, it can receive, process, and deliver samples. However, a renderer filter will only accept one sample while paused. Therefore, when the filter graph is paused, samples move through the graph until the first sample reaches the renderer. At that point, streaming is paused until the [IMediaFilter::Run](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediafilter-run) method is called. Video renderers display the first sample as a still frame.

Live capture filters do not deliver any samples while paused, only while running.

The state transition might be asynchronous. If the method returns before the transition completes, the return value is **S_FALSE**. A renderer filter does not complete the transition to paused until either (1) it receives one sample, or (2) it receives an end-of-stream notification. While the state transition is pending, [IMediaFilter::GetState](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediafilter-getstate) returns **VFW_S_STATE_INTERMEDIATE**.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter)

[IMediaFilter Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediafilter)