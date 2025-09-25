# VMR_ASPECT_RATIO_MODE enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VMR_ASPECT_RATIO_MODE** enumeration type describes whether the [Video Mixing Renderer Filter 7](https://learn.microsoft.com/windows/desktop/DirectShow/video-mixing-renderer-filter-7) preserves the aspect ratio of the source video.

## Constants

### `VMR_ARMODE_NONE:0`

Indicates that the VMR will not try to maintain the aspect ratio of the source video.

### `VMR_ARMODE_LETTER_BOX`

Indicates that the VMR will maintain the aspect ratio of the source video by letterboxing within the output rectangle.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IVMRAspectRatioControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmraspectratiocontrol)

[IVMRWindowlessControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrwindowlesscontrol)