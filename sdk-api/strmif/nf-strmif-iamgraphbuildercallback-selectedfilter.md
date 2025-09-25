# IAMGraphBuilderCallback::SelectedFilter

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The Filter Graph Manager calls this method when it finds a candidate filter for the graph, but before it creates the filter.

## Parameters

### `pMon`

Pointer to a moniker that contains information about the filter.

## Return value

If the method returns a success code, the Filter Graph Manager creates the filter and tries to connect it. If the method returns a failure code, the Filter Graph Manager rejects the filter.

## Remarks

This method enables the client to examine a filter to determine whether it is acceptable for the current filter graph.

The Filter Graph Manager holds a graph-wide critical section while it calls this method. Therefore, the callback method should avoid calling any methods on the Filter Graph Manager, or any methods on filters that might change the graph state (such as disconnecting pins). Doing so might cause a deadlock or other unexpected behaviors.

## See also

[IAMGraphBuilderCallback Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamgraphbuildercallback)