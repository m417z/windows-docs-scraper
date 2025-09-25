# VMR9PresentationFlags enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `VMR9PresentationFlags` enumeration type contains flags that describe the status of a video sample. These flags are used in the [VMR9PresentationInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9presentationinfo) structure.

## Constants

### `VMR9Sample_SyncPoint:0x1`

Indicates that the sample is a sync point.

### `VMR9Sample_Preroll:0x2`

Indicates that the sample is part of the preroll.

### `VMR9Sample_Discontinuity:0x4`

Indicates that the sample is a discontinuity.

### `VMR9Sample_TimeValid:0x8`

Indicates that the time stamp on the sample is valid.

### `VMR9Sample_SrcDstRectsValid:0x10`

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)