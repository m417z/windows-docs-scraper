# VMR9_SampleFormat enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VMR9_SampleFormat** enumeration type describes the interlacing of a video stream.

## Constants

### `VMR9_SampleReserved:1`

Reserved; do not use.

### `VMR9_SampleProgressiveFrame:2`

Progressive frame; no interleaving

### `VMR9_SampleFieldInterleavedEvenFirst:3`

Each sample contains two interleaved fields, with the even field first.

### `VMR9_SampleFieldInterleavedOddFirst:4`

Each sample contains two interleaved fields, with the odd field first.

### `VMR9_SampleFieldSingleEven:5`

The sample contains a single field, and each line in the sample corresponds to the even lines in a deinterlaced frame. That is, lines 0, 1, 2,... in the sample correspond to lines 0, 2, 4,... in the deinterlaced frame. The missing lines must be constructed when the frame is deinterlaced.

### `VMR9_SampleFieldSingleOdd:6`

The sample contains a single field, and each line in the sample corresponds to the odd lines in a de-interlaced frame.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[VMR9VideoDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9videodesc)

[VMR9VideoStreamInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9videostreaminfo)