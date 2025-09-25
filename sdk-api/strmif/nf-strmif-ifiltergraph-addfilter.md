# IFilterGraph::AddFilter

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `AddFilter` method adds a filter to the graph.

## Parameters

### `pFilter` [in]

Pointer to the [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface of the filter to add.

### `pName` [in]

Pointer to a wide-character string containing a name for filter.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_S_DUPLICATE_NAME** | Successfully added a filter with a duplicate name. |
| **E_FAIL** | Failure. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_CERTIFICATION_FAILURE** | Use of this filter is restricted by a software key. |
| **VFW_E_DUPLICATE_NAME** | Failed to add a filter with a duplicate name. |

## Remarks

The name of the filter can be **NULL**, in which case the Filter Graph Manager generates a name. If the name is not **NULL** and is not unique, this method will modify the name in an attempt to generate a new unique name. If this is successful, this method returns VFW_S_DUPLICATE_NAME. If it cannot generate a unique name, it returns VFW_E_DUPLICATE_NAME.

`AddFilter` calls the filter's [IBaseFilter::JoinFilterGraph](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ibasefilter-joinfiltergraph) method to inform the filter that it has been added. `AddFilter` must be called before attempting to use the [IGraphBuilder::Connect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphbuilder-connect), [IFilterGraph::ConnectDirect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifiltergraph-connectdirect), or [IGraphBuilder::Render](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphbuilder-render) method to connect or render pins belonging to the added filter.

The Filter Graph Manager holds a reference count on the filter until the filter is removed from the graph or the Filter Graph Manager is released.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterGraph Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltergraph)