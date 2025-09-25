# ICaptureGraphBuilder::FindInterface

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **ICaptureGraphBuilder** interface is deprecated. Use [ICaptureGraphBuilder2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder2) instead.

Looks for the specified interface on the filter, upstream and downstream from the filter, and, optionally, only on the output pin of the given category.

## Parameters

### `pCategory` [in]

Pointer to a GUID specifying the output pin category. See [Pin Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/pin-property-set) for a list of all pin categories. **NULL** indicates search all the output pins regardless of category.

### `pf` [in]

Pointer to the [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface of the filter.

### `riid` [in]

Reference ID of the desired interface.

### `ppint` [out]

Address of a void pointer. If the interface was found, this method initializes *ppint* so that it contains the address of a pointer to the found interface. Call the **Release** method to decrement the reference count when you're done with the interface.

## Return value

Returns an **HRESULT** value.

## Remarks

This method looks for the interface on the filter, and upstream and downstream of the filter, unless a category is given. If a category is given, it only looks downstream of the output pin of that category. It can be used to find interfaces on renderers, multiplexers, TV tuners, crossbars, and so forth.

If *pCategory* equals &LOOK_UPSTREAM_ONLY, then the graph builder will look upstream of the filter given in parameter *pf*, but not on the filter itself, nor downstream of the filter.

If *pCategory* equals &LOOK_DOWNSTREAM_ONLY, then the graph builder will look downstream of the filter given in parameter *pf*, but not on the filter itself, nor upstream of the filter.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICaptureGraphBuilder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder)