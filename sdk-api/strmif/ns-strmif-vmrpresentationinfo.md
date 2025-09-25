# VMRPRESENTATIONINFO structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `VMRPRESENTATIONINFO` structure is used in the [IVMRImagePresenter::PresentImage](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrimagepresenter-presentimage) method (VMR-7 only).

## Members

### `dwFlags`

A bitwise combination of flags from the [VMRPresentationFlags](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-vmrpresentationflags) enumeration, which describe the status of the video sample with respect to its presentation time.

### `lpSurf`

Pointer to the DirectDraw surface that contains the video frame to be presented.

### `rtStart`

The start time for the current frame, in 100-nanosecond units.

### `rtEnd`

The end time for the current frame, in 100-nanosecond units.

### `szAspectRatio`

The aspect ratio of the rectangle.

### `rcSrc`

The source rectangle.

### `rcDst`

The destination rectangle.

### `dwTypeSpecificFlags`

Bitwise combination of flags, as defined for the [AM_SAMPLE2_PROPERTIES](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-am_sample2_properties) structure.

### `dwInterlaceFlags`

Bitwise combination of flags, as defined for the **dwInterlaceFlags** member of the [VIDEOINFOHEADER2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-videoinfoheader2) structure.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[VIDEOINFOHEADER2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-videoinfoheader2)