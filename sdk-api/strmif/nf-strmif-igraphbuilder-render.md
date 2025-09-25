# IGraphBuilder::Render

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Render` method builds a filter graph that renders the data from a specified output pin.

## Parameters

### `ppinOut` [in]

Pointer to the [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface on an output pin.

## Return value

Returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_S_AUDIO_NOT_RENDERED** | Partial success; the audio was not rendered. |
| **VFW_S_DUPLICATE_NAME** | Success; the Filter Graph Manager modified a filter name to avoid duplication. |
| **VFW_S_PARTIAL_RENDER** | Partial success; some of the streams in this movie are in an unsupported format. |
| **VFW_S_VIDEO_NOT_RENDERED** | Partial success; the video was not rendered. |
| **E_ABORT** | Operation aborted. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_CANNOT_CONNECT** | No combination of intermediate filters could be found to make the connection. |
| **VFW_E_CANNOT_RENDER** | No combination of filters could be found to render the stream. |
| **VFW_E_NO_ACCEPTABLE_TYPES** | There is no common media type between these pins. |
| **VFW_E_NOT_IN_GRAPH** | The filter to which this pin belongs is not in the filter graph. |

## Remarks

This method renders the data from a specified output pin, adding new filters to the graph as needed. Filters are tried in the same order as for the [IGraphBuilder::Connect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphbuilder-connect) method. For more information, see [Intelligent Connect](https://learn.microsoft.com/windows/desktop/DirectShow/intelligent-connect).

During the connection process, the Filter Graph Manager ignores pins on intermediate filters if the pin name begins with a tilde (~). For more information, see [PIN_INFO](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-pin_info).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGraphBuilder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphbuilder)