# IGraphConfig::EnumCacheFilter

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `EnumCacheFilter` method enumerates the filters in the filter cache.

## Parameters

### `pEnum` [out]

Receives a pointer to the [IEnumFilters](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ienumfilters) interface on the filter enumerator. The caller must release the interface.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Failed to allocate necessary memory. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGraphConfig Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphconfig)