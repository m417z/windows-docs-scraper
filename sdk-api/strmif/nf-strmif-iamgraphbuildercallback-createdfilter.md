# IAMGraphBuilderCallback::CreatedFilter

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The Filter Graph Manager calls this method after it has created a filter, but before it attempts to connect the filter.

## Parameters

### `pFil`

Pointer to the [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface of the filter.

## Return value

If the method returns a success code, the Filter Graph Manager tries to connect the filter. If the method returns a failure code, the Filter Graph Manager rejects the filter.

## Remarks

This method enables the client to configure the filter immediately after it has been created. The Video Mixing Renderer is the primary example of a filter that requires configuration before it is connected. Most other DirectShow filters can be configured after they are connected.

The Filter Graph Manager holds a graph-wide critical section while it calls this method. Therefore, the callback method should avoid calling any methods on the Filter Graph Manager, or any methods on filters that might change the graph state (such as disconnecting pins). Doing so might cause a deadlock or other unexpected behaviors.

## See also

[IAMGraphBuilderCallback Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamgraphbuildercallback)