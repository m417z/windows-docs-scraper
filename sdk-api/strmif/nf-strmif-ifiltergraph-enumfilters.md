# IFilterGraph::EnumFilters

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `EnumFilters` method provides an enumerator for all filters in the graph.

## Parameters

### `ppEnum` [out]

Receives a pointer to the [IEnumFilters](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ienumfilters) interface. Use this interface to enumerate the filters. The caller must release the interface.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Insufficient memory to create the enumerator. |
| **E_POINTER** | **NULL** pointer argument. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterGraph Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltergraph)