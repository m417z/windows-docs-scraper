# IOverlay::SetPalette

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetPalette` method sets the palette.

## Parameters

### `dwColors` [in]

Number of colors present.

### `pPalette` [in]

Pointer to colors to use for the palette.

## Return value

Returns S_OK if successful. If the method fails, it returns an **HRESULT** error code.

## Remarks

This method sets a logical palette for the window. The window is not guaranteed to always have the colors requested in the actual system device palette. The Microsoft® Windows® operating system only guarantees those colors when the window is the foreground active window. The current device palette can be obtained by calling [IOverlay::GetPalette](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ioverlay-getpalette).

If the device does not have a palette, it returns VFW_E_NO_DISPLAY_PALETTE.

The [Overlay Mixer](https://learn.microsoft.com/windows/desktop/DirectShow/overlay-mixer-filter) filter returns E_NOTIMPL.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IOverlay Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ioverlay)