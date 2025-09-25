# IMediaControl::StopWhenReady

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `StopWhenReady` method pauses the filter graph, allowing filters to queue data, and then stops the filter graph.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **S_FALSE** | The graph was still transitioning to the paused state when the method returned. |

## Remarks

This method is useful if you want to seek the filter graph while the graph is stopped. As long as the filter graph is stopped, changes in the current position do not repaint the video window with a new frame. Therefore, calling [IMediaSeeking::SetPositions](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-setpositions) does not update the video window. To update the window after the seek operation, call `StopWhenReady`. This method transitions the graph to a paused state, waits for the pause operation to complete, and then transitions the graph back to stopped. The pause operation queues data in the graph, so that the video renderer receives and displays the new frame.

This method is asynchronous. It waits on a separate thread for the pause to complete. The calling thread does not block, which enables the application to respond to user input. When the method returns, the logical state of the graph is stopped, even before the pause operation completes. If you call the [IMediaControl::GetState](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-getstate) method at this point, it returns State_Stopped.

If the application issues another state-change command (such as pause, run, or seek) before the pause operation completes, the new command cancels the pending stop command. The pause operation completes, but the graph does not stop.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaControl Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediacontrol)