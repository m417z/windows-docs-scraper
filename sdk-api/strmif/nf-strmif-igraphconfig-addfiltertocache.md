# IGraphConfig::AddFilterToCache

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `AddFilterToCache` method adds a filter to the filter cache.

## Parameters

### `pFilter` [in]

Pointer to the [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface of the filter.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_FALSE** | Filter is already in the cache. |
| **S_OK** | Filter was added to the cache. |

## Remarks

You must disconnect all of the filter's pins before calling this method, or the method will fail. If the filter is in the filter graph, this method will remove it. This method will also put the filter into a stopped state, if it is not already.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGraphConfig Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphconfig)