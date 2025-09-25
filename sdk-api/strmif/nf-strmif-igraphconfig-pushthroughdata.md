# IGraphConfig::PushThroughData

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `PushThroughData` method pushes data through the filter graph to the specified pin.

## Parameters

### `pOutputPin` [in]

Pointer to the [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface of an output pin in the filter graph.

### `pConnection` [in]

Pointer to the [IPinConnection](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipinconnection) interface of an input pin in the filter graph. This parameter can be **NULL**.

### `hEventAbort` [in]

Handle to an event. If the caller is a filter calling on one of its data processing threads, this parameter should be a handle to an event that will be signaled when the filter is put into a stopped state. Otherwise, this parameter can be **NULL**. For more information, see Remarks.

## Return value

Returns S_OK if successful. Otherwise, returns an error code that may be one of the following values, or others not listed.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Failed to allocate necessary memory. |
| **VFW_E_NOT_FOUND** | Could not find a candidate input pin. |
| **VFW_E_STATE_CHANGED** | Filter state changed during the operation. |

## Remarks

This method pushes through any pending data, from a specified output pin down to a specified input pin. Optionally, you can leave the input pin unspecified and let the method search the filter graph for the best candidate. Do not call this method from the thread that is pushing data.

If a filter calls this method on one of its own data processing threads, it creates the potential for a deadlock. The method obtains a lock on the filter graph, which can block the filter from stopping on receiving a call to [IMediaFilter::Stop](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediafilter-stop). To prevent this situation, the method takes a handle to an event object provided by the filter. The filter should signal the event if it receives a call to its **Stop** method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGraphConfig Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphconfig)