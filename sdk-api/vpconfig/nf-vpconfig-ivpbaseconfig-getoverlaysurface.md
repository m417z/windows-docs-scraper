# IVPBaseConfig::GetOverlaySurface

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetOverlaySurface` method queries whether the caller should use the driver's overlay surface. If so, the method returns a pointer to the surface.

## Parameters

### `ppddOverlaySurface` [out]

Address of a pointer to the **IDirectDrawSurface** interface. If the caller should use the driver's overlay surface, it sets this variable equal to the **IDirectDrawSurface** interface for the overlay surface.

## Return value

Returns S_OK if the overlay surface object was returned.

## Remarks

The [Overlay Mixer](https://learn.microsoft.com/windows/desktop/DirectShow/overlay-mixer-filter) uses this function to determine if the driver requires the Overlay Mixer to use the driver's overlay surface. If this function returns **NULL**, then the Overlay Mixer allocates its own surface.

Include Dvp.h and Vptype.h before Vpconfig.h.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVPBaseConfig Interface](https://learn.microsoft.com/windows/desktop/api/vpconfig/nn-vpconfig-ivpbaseconfig)