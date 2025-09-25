# IGraphConfig::Reconnect

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Reconnect` method performs a dynamic reconnection between two pins.

## Parameters

### `pOutputPin` [in]

Pointer to the [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface of an output pin. Can be **NULL**, in which case *pInputPin* must not be **NULL**.

### `pInputPin` [in]

Pointer the [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface to an input pin. Can be **NULL**, in which case *pOutputPin* must not be **NULL**.

### `pmtFirstConnection` [in]

Pointer to an [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure that specifies the media type for the first pin connection made during the reconnection. If this parameter is **NULL**, the first connection can have any media type.

### `pUsingFilter` [in]

Pointer to an optional filter to use in the reconnection. The filter must already be in the graph. Can be **NULL**.

### `hAbortEvent` [in]

Handle to an event. If the caller is a filter calling on one of its data processing threads, this parameter should be a handle to an event that will be signaled when the filter is put into a stopped state. Otherwise, this parameter can be **NULL**. For more information, see Remarks.

### `dwFlags` [in]

Combination of flags from the [AM_GRAPH_CONFIG_RECONNECT_FLAGS](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-am_graph_config_reconnect_flags) enumeration, specifying how to perform the reconnection.

## Return value

Returns S_OK if successful. Otherwise, returns an error code that may be one of the following values, or others not listed.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. (For example, both *pInputPin* and *pOutputPin* are **NULL**.) |
| **E_NOINTERFACE** | Input pin does not support [IPinConnection](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipinconnection). |
| **VFW_E_CANNOT_CONNECT** | Unable to connect filter. |
| **VFW_E_STATE_CHANGED** | The state of the filter changed. Unable to complete the operation. |

## Remarks

If you specify only one pin, the method will search for the other pin. By default, however, the search fails if it reaches a filter that was added to the graph by means of the [IFilterGraph::AddFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifiltergraph-addfilter) method. To override this behavior, call [IGraphConfig::SetFilterFlags](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphconfig-setfilterflags) and set the AM_FILTER_FLAGS_REMOVABLE flag on the filter.

The reconnection process involves several steps, most of them handled inside this method:

1. First, before calling the method, make sure to block the flow of data along the path that is being reconfigured. Applications should call the [IPinFlowControl::Block](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipinflowcontrol-block) method to do this. If the caller is a filter, rather than an application, possibly the filter can control the data flow internally.
2. The specified output and input pins define the starting and ending points for the reconnection. The input pin must support the [IPinConnection](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipinconnection) interface. If you leave one of these pins unspecified (by passing a **NULL** parameter), the method searches the filter graph to find a candidate pin for reconnection. (To find an input pin, it searches downstream from the output pin; to find an output pin, it searches upstream from the input pin.)
3. The method pushes any pending data through the filter graph (through an internal call to [IGraphConfig::PushThroughData](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphconfig-pushthroughdata)).
4. If you have specified a filter to insert into the graph, the method connects the starting output pin to the filter's input pin, and connects the filter's output pin to the final input pin. If you do not specify a filter, the method simply connects the output pin to the input pin. In either case, the method inserts any transform filters required to complete the connections. (However, you can override this behavior by setting the appropriate flag; for more information see the description of the *dwFlags* parameter.)
5. Finally, the method places the new filters into a running state. It is up to the caller to restart the data flow. Applications can do this by calling [IPinFlowControl::Block](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipinflowcontrol-block) with no flags.

If a filter calls this method on one of its own data processing threads, it creates the potential for a deadlock. The method obtains a lock on the filter graph, which can block the filter from stopping on receiving a call to [IMediaFilter::Stop](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediafilter-stop). To prevent this situation, the method takes a handle to an event object provided by filter. The filter should signal the event if it receives a call to its **Stop** method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGraphConfig Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphconfig)