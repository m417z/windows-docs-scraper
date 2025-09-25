# VMR9RenderPrefs enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `VMR9RenderPrefs` enumeration type specifies basic rendering preferences for the VMR-9. It is used with the [IVMRFilterConfig9::GetRenderingPrefs](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrfilterconfig9-getrenderingprefs) and [IVMRFilterConfig9::SetRenderingPrefs](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrfilterconfig9-setrenderingprefs) methods.

## Constants

### `RenderPrefs9_DoNotRenderBorder:0x1`

Indicates that the application paints the color keyed areas.

### `RenderPrefs9_Mask:0x1`

Bitwise **OR** of all flags; not used by applications.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)