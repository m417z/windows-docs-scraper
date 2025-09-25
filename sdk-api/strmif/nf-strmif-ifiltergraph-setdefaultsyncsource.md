# IFilterGraph::SetDefaultSyncSource

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetDefaultSyncSource` method sets the reference clock to the default clock.

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_E_NOT_STOPPED** | The filter graph is not stopped. |

## Remarks

This method instructs the Filter Graph Manager to choose a reference clock using its default algorithm. For more information about the algorithm that it uses, see [Reference Clocks](https://learn.microsoft.com/windows/desktop/DirectShow/reference-clocks).

Usually you do not need to call this method, because the Filter Graph Manager automatically selects a clock. However, if you call [IMediaFilter::SetSyncSource](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediafilter-setsyncsource) to override the clock, you can use `SetDefaultSyncSource` to restore the default clock.

This method fails if the filter graph is running or paused.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterGraph Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltergraph)

[Time and Clocks in DirectShow](https://learn.microsoft.com/windows/desktop/DirectShow/time-and-clocks-in-directshow)