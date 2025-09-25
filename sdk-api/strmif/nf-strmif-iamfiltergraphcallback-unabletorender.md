# IAMFilterGraphCallback::UnableToRender

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `UnableToRender` method is called by the Filter Graph Manager if it cannot find any combination of filters to render the specified pin.

## Parameters

### `pPin`

Specifies the [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface of the pin that could not be rendered.

## Return value

If the return value is S_OK, this Filter Graph Manager attempts to render the pin again. For any other return value, including S_FALSE and other success codes, the Filter Graph Manager continues to build the graph as normal. Typically it will reject the current filter and attempt to use a different filter.

## Remarks

The Filter Graph Manager holds a graph-wide critical section while it calls this method. Therefore, the callback method should avoid calling any methods on the Filter Graph Manager, or any methods on filters that might change the graph state (such as disconnecting pins). Doing so might cause a deadlock or other unexpected behaviors. However, it is safe to query the pin for an interface or check the pin's preferred media type. The main use for this method would be to register a new filter, such as a decoder.

This method uses the thiscall calling convention, rather than __stdcall.

## See also

[IAMFilterGraphCallback Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamfiltergraphcallback)

[Intelligent Connect](https://learn.microsoft.com/windows/desktop/DirectShow/intelligent-connect)