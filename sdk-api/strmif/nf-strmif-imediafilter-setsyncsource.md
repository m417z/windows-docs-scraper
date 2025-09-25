# IMediaFilter::SetSyncSource

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetSyncSource` method sets the reference clock.

## Parameters

### `pClock` [in]

Pointer to the clock's [IReferenceClock](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ireferenceclock) interface, or **NULL**. If this parameter is **NULL**, the filter graph does not use a reference clock, and all filters run as quickly as possible.

## Return value

Returns S_OK if successful, or an **HRESULT** value indicating the cause of the error.

## Remarks

All the filters in the filter graph share the same reference clock, in order to stay synchronized. Stream time is calculated from the reference clock. Renderer filters use the reference clock to schedule when they render samples. If there is no reference clock, a renderer filter renders every sample as soon as it arrives.

This method is implemented by all DirectShow filters, and also by the Filter Graph Manager.

### Filter Implementation

When the graph runs, the Filter Graph manager calls this method on every filter in the graph, to notify them of the graph reference clock. Use this method to store the [IReferenceClock](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ireferenceclock) pointer. Increment the reference count on the stored pointer. Before the filter is removed from the graph, the Filter Graph Manager calls **SetSyncSource** again with the value **NULL**. Release the stored pointer and set it to **NULL**.

The [CBaseFilter](https://learn.microsoft.com/windows/desktop/DirectShow/cbasefilter) class implements this method; see [CBaseFilter::SetSyncSource](https://learn.microsoft.com/windows/desktop/DirectShow/cbasefilter-setsyncsource).

Note that filters cannot use this method to select the graph clock. In filters, the only function of this method is to inform the filter of the clock that the graph is using. A filter can provide a reference clock by exposing the [IReferenceClock](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ireferenceclock) interface. For more information, see [Time and Clocks in DirectShow](https://learn.microsoft.com/windows/desktop/DirectShow/time-and-clocks-in-directshow).

### Application Use

An application can override the default clock by calling **SetSyncSource** on the Filter Graph Manager. Do not do this unless you have a particular reason to prefer another clock. You can also set the graph not to use any reference clock, by calling **SetSyncSource** with the value **NULL**. You might do this to process samples as quickly as possible. For more information, see [Setting the Graph Clock](https://learn.microsoft.com/windows/desktop/DirectShow/setting-the-graph-clock).

Applications should never call this method on filters.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterGraph::SetDefaultSyncSource](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifiltergraph-setdefaultsyncsource)

[IMediaFilter Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediafilter)