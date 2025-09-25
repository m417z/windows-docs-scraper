# VMRPresentationFlags enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The [VMRPRESENTATIONINFO](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-vmrpresentationinfo) structure .

## Constants

### `VMRSample_SyncPoint:0x1`

Indicates that the sample is a sync point.

### `VMRSample_Preroll:0x2`

Indicates that the sample is part of the preroll.

### `VMRSample_Discontinuity:0x4`

Indicates that the sample is a discontinuity.

### `VMRSample_TimeValid:0x8`

Indicates that the time stamp on the sample is valid.

### `VMRSample_SrcDstRectsValid:0x10`

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)