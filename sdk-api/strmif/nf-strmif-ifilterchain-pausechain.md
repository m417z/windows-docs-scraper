# IFilterChain::PauseChain

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `PauseChain` method switches all the filters in a filter chain into a paused state.

## Parameters

### `pStartFilter` [in]

A pointer to the [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface of the filter at the start of the chain.

### `pEndFilter` [in]

A pointer to the [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface of the filter at the end of the chain. If this parameter is **NULL**, the method uses the longest possible filter chain that extends downstream from the start filter.

## Return value

Returns S_OK if successful. If the method fails, the return value may be VFW_E_NOT_PAUSED or another **HRESULT** value.

## Remarks

If this method cannot switch a given filter into a paused state, it stops all of the filters in chain. The filter graph must be paused when you call this method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterChain Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifilterchain)