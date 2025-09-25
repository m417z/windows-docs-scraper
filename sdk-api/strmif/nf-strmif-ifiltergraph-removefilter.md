# IFilterGraph::RemoveFilter

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `RemoveFilter` method removes a filter from the graph.

## Parameters

### `pFilter` [in]

Pointer to the filter to be removed from the graph.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | Failure. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

The Filter Graph Manager notifies the filter that it is being removed by calling the filter's [IBaseFilter::JoinFilterGraph](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ibasefilter-joinfiltergraph) method with a **NULL** argument. It is not necessary to disconnect the filter's pins before calling `RemoveFilter`, but the filter graph should be in the Stopped state. If the filters are not stopped, `RemoveFilter` may fail to disconnect the pins and then fail to remove the filter from the graph. [IGraphConfig::RemoveFilterEx](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphconfig-removefilterex) enables an application to remove a filter without disconnecting the pins automatically, which improves performance if you want to move groups of connected filters into a new graph.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterGraph Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltergraph)