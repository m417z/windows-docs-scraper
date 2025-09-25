# VMRDeinterlaceTech enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VMRDeinterlaceTech** enumeration type describes the algorithm used for deinterlacing a video stream. The flags are not mutually exclusive; drivers can set a combination of flags.

## Constants

### `DeinterlaceTech_Unknown:0`

The algorithm is unknown or proprietary.

### `DeinterlaceTech_BOBLineReplicate:0x1`

The algorithm creates each missing line by repeating the line above it or below it. This method creates jagged artifacts and is not recommended.

### `DeinterlaceTech_BOBVerticalStretch:0x2`

The algorithm creates the missing lines by vertically stretching each video field by a factor of two. For example, it might average two lines or use a (-1, 9, 9, -1)/16 filter across four lines. Slight vertical adjustments are made to ensure that the resulting image does not "bob" up and down.

### `DeinterlaceTech_MedianFiltering:0x4`

The algorithm uses median filtering to recreate the pixels in the missing lines.

### `DeinterlaceTech_EdgeFiltering:0x10`

The algorithm uses an edge filter to create the missing lines. In this process, spatial directional filters are applied to determine the orientation of edges in the picture content. Missing pixels are created by filtering along (rather than across) the detected edges.

### `DeinterlaceTech_FieldAdaptive:0x20`

The algorithm uses spatial or temporal interpolation, switching between the two on a field-by-field basis, depending on the amount of motion.

### `DeinterlaceTech_PixelAdaptive:0x40`

The algorithm uses spatial or temporal interpolation, switching between the two on a pixel-by-pixel basis, depending on the amount of motion.

### `DeinterlaceTech_MotionVectorSteered:0x80`

The algorithm identifies objects within a sequence of video fields. Before it recreates the missing pixels, it aligns the movement axes of the individual objects in the scene to make them parallel with the time axis.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[VMRDeinterlaceCaps Structure](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-vmrdeinterlacecaps)