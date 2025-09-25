# IOverlay::GetColorKey

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetColorKey` method retrieves the current color key used for chroma keying.

## Parameters

### `pColorKey` [out]

Pointer to a variable that receives the current color key for chroma keying.

## Return value

Returns S_OK if successful. If the method fails, it returns an **HRESULT** error code.

## Remarks

If you change the color key by using the [IOverlay::SetColorKey](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ioverlay-setcolorkey) method, all the advise links receive an [IOverlayNotify::OnColorKeyChange](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ioverlaynotify-oncolorkeychange) callback method with the new color.

If no color key is currently being used, this method returns VFW_E_NO_COLOR_KEY_SET.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IOverlay Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ioverlay)