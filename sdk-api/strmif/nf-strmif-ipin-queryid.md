# IPin::QueryId

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `QueryId` method retrieves an identifier for the pin.

## Parameters

### `Id` [out]

Receives a string containing the pin identifier.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

This method supports graph persistence. Use this method to save a pin's state, and the [IBaseFilter::FindPin](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ibasefilter-findpin) method to restore the state. The pin's identifier string is defined by the filter implementation. The identifier must be unique within the filter.

**Note** The *pin identifier* is not necessarily the same as the *pin name* that the [QueryPinInfo](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-querypininfo) method returns.

The filter allocates the returned string using the [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) function. The caller must free it using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## See also

[Data Flow in the Filter Graph](https://learn.microsoft.com/windows/desktop/DirectShow/data-flow-in-the-filter-graph)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IPin Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin)