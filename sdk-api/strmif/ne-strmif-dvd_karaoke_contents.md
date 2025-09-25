# DVD_KARAOKE_CONTENTS enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies flags that, when used in a bitwise **OR** operation, describe the contents of each channel of an audio stream in a karaoke title.

## Constants

### `DVD_Karaoke_GuideVocal1:0x1`

The channel contains guide vocal 1.

### `DVD_Karaoke_GuideVocal2:0x2`

The channel contains guide vocal 2.

### `DVD_Karaoke_GuideMelody1:0x4`

The channel contains guide melody 1.

### `DVD_Karaoke_GuideMelody2:0x8`

The channel contains guide melody 2.

### `DVD_Karaoke_GuideMelodyA:0x10`

The channel contains guide melody A.

### `DVD_Karaoke_GuideMelodyB:0x20`

The channel contains guide melody B.

### `DVD_Karaoke_SoundEffectA:0x40`

The channel contains sound effect A.

### `DVD_Karaoke_SoundEffectB:0x80`

The channel contains sound effect B.

## Remarks

This enumeration is used in the [DVD_KaraokeAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_karaokeattributes) structure.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)