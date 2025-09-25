# DVD_TIMECODE structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DVD_TIMECODE` structure contains DVD timecode in hours, minutes, seconds, and frames.

## Members

### `Hours1`

Hours.

### `Hours10`

Tens of hours.

### `Minutes1`

Minutes.

### `Minutes10`

Tens of minutes.

### `Seconds1`

Seconds.

### `Seconds10`

Tens of seconds.

### `Frames1`

Frames.

### `Frames10`

Tens of frames.

### `FrameRateCode`

Frames per second dropped and not dropped as indicated by [DVD_FRAMERATE](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_framerate).

## Remarks

DVD timecode is binary coded decimal (BCD) encoded in the format 0xHhMmSsFf, where:

* H is tens of hours
* h is hours
* M is tens of minutes
* m is minutes
* S is tens of seconds
* s is seconds
* F is tens of frames
* f is frames

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)