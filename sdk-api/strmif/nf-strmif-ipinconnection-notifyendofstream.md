# IPinConnection::NotifyEndOfStream

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `NotifyEndOfStream` method requests notification from the pin when the next end-of-stream condition occurs.

## Parameters

### `hNotifyEvent` [in]

Handle to an event object that the pin will signal.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | Event handle was **NULL**, but there was no existing event handle to reset. |
| **S_OK** | Event handle was set. (If event handle was **NULL**, event notification was canceled.) |

## Remarks

This method enables the caller to push data through a portion of the filter graph ending with this pin.

For example, suppose the caller is pushing data from an output pin called "A" on one filter, to an input pin called "B" on another filter, possibly with intermediate filters connecting them. The following sequence of events would take place.

1. The caller blocks the data flow at pin A.
2. It calls `NotifyEndOfStream` on pin B.
3. It calls [IPin::EndOfStream](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-endofstream) on the input pin connected to pin A.
4. As the remaining data travels downstream through any intermediate filters, those filters propagate the end-of-stream notification.
5. When pin B receives the end-of-stream notification, it signals the event given in the *hNotifyEvent* parameter. At that point, the caller can safely reconfigure the graph between pin A and pin B.

Because the purpose of this method is to enable the caller to rebuild the graph dynamically and then restart the connection, the end-of-stream notification does not represent the actual end of the stream. Therefore, pin B does not propagate the end-of-stream condition or signal EC_COMPLETE. This is an exception to the usual rules for data flow in the filter graph.

It is the caller's responsibility to cancel notification by calling this method again with a **NULL** event handle.

The filter graph calls this method inside the [IGraphConfig::Reconnect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphconfig-reconnect) method. If an application or filter does any specialized dynamic reconfiguration to the graph (using the [IGraphConfig::Reconfigure](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphconfig-reconfigure) method), it might call this method first in order to push data through the portion of the graph that is being reconfigured.

## See also

[Dynamic Reconnection](https://learn.microsoft.com/windows/desktop/DirectShow/dynamic-reconnection)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IPinConnection Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipinconnection)