# IDvdGraphBuilder::GetFiltergraph

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetFiltergraph` method retrieves the [IGraphBuilder](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphbuilder) interface for the filter graph used by the DVD-Video graph builder object.

## Parameters

### `ppGB` [out]

Address of a pointer to the [IGraphBuilder](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphbuilder) interface that the DVD-Video graph builder object is using.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface. The current DirectShow implementation returns E_INVALIDARG if *ppGB* is invalid.

## Remarks

The returned **IGraphBuilder** interface pointer has an outstanding reference count. The caller must release the interface.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdGraphBuilder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdgraphbuilder)