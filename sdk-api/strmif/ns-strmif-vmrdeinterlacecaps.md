# VMRDeinterlaceCaps structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `VMRDeinterlaceCaps` structure describes the capabilities of a deinterlacing mode.

## Members

### `dwSize`

Size of the structure, in bytes.

### `dwNumPreviousOutputFrames`

Number of previously de-interlaced frames that must be fed back to the hardware to deinterlace the next field. (Used by recursive deinterlacing algorithms.)

### `dwNumForwardRefSamples`

Number of future samples needed to deinterlace the current field.

### `dwNumBackwardRefSamples`

Number of past samples needed to deinterlace the current field.

### `DeinterlaceTechnology`

Bitwise combination of flags from the [VMRDeinterlaceTech](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-vmrdeinterlacetech) enumeration type. These flags are used to describe the deinterlacing algorithm.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[IVMRDeinterlaceControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrdeinterlacecontrol)