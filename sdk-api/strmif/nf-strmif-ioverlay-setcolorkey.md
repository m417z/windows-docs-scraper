# IOverlay::SetColorKey

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetColorKey` method changes the color key.

## Parameters

### `pColorKey` [in, out]

Pointer to the color key value to be set. If successful, the actual color key value selected is copied to this parameter.

## Return value

Returns S_OK if successful, E_POINTER if *pColorKey* is **NULL**, or E_INVALIDARG if the value of *pColorKey* is invalid for the current palette or pixel format.

## Remarks

If you change the color key using the `SetColorKey` method, all the advise links will receive an [IOverlayNotify::OnColorKeyChange](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ioverlaynotify-oncolorkeychange) callback method with the new color.

When using [IOverlay::Advise](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ioverlay-advise) on a palettized display, a filter can either install a color key (using `SetColorKey`) or install a palette (using [IOverlay::SetPalette](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ioverlay-setpalette)), but not both. This is because color keys in this mode require a palette to be realized that would conflict with **SetPalette**. Color keys can be uninstalled by requesting a color key with the CK_NOCOLORKEY flag. Likewise, any palette installed through **SetPalette** can be uninstalled by calling **SetPalette** and passing in **NULL** parameters (that is, SetPalette(0,**NULL**)).

Trying to set a palette when a color key is installed returns a VFW_E_PALETTE_SET error. Trying to set a color key when a palette is installed returns VFW_E_COLOR_KEY_SET.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IOverlay Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ioverlay)