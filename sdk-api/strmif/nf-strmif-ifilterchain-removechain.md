# IFilterChain::RemoveChain

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `RemoveChain` method removes every filter in a filter chain from the filter graph.

## Parameters

### `pStartFilter` [in]

A pointer to the [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface of the filter at the start of the chain.

### `pEndFilter` [in]

A pointer to the [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface of the filter at the end of the chain. If this parameter is **NULL**, the method uses the longest possible filter chain that extends downstream from the start filter.

## Return value

Returns S_OK if successful, or an **HRESULT** value indicating the cause of the failure otherwise.

## Remarks

You can call this method while the graph is running; the method stops the filters in the chain before removing them from the graph.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterChain Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifilterchain)