# IPin::Disconnect

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Disconnect` method breaks the current pin connection.

The Filter Graph Manager calls this method when it disconnects two filters. Applications and filters should not call this method. Instead, call the [IFilterGraph::Disconnect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifiltergraph-disconnect) method on the Filter Graph Manager.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The pin was not connected. |
| **S_OK** | Success. |
| **VFW_E_NOT_STOPPED** | The filter is active. |

## Remarks

This method fails if the filter is paused or running. If the pin supports the [IPinConnection](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipinconnection) interface, call [IPinConnection::DynamicDisconnect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipinconnection-dynamicdisconnect) to disconnect the pin when the filter is paused or running.

This method does not disconnect the other pin in the pin connection.

## See also

[Data Flow in the Filter Graph](https://learn.microsoft.com/windows/desktop/DirectShow/data-flow-in-the-filter-graph)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IPin Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin)