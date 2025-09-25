# DVD_KARAOKE_DOWNMIX enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Defines flags used by the [IDvdControl2::SelectKaraokeAudioPresentationMode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-selectkaraokeaudiopresentationmode) method to control which speakers, if any, each auxiliary channel is downmixed to.

## Constants

### `DVD_Mix_0to0:0x1`

Reserved.

### `DVD_Mix_1to0:0x2`

Reserved.

### `DVD_Mix_2to0:0x4`

Downmix channel 2 to the left speaker.

### `DVD_Mix_3to0:0x8`

Downmix channel 3 to the left speaker.

### `DVD_Mix_4to0:0x10`

Downmix channel 4 to the left speaker.

### `DVD_Mix_Lto0:0x20`

Reserved.

### `DVD_Mix_Rto0:0x40`

Reserved.

### `DVD_Mix_0to1:0x100`

Reserved.

### `DVD_Mix_1to1:0x200`

Reserved.

### `DVD_Mix_2to1:0x400`

Downmix channel 2 to the right speaker.

### `DVD_Mix_3to1:0x800`

Downmix channel 3 to the right speaker.

### `DVD_Mix_4to1:0x1000`

Downmix channel 4 to the right speaker.

### `DVD_Mix_Lto1:0x2000`

Reserved.

### `DVD_Mix_Rto1:0x4000`

Reserved.

## Remarks

Audio channels are zero-based, so channels 2 through 4 are the three auxiliary karaoke channels. Use bitwise **OR** operations to set the appropriate bit to send a channel to the left speaker (0), right speaker (1), both speakers, or to no speakers by turning both bits off. These bits are all off by default whenever the [DVD Navigator Filter](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) filter enters karaoke mode.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IDvdControl2::SelectKaraokeAudioPresentationMode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-selectkaraokeaudiopresentationmode)