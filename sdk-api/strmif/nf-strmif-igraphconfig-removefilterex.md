# IGraphConfig::RemoveFilterEx

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `RemoveFilterEx` method removes a filter from the filter graph.

## Parameters

### `pFilter` [in]

Pointer to the [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface of the filter to remove from the graph.

### `Flags` [in]

Combination of flags from the [REM_FILTER_FLAGS](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-_rem_filter_flags) enumerated type.

## Return value

Returns S_OK if successful, or an **HRESULT** value indicating the cause of the failure.

## Remarks

This method extends the [IFilterGraph::RemoveFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifiltergraph-removefilter) method by accepting a flag that specifies the behavior of the method. This flag enables an application to remove a filter without disconnecting the pins automatically, which improves performance when moving groups of connected filters into a new graph.

By default, this method disconnects the filter before removing it from the graph. Use the REMFILTERF_LEAVECONNECTED flag to leave the filter connected.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGraphConfig Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphconfig)