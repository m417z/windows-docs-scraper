# IVPBaseConfig::SetSurfaceParameters

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetSurfaceParameters` method informs the device of the layout of the overlay surface. The downstream filter (the Overlay Mixer, VBI Surface Allocator, or Video Port Manager) calls this method after it creates the overlay surface.

## Parameters

### `dwPitch` [in]

Specifies the stride of the surface (also called the *pitch*), in pixels.

### `dwXOrigin` [in]

Specifies the X-coordinate of the pixel at which valid data starts.

### `dwYOrigin` [in]

Specifies the Y-coordinate of the pixel at which valid data starts.

## Return value

Returns S_OK if successful, or E_NOTIMPL.

## Remarks

Include Dvp.h and Vptype.h before Vpconfig.h.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVPBaseConfig Interface](https://learn.microsoft.com/windows/desktop/api/vpconfig/nn-vpconfig-ivpbaseconfig)