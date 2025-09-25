# IMediaControl::Run

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Run` method runs all the filters in the filter graph. While the graph is running, data moves through the graph and is rendered.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The graph is preparing to run, but some filters have not completed the transition to a running state. |
| **S_OK** | All filters in the graph completed the transition to a running state. |

## Remarks

If the filter graph is stopped, this method pauses the graph before running. If the graph is already running, the method returns S_OK but has no effect.

The graph runs until the application calls the [IMediaControl::Pause](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-pause) or [IMediaControl::Stop](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-stop) method. When playback reaches the end of the stream, the graph continues to run, but the filters do not stream any more data. At that point, the application can pause or stop the graph. For information about the end-of-stream event, see **IMediaControl::Pause** and [EC_COMPLETE](https://learn.microsoft.com/windows/desktop/DirectShow/ec-complete).

This method does not seek to the beginning of the stream. Therefore, if you run the graph, pause it, and then run it again, playback resumes from the paused position. If you run the graph after it has reached the end of the stream, nothing is rendered. To seek the graph, use the [IMediaSeeking](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediaseeking) interface.

If method returns **S_FALSE**, it means that the method returned before all of the filters switched to a running state. The filters will complete the transition after the method returns. Optionally, you can wait for the transition to complete by calling the [IMediaControl::GetState](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-getstate) method with a timeout value. However, this is not required.

If the **Run** method returns an error code, it means that one or more filters failed to run. However, some filters might be in a running state. In a multistream graph, entire streams might be playing successfully. Typically the application would tear down the graph and report an error in this case.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaControl Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediacontrol)