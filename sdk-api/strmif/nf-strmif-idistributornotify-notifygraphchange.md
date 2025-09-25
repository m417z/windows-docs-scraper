# IDistributorNotify::NotifyGraphChange

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `NotifyGraphChange` method is called when the set of filters in the filter graph changes or any pin connections change.

## Return value

Returns an **HRESULT** value.

## Remarks

This method is called whenever the [IFilterGraph::AddFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifiltergraph-addfilter), [IFilterGraph::RemoveFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifiltergraph-removefilter), or [IFilterGraph::ConnectDirect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ifiltergraph-connectdirect) method is called or a method is called that will lead to one of these being called (such as [IGraphBuilder::RenderFile](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphbuilder-renderfile)).

Make sure you call **Release** on any held filters that have been removed at this point. For performance reasons, PIDs might choose not to rescan the filters until the PIDs actually need the interfaces, because there might be several separate notifications sent. However, it is important to release any cached interfaces immediately.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDistributorNotify Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idistributornotify)