# ICaptureGraphBuilder::SetFiltergraph

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **ICaptureGraphBuilder** interface is deprecated. Use [ICaptureGraphBuilder2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder2) instead.

Tells the graph builder object which filter graph to use.

## Parameters

### `pfg` [in]

Pointer to an [IGraphBuilder](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphbuilder) interface that specifies the filter graph to use for subsequent calls to the [IFilterGraph::AddFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifiltergraph-addfilter) method.

## Return value

Returns an **HRESULT** value.

## Remarks

The graph builder will automatically create a filter graph if you don't call this method. If you call this method after the graph builder has created its own filter graph, the call will fail.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICaptureGraphBuilder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icapturegraphbuilder)