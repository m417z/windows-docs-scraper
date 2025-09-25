# IFilterGraph2::ReconnectEx

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ReconnectEx` method breaks the existing pin connection and reconnects it to the same pin, using a specified media type.

Applications should not call this method. It is called by filters during the graph building process.

## Parameters

### `ppin` [in]

Pointer to the pin to disconnect and reconnect.

### `pmt` [in]

Pointer to the media type to reconnect with. Specify **NULL** to use the existing media type.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **S_FALSE** | Pin was not connected. No error. |
| **E_FAIL** | Failure. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_NOT_STOPPED** | The filter is not stopped, but it does not support reconnection while in a running state. |

## Remarks

Filters can call this method in order to renegotiate a pin connection. The method executes on a separate thread. Before calling this method, call [IPin::QueryAccept](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-queryaccept) on the other pin to ensure that the reconnection attempt will succeed. Do not call this method unless **QueryAccept** returns S_OK. Otherwise, because the reconnection is performed asynchronously, the reconnection might fail even though the `ReconnectEx` method succeeds, leaving the filter graph in an inconsistent state.

This method improves on the [IFilterGraph::Reconnect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifiltergraph-reconnect) method by specifying a media type. This makes the reconnection more likely to succeed.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterGraph2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltergraph2)

[Reconnecting Pins](https://learn.microsoft.com/windows/desktop/DirectShow/reconnecting-pins)