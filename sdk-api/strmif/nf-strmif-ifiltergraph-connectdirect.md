# IFilterGraph::ConnectDirect

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ConnectDirect` method connects the two pins directly (without intervening filters).

## Parameters

### `ppinOut` [in]

Pointer to the output pin.

### `ppinIn` [in]

Pointer to the input pin.

### `pmt` [in]

Pointer to the media type to use for the connection (optional; can be **NULL**).

## Return value

Returns one of the following values, or an error value returned by [IPin::Connect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-connect).

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_NOT_IN_GRAPH** | One of the specified pins is not in the graph. |
| **VFW_E_CIRCULAR_GRAPH** | The input pin is upstream of the output pin, which would result in a circular graph. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterGraph Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltergraph)