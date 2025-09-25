# AM_DVD_STREAM_FLAGS enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Describes a DVD stream type (video, audio, or subpicture).

## Constants

### `AM_DVD_STREAM_VIDEO:0x1`

DVD video stream.

### `AM_DVD_STREAM_AUDIO:0x2`

DVD audio stream.

### `AM_DVD_STREAM_SUBPIC:0x4`

DVD subpicture stream.

## See also

[AM_DVD_RENDERSTATUS Structure](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_dvd_renderstatus)

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)