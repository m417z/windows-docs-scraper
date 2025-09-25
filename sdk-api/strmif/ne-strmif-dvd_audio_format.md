# DVD_AUDIO_FORMAT enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Indicates the audio format of a DVD.

## Constants

### `DVD_AudioFormat_AC3:0`

Audio format is Dolby AC-3.

### `DVD_AudioFormat_MPEG1:1`

Audio format is MPEG-1.

### `DVD_AudioFormat_MPEG1_DRC:2`

Audio format is MPEG-1 with dynamic range control.

### `DVD_AudioFormat_MPEG2:3`

Audio format is MPEG-2.

### `DVD_AudioFormat_MPEG2_DRC:4`

Audio format is MPEG-2 with dynamic range control.

### `DVD_AudioFormat_LPCM:5`

Audio format is Linear Pulse Code Modulated (LPCM).

### `DVD_AudioFormat_DTS:6`

Audio format is Digital Theater Systems (DTS).

### `DVD_AudioFormat_SDDS:7`

Audio format is Sony Dynamic Digital Sound (SDDS).

### `DVD_AudioFormat_Other:8`

Audio format is unrecognized.

## Remarks

This enumeration is a member of the [DVD_AudioAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_audioattributes) structure.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)