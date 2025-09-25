# DVD_HMSF_TIMECODE structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DVD_HMSF_TIMECODE` structure gives the hours, minutes, seconds, and frames in a DVD timecode.

## Members

### `bHours`

Hours.

### `bMinutes`

Minutes.

### `bSeconds`

Seconds.

### `bFrames`

Frames.

## Remarks

A `DVD_HMSF_TIMECODE` structure is used in various [IDvdControl2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2) and [IDvdInfo2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2) methods. A `DVD_HMSF_TIMECODE` structure can be cast to or from a **ULONG** value. This means that if you need to use the old BCD time format for backward compatibility, you can do so in place of a `DVD_HMSF_TIMECODE` structure.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)