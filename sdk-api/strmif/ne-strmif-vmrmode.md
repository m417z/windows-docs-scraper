# VMRMode enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VMRMode** enumeration type is used in calls to the [IVMRFilterConfig::GetRenderingMode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrfilterconfig-getrenderingmode) and [IVMRFilterConfig::SetRenderingMode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrfilterconfig-setrenderingmode) methods to retrieve or specify the [Video Mixing Renderer Filter 7](https://learn.microsoft.com/windows/desktop/DirectShow/video-mixing-renderer-filter-7) (VMR-7) rendering mode.

## Constants

### `VMRMode_Windowed:0x1`

Windowed mode.

### `VMRMode_Windowless:0x2`

Windowless mode.

### `VMRMode_Renderless:0x4`

Renderless mode.

### `VMRMode_Mask:0x7`

Bitwise **OR** of all above flags; this is not a valid value to pass to [SetRenderingMode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrfilterconfig-setrenderingmode).

## Remarks

These modes are mutually exclusive. The **VMRMode_Renderless** flag means that the application is providing its own allocator-presenter, which is responsible for all drawing to the screen. The **VMRMode_Windowed** flag is the default mode of the VMR-7. See [VMR Modes of Operation](https://learn.microsoft.com/windows/desktop/DirectShow/vmr-modes-of-operation) for more information on the rendering modes.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)