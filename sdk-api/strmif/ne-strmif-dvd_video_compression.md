# DVD_VIDEO_COMPRESSION enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Defines the possible DVD video compression types.

## Constants

### `DVD_VideoCompression_Other:0`

Unrecognized compression type.

### `DVD_VideoCompression_MPEG1:1`

MPEG-1 compression type.

### `DVD_VideoCompression_MPEG2:2`

MPEG-2 compression type.

## Remarks

This enumeration is a member of the [DVD_VideoAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_videoattributes) structure, which is filled by a call to the [IDvdInfo2::GetCurrentVideoAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getcurrentvideoattributes) method.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)