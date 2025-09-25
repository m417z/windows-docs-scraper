# VMR9Mode enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VMR9Mode** enumeration type specifies the rendering mode of the [Video Mixing Renderer 9](https://learn.microsoft.com/windows/desktop/DirectShow/video-mixing-renderer-filter-9) (VMR-9) filter.

## Constants

### `VMR9Mode_Windowed:0x1`

Windowed mode.

### `VMR9Mode_Windowless:0x2`

Windowless mode.

### `VMR9Mode_Renderless:0x4`

Renderless mode.

### `VMR9Mode_Mask:0x7`

Bitwise **OR** of all above flags; not used by applications.

## Remarks

For a description of the various VMR-9 modes, see [VMR Modes of Operation](https://learn.microsoft.com/windows/desktop/DirectShow/vmr-modes-of-operation).

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IVMRFilterConfig9::GetRenderingMode](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrfilterconfig9-getrenderingmode)

[IVMRFilterConfig9::SetRenderingMode](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrfilterconfig9-setrenderingmode)