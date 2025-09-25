# IGraphConfig::Reconfigure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Reconfigure` method locks the filter graph and calls a callback function in the application or filter to perform a dynamic reconfiguration.

## Parameters

### `pCallback` [in]

Pointer to the [IGraphConfigCallback](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphconfigcallback) callback interface on the application or filter.

### `pvContext` [in]

Pointer to a variable of type **PVOID** that is passed to the callback routine.

### `dwFlags` [in]

Application-defined flags that are passed to the callback routine.

### `hAbortEvent` [in]

Handle to an event. If the caller is a filter calling on one of its data processing threads, this parameter should be a handle to an event that will be signaled when the filter is put into a stopped state. Otherwise, this parameter can be **NULL**. For more information, see Remarks.

## Return value

Returns S_OK if successful, or an error code otherwise. Possible errors include VFW_E_WRONG_STATE, if the method could not obtain a lock on the filter graph; whatever **HRESULT** was returned by the callback routine; or an error code indicating that the graph could not put the filters into a running state.

## Remarks

This method is provided so that an application or filter can implement specialized dynamic graph building. In most cases, however, the [IGraphConfig::Reconnect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphconfig-reconnect) method is adequate, and should be preferred because it handles most of the implementation details.

Before calling this method, block any streams as needed and push the data through the graph (see [IPinFlowControl::Block](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipinflowcontrol-block) and [IGraphConfig::PushThroughData](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphconfig-pushthroughdata)). If the callback method succeeds, `IGraphConfig::Reconfigure` attempts to put all the filters into a running state. (The caller must then unblock the data flow.) Otherwise, it returns whatever error code the callback method returned.

If a filter calls this method on one of its own data processing threads, it creates the potential for a deadlock. The method obtains a lock on the filter graph, which can block the filter from stopping on receiving a call to [IMediaFilter::Stop](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediafilter-stop). To prevent this situation, the method takes a handle to an event object provided by filter. The filter should signal the event if it receives a call to its **Stop** method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGraphConfig Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphconfig)