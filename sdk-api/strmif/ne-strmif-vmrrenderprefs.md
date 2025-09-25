# VMRRenderPrefs enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VMRRenderPrefs** enumeration type is used with the [IVMRFilterConfig::GetRenderingPrefs](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrfilterconfig-getrenderingprefs) and [IVMRFilterConfig::SetRenderingPrefs](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrfilterconfig-setrenderingprefs) methods to get and set basic rendering preferences.

## Constants

### `RenderPrefs_RestrictToInitialMonitor:0`

Not implemented; do not use.

### `RenderPrefs_ForceOffscreen:0x1`

Indicates that the [Video Mixing Renderer Filter 7](https://learn.microsoft.com/windows/desktop/DirectShow/video-mixing-renderer-filter-7) (VMR-7) should use only offscreen surfaces for rendering.

### `RenderPrefs_ForceOverlays:0x2`

Indicates that the VMR-7 should fail if no overlay surfaces are available.

### `RenderPrefs_AllowOverlays:0`

Indicates that the VMR-7 should use overlays if they are available. Should not be used by new applications.

### `RenderPrefs_AllowOffscreen:0`

Indicates that the VMR-7 should use offscreen surfaces if no overlays are available. Should not be used by new applications.

### `RenderPrefs_DoNotRenderColorKeyAndBorder:0x8`

Indicates that the application is responsible for painting the color keys.

### `RenderPrefs_Reserved:0x10`

Reserved; do not use.

### `RenderPrefs_PreferAGPMemWhenMixing:0x20`

Indicates that the VMR-7 should attempt to use AGP memory when allocating texture surfaces.

### `RenderPrefs_Mask:0x3f`

Bitwise **OR** of all of the above flags.

## Remarks

By default the VMR-7 tries to allocate DirectDraw texture surfaces from Video Memory and falls back to AGP memory if there is no Video Memory remaining to fulfill the allocation. In order for the VMR-7 to use AGP memory, the graphics card must have some basic support for blitting from AGP memory to Video Memory.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)