# VMRDeinterlacePrefs enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VMRDeinterlacePrefs** enumeration type describes the deinterlacing method that the [Video Mixing Renderer Filter 7](https://learn.microsoft.com/windows/desktop/DirectShow/video-mixing-renderer-filter-7) (VMR-7) uses if the method set by the application cannot be used.

## Constants

### `DeinterlacePref_NextBest:0x1`

Use the next best mode offered by the driver.

### `DeinterlacePref_BOB:0x2`

Use the bob method.

### `DeinterlacePref_Weave:0x4`

Use the weave method (that is, no deinterlacing).

### `DeinterlacePref_Mask:0x7`

Bitwise **OR** of the previous flags. This value is not a valid flag.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IVMRDeinterlaceControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrdeinterlacecontrol)