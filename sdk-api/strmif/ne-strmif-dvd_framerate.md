# DVD_FRAMERATE enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Indicates whether the DVD is authored to play at 25 or 30 frames per second.

## Constants

### `DVD_FPS_25:1`

Twenty-five frames per second.

### `DVD_FPS_30NonDrop:3`

Exactly 30 frames per second.

## Remarks

You must know the frame rate to interpret the frame count as time.

## See also

[DVD_TIMECODE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_timecode)

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)