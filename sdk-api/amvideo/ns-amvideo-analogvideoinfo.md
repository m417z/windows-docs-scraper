# ANALOGVIDEOINFO structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **ANALOGVIDEOINFO** structure maintains information about the format of the analog video signal.

## Members

### `rcSource`

Source video rectangle.

### `rcTarget`

Destination target rectangle.

### `dwActiveWidth`

Source video width.

### `dwActiveHeight`

Source video height (483 for NTSC, 575 for PAL/SECAM).

### `AvgTimePerFrame`

Average time per frame in 100-nanosecond units.

## Remarks

Filters using this format usually pass the video signal using a hardware-based connection rather than using memory-based transports.

An example of a definition of an analog video media type connection would be a connection of NTSC video using "M" color encoding. This would use a major media type of MEDIATYPE_AnalogVideo, a subtype of MEDIASUBTYPE_AnalogVideo_NTSC_M, and a format type of FORMAT_AnalogVideo.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)