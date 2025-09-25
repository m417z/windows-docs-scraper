## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies DVD warning conditions.

## Constants

### `DVD_WARNING_InvalidDVD1_0Disc:1`

DVD-Video disc is authored incorrectly. Playback can continue, but unexpected behavior might occur.

### `DVD_WARNING_FormatNotSupported:2`

A decoder would not support the current format. Playback of a stream (audio, video or subpicture) might not function. *lParam2* of the [EC_DVD_WARNING](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-warning) event notification code contains the stream type (see [AM_DVD_STREAM_FLAGS](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-am_dvd_stream_flags)).

### `DVD_WARNING_IllegalNavCommand:3`

The internal DVD navigation command processor attempted to process an illegal command.

### `DVD_WARNING_Open:4`

File Open failed.

### `DVD_WARNING_Seek:5`

File Seek failed.

### `DVD_WARNING_Read`

File Read failed.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[EC_DVD_WARNING](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-warning)