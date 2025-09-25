# IFilterGraph3::SetSyncSourceEx

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetSyncSourceEx` method establishes two reference clocks for the filter graph: a primary clock that is used by most of the filters, and a secondary clock that is used only by one specified filter.

## Parameters

### `pClockForMostOfFilterGraph` [in]

Pointer to the [IReferenceClock](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ireferenceclock) interface of the main reference clock. Every filter in the graph uses this clock, except for the filter specified by the *pFilter* parameter.

### `pClockForFilter` [in]

Pointer to the **IReferenceClock** interface of the secondary clock. The filter specified by the *pFilter* parameter uses this clock.

### `pFilter` [in]

Pointer to the [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface of a filter in the graph. This filter uses the secondary reference clock.

## Return value

Returns and **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_E_NOT_STOPPED** | The filter graph is not stopped. |

## Remarks

If the filter graph is running or paused, this method return VFW_E_NOT_STOPPED.

To clear both reference clocks, set all three parameters to **NULL**. To set a single clock for the entire graph, with no secondary clock, call the [IMediaFilter::SetSyncSource](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediafilter-setsyncsource) method on the Filter Graph Manager.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterGraph3 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltergraph3)