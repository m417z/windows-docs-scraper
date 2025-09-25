# IFilterGraph2::RenderEx

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `RenderEx` method renders an output pin, with an option to use existing renderers only.

## Parameters

### `pPinOut` [in]

Pointer to the [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface of the output pin.

### `dwFlags` [in]

Flag that specifies how to render the pin. If the value is AM_RENDEREX_RENDERTOEXISTINGRENDERERS, the method attempts to use renderers already in the filter graph. It will not add new renderers to the graph. (It will add intermediate transform filters, if needed.) For the method to succeed, the graph must contain the appropriate renderers, and they must have unconnected input pins. If the value is zero, the method behaves identically to the [IGraphBuilder::Render](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphbuilder-render) method.

### `pvContext` [in, out]

Reserved. Must be **NULL**.

## Return value

Returns an **HRESULT**.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterGraph2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltergraph2)