# IBaseFilter::JoinFilterGraph

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `JoinFilterGraph` method notifies the filter that it has joined or left the filter graph.

## Parameters

### `pGraph` [in]

Pointer to the Filter Graph Manager's [IFilterGraph](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltergraph) interface, or **NULL** if the filter is leaving the graph.

### `pName` [in]

Pointer to a wide-character string that specifies a name for the filter.

## Return value

Returns S_OK if successful, or an **HRESULT** value indicating the cause of the error.

## Remarks

When the Filter Graph Manager adds a filter to the filter graph, it calls this method with a pointer to itself. It assigns a name for this instance of the filter through the *pName* parameter. The name can be retrieved by calling the [IBaseFilter::QueryFilterInfo](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ibasefilter-queryfilterinfo) method.

When the Filter Graph Manager removes the filter from the graph, it calls this method with a **NULL** pointer.

Applications should never call this method. To add a filter to the graph, call the [IFilterGraph::AddFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifiltergraph-addfilter) method on the filter graph manager.

**Filter developers**: The filter can store the **IFilterGraph** interface pointer and query it for other Filter Graph Manager interfaces. However, it must never hold a reference count on the Filter Graph Manager. Doing so creates a circular reference count, because the Filter Graph Manager keeps a reference count on the filter. A circular reference count prevents the interface from being released properly, which can lead to a deadlock. The **IFilterGraph** interface is guaranteed to be valid until the Filter Graph Manager calls this method again with the value **NULL**. For an implementation of this method, see the [CBaseFilter::JoinFilterGraph](https://learn.microsoft.com/windows/desktop/DirectShow/cbasefilter-joinfiltergraph) method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBaseFilter Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter)