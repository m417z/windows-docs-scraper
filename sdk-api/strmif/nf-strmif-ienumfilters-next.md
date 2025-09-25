# IEnumFilters::Next

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Next` method retrieves the specified number of filters in the enumeration sequence.

## Parameters

### `cFilters` [in]

Number of filters to retrieve.

### `ppFilter` [out]

Array of size *cFilters* that is filled with [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface pointers. The caller must release the interfaces.

### `pcFetched` [out]

Receives the number of filters retrieved. Can be **NULL** if *cFilters* is 1.

## Return value

| Value | Description |
| --- | --- |
| S_FALSE | Did not retrieve as many filters as requested. |
| S_OK | Success. |
| E_INVALIDARG | Invalid argument. |
| E_POINTER | **NULL** pointer argument. |
| VFW_E_ENUM_OUT_OF_SYNC | The graph has changed and is now inconsistent with the enumerator. |

## Remarks

If the method succeeds, the **IBaseFilter** pointers all have outstanding reference counts. Be sure to release them when you are done.

If the filter graph changes (for example, the application removes a filter), the enumerator is no longer be consistent with the graph, and the method returns VFW_E_ENUM_OUT_OF_SYNC. Discard any data obtained from previous calls to the enumerator, because it might be invalid. Update the enumerator by calling the [IEnumFilters::Reset](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ienumfilters-reset) method. You can then call the `Next` method safely.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IEnumFilters Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ienumfilters)