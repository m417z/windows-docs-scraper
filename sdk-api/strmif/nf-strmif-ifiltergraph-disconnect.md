# IFilterGraph::Disconnect

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Disconnect` method disconnects this pin.

## Parameters

### `ppin` [in]

Pointer to the pin to disconnect.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **S_FALSE** | Pin was not connected. No error. |
| **E_FAIL** | Failure. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_NOT_STOPPED** | The filter is not stopped, but does not support reconnection while in a running state. |

## Remarks

This method does not completely break the connection. To completely break the connection, both ends must be disconnected.

To remove a filter from the filter graph entirely, call the [IFilterGraph::RemoveFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifiltergraph-removefilter) method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterGraph Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltergraph)