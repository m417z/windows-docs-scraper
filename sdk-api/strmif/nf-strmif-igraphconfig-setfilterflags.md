# IGraphConfig::SetFilterFlags

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetFilterFlags` method sets a filter's configuration information.

## Parameters

### `pFilter` [in]

Pointer to the [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface of a filter in the filter graph.

### `dwFlags` [in]

Value specifying the new configuration flags. Must be one of the following values.

| Value | Description |
| --- | --- |
| Zero | No flags set. |
| AM_FILTER_FLAGS_REMOVABLE | The filter is removable during a dynamic reconnection. For more information, see Remarks. |

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument. |
| **E_INVALIDARG** | Invalid argument. |
| **S_OK** | Success. |
| **VFW_E_NOT_IN_GRAPH** | The filter is not in the graph. |

## Remarks

The AM_FILTER_FLAGS_REMOVABLE flag changes the behavior of the [IGraphConfig::Reconnect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphconfig-reconnect) method. The **Reconnect** method performs a dynamic reconnection between two pins. If the caller specifies one pin, but leaves the other pin unspecified, **Reconnect** searches upstream or downstream from the specified pin to find a suitable match. By default, however, the search fails if it reaches a filter that was added to the graph by means of the [IFilterGraph::AddFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifiltergraph-addfilter) method. To override this behavior, call `SetFilterFlags` and set the AM_FILTER_FLAGS_REMOVABLE flag on the filter.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGraphConfig Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphconfig)