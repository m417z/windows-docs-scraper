# IPin::QueryInternalConnections

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **QueryInternalConnections** method retrieves the pins that are connected internally to this pin (within the filter).

## Parameters

### `apPin` [out]

Address of an array of [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) pointers. The caller allocates the array. The method fills the array with **IPin** pointers. If *nPin* is zero, this parameter can be **NULL**.

### `nPin` [in, out]

On input, specifies the size of the array. On output, specifies the number of internally connected pins.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | Insufficient array size. |
| **S_OK** | Success. |
| **E_NOTIMPL** | Not implemented. |

## Remarks

This method returns information about the filter's internal mapping of input pins to output pins. In other words, it describes how the input pins deliver data to the output pins.

In most filters, every input pin connects to every output pin. For example, in a transform filter, one input connects to one output; in a splitter filter, one input connects to multiple outputs. In these cases, the method should simply return E_NOTIMPL.

Otherwise, the method returns an array of **IPin** pointers, one for each pin that is mapped internally to the pin you have queried. If you call the method on an input pin, the array contains pointers to output pins, and vice versa.

The caller allocates the array of **IPin** pointers. To get the required array size, call the method once with *apPin* equal to **NULL**. The size is returned in the *nPin* parameter. Then allocate the array and call the method again, setting *apPin* equal to the address of the array and *nPin* equal to the array size. The method then fills the array with **IPin** pointers. Each returned pointer has an outstanding reference count and must be released by the caller.

This method has another use that is now deprecated: The [Filter Graph Manager](https://learn.microsoft.com/windows/desktop/DirectShow/filter-graph-manager) treats a filter as being a renderer filter if at least one input pin implements this method but returns zero in *nPin*. If you are writing a new renderer filter, however, you should implement the [IAMFilterMiscFlags](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamfiltermiscflags) interface instead of using this method to indicate that the filter is a renderer.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IPin Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin)