# DVD_KARAOKE_ASSIGNMENT enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Defines the speaker configuration for an audio stream.

## Constants

### `DVD_Assignment_reserved0:0`

Reserved.

### `DVD_Assignment_reserved1:1`

Reserved.

### `DVD_Assignment_LR:2`

The stream is assigned to the left and right speakers.

### `DVD_Assignment_LRM:3`

The stream is assigned to the left, right, and middle speakers.

### `DVD_Assignment_LR1:4`

The stream is assigned to the left, right, and audio1 speakers.

### `DVD_Assignment_LRM1:5`

The stream is assigned to the left, right, middle, and audio1 speakers.

### `DVD_Assignment_LR12:6`

The stream is assigned to the left, right, and audio2 speakers.

### `DVD_Assignment_LRM12:7`

The stream is assigned to the left, right, middle, and audio2 speakers.

## Remarks

All channels within a stream will use the same speaker configuration, although the channels can be sent to different speakers within this configuration.

## See also

[DVD_KaraokeAttributes Structure](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_karaokeattributes)

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)