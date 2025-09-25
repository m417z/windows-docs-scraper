# IPinConnection::DynamicDisconnect

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DynamicDisconnect` method disconnects the pin when the filter is active (paused or running). Call this method instead of [IPin::Disconnect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-disconnect) to disconnect a pin when the graph is running or paused.

The caller must ensure that no data is flowing to the pin when it calls this method. Call the [IPinFlowControl::Block](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipinflowcontrol-block) method on an upstream pin to block the data flow, or use some other mechanism to make sure that no samples are delivered until this pin is reconnected.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The pin is already disconnected. |
| **S_OK** | Success. |

## See also

[Dynamic Reconnection](https://learn.microsoft.com/windows/desktop/DirectShow/dynamic-reconnection)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IPinConnection Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipinconnection)