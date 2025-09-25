# DVD_PLAYBACK_LOCATION structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DVD_PLAYBACK_LOCATION` structure indicates DVD playback location.

## Members

### `TitleNum`

Title number for the whole disc; Title Track Number (TTN) not Video Title Set_Title Track Number (VTS_TTN).

### `ChapterNum`

Part-of-title number with title. 0xffffffff if not a simple linear movie.

### `TimeCode`

Timecode. Use [DVD_TIMECODE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_timecode) for current playback time. 0xFFFFFFFF if not a simple linear movie.

## Remarks

**TitleNum** and **ChapterNum** or **TitleNum** and **TimeCode** are sufficient to save the playback location for simple linear movies.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)