# IMediaControl::Stop

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Stop` method stops all the filters in the graph.

## Return value

Returns S_OK if successful, or an **HRESULT** value that indicates the cause of the error.

## Remarks

If the graph is running, this method pauses the graph before stopping it. While paused, video renderers can copy the current frame to display as a poster frame.

This method does not seek to the beginning of the stream. If you call this method and then call the [IMediaControl::Run](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-run) method, playback resumes from the stopped position. To seek, use the [IMediaSeeking](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediaseeking) interface.

The Filter Graph Manager pauses all the filters in the graph, and then calls the [IMediaFilter::Stop](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediafilter-stop) method on all filters, without waiting for the pause operations to complete. Therefore, some filters might have their `Stop` method called before they complete their pause operation. If you develop a custom rendering filter, you might need to handle this case by pausing the filter if it receives a stop command while in a running state. However, most filters do not need to take any special action in this regard.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaControl Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediacontrol)

[StopWhenReady](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-stopwhenready)