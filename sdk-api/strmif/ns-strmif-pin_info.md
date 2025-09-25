# PIN_INFO structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `PIN_INFO` structure contains information about a pin.

## Members

### `pFilter`

Pointer to the [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface of the owning filter.

### `dir`

Direction of the pin (input or output).

### `achName`

Name of the pin.

## Remarks

If the name of an output pin begins with a tilde (~), the filter graph manager ignores the pin when it builds a graph. During a call to [IGraphBuilder::Connect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphbuilder-connect), [IGraphBuilder::Render](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphbuilder-render), or [IGraphBuilder::RenderFile](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphbuilder-renderfile), if the pin appears on an intermediate filter, the filter graph manager does not render the pin. However, it renders the pin if you explicitly pass the pin to the **Connect** or **Render** method.

Use a tilde if the pin delivers a secondary stream that should not be rendered by default, or if the pin requires special code to render correctly. For example, DVD filters should use it for pins that deliver subpicture or closed captioning data. Video capture filters should use it for capture pins (but not preview pins).

The **pFilter** member has an outstanding reference count. The application must release the interface.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[IPin::QueryPinInfo](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-querypininfo)