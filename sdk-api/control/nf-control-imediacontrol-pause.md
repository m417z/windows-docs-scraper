# IMediaControl::Pause

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Pause` method pauses all the filters in the filter graph.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The graph paused successfully, but some filters have not completed the state transition. |
| **S_OK** | All filters in the graph completed the transition to a paused state. |

## Remarks

Pausing the filter graph cues the graph for immediate rendering when the graph is next run. While the graph is paused, filters process data but do not render it. Data is pushed through the graph and processed by transform filters as far as buffering permits, but renderer filters do not render the data. However, video renderers display a static poster frame of the first sample.

If the method returns S_FALSE, call the [IMediaControl::GetState](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-getstate) method to wait for the state transition to complete, or to check if the transition has completed. When you call `Pause` to display the first frame of a video file, always follow it immediately with a call to **GetState** to ensure that the state transition has completed. Failure to do this can result in the video rectangle being painted black.

If the method fails, it stops the graph before returning.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaControl Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediacontrol)

[IMediaControl::StopWhenReady](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-stopwhenready)