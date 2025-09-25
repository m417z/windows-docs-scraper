# VMR9ProcAmpControlFlags enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `VMR9ProcAmpControlFlags` enumeration type specifies image adjustment properties, for use with the Video Mixing Render Filter 9 (VMR-9).

## Constants

### `ProcAmpControl9_Brightness:0x1`

Brightness adjustment.

### `ProcAmpControl9_Contrast:0x2`

Contrast adjustment.

### `ProcAmpControl9_Hue:0x4`

Hue adjustment.

### `ProcAmpControl9_Saturation:0x8`

Saturation adjustment.

### `ProcAmpControl9_Mask:0xf`

Bitwise **OR** of all the previous flags. This value is used internally by the VMR-9, and is not a valid flag.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[VMR9ProcAmpControl Structure](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9procampcontrol)

[VMR9ProcAmpControlRange Structure](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9procampcontrolrange)