# IAMOverlayFX::GetOverlayFX

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetOverlayFX` method retrieves the effects currently applied to the overlay surface, if any. The application can call this method while the filter graph is running.

## Parameters

### `lpdwOverlayFX` [out]

Pointer a variable that receives a value indicating which effects, if any, are currently applied to the overlay surface. The value is a logical combination of flags from the [AMOVERLAYFX](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-amoverlayfx) enumeration.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface. The DirectShow implementation returns S_OK if successful, or E_POINTER to indicate a **NULL** pointer argument.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMOverlayFX Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamoverlayfx)