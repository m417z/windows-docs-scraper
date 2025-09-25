# IFilterMapper2::UnregisterFilter

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `UnregisterFilter` method removes filter information from the registry.

## Parameters

### `pclsidCategory` [in]

Address of a GUID that specifies the filter category from which to remove the filter. For a list of categories, see [Filter Categories](https://learn.microsoft.com/windows/desktop/DirectShow/filter-categories).

### `szInstance` [in]

Instance data used to construct the device moniker's display name. Use the value that was originally passed to the **RegisterFilter** method.

### `Filter` [in]

Class identifier (CLSID) of the filter.

## Return value

Returns S_OK if successful, or an **HRESULT** value indicating the cause of the error.

## Remarks

If the filter was not registered, the method might return an error.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterMapper2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltermapper2)