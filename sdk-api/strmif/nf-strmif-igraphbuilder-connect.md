# IGraphBuilder::Connect

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Connect` method connects the two pins, using intermediates if necessary.

## Parameters

### `ppinOut` [in]

Pointer to the [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface on the output pin.

### `ppinIn` [in]

Pointer to the **IPin** interface on the input pin.

## Return value

Returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_S_PARTIAL_RENDER** | Partial success; some of the streams from this pin use an unsupported format. |
| **E_ABORT** | Operation aborted. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_CANNOT_CONNECT** | No combination of intermediate filters could be found to make the connection. |
| **VFW_E_NOT_IN_GRAPH** | At least one of the filters is not in the filter graph. |

## Remarks

This method connects two pins directly or indirectly, adding intermediate filters if necessary. The method starts by attempting a direct connection. If that fails, it tries to use any filters that are already in the filter graph and have unconnected input pins. (It enumerates these in an arbitrary order.) If that fails, it searches for filters in the registry, and tries them in order of merit. For more information, see [Intelligent Connect](https://learn.microsoft.com/windows/desktop/DirectShow/intelligent-connect).

During the connection process, the Filter Graph Manager ignores pins on intermediate filters if the pin name begins with a tilde (~). For more information, see [PIN_INFO](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-pin_info).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGraphBuilder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphbuilder)