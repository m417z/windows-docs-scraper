# IOverlay::GetDefaultColorKey

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetDefaultColorKey` method retrieves the default color key used for a chroma key overlay.

## Parameters

### `pColorKey` [out]

Pointer to a variable that receives the default color key.

## Return value

Returns S_OK if successful. If the method fails, it returns an **HRESULT** error code.

## Remarks

A filter using color keys can get a default color from the video renderer. The default color key can then be installed into the window using [IOverlay::SetColorKey](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ioverlay-setcolorkey). The colors returned through this method vary depending on the current display mode. If the colors are 8-bit palettized, they will be bright system colors (such as magenta). If the display is in a true-color mode, they will be shades of black.

The [IOverlay](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ioverlay) interface is used to ensure that separate instances of the renderer on the same computer get different color keys so that overlays do not conflict.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IOverlay Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ioverlay)