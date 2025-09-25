# IBaseFilter::QueryFilterInfo

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `QueryFilterInfo` method retrieves information about the filter.

## Parameters

### `pInfo` [out]

Pointer to a [FILTER_INFO](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-filter_info) structure.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |
| **E_POINTER** | **NULL** pointer argument |

## Remarks

This method fills the **FILTER_INFO** structure with the filter information. On return, if the **pGraph** member of the **FILTER_INFO** structure is non-**NULL**, the [IFilterGraph](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltergraph) interface has an outstanding reference count. Be sure to release the interface when you are done.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBaseFilter Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter)