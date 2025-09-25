# VMR9AspectRatioMode enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `VMR9AspectRatioMode` enumeration type is used with the [IVMRWindowlessControl9::GetAspectRatioMode](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrwindowlesscontrol9-getaspectratiomode) and [IVMRWindowlessControl9::SetAspectRatioMode](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrwindowlesscontrol9-setaspectratiomode) methods to set and retrieve the aspect ratio mode (VMR-9 only).

## Constants

### `VMR9ARMode_None:0`

Indicates that the VMR is not attempting to maintain the aspect ratio of the source video.

### `VMR9ARMode_LetterBox`

Indicates that the VMR will maintain the aspect ratio of the source video by letterboxing within the output rectangle.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)