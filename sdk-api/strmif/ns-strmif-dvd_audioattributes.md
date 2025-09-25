# DVD_AudioAttributes structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DVD_AudioAttributes` structure is used in [IDvdInfo2::GetAudioAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getaudioattributes) to receive the various audio attributes of the disc.

## Members

### `AppMode`

Indicates the current audio mode. If the mode returned is DVD_AudioMode_Karaoke, call [IDvdInfo2::GetKaraokeAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getkaraokeattributes) to get more info.

### `AppModeData`

### `AudioFormat`

Describes the format (encoding mode) of the audio stream.

### `Language`

An **LCID** value indicating the language of the audio stream. Is zero if no language is present.

### `LanguageExtension`

A [DVD_AUDIO_LANG_EXT](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_audio_lang_ext) enumeration that will be filled in if any information is available on the disc.

### `fHasMultichannelInfo`

Indicates whether multichannel attributes are present. If **TRUE**, it means there is additional mixing information available, such as for SurroundSound. Call [IDvdInfo2::GetTitleAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-gettitleattributes) to retrieve the multichannel information.

### `dwFrequency`

The frequency in hertz (48k, 96k) of the audio stream.

### `bQuantization`

The resolution of the audio stream (16, 20, 24 bits, or other) Zero indicates the resolution is unknown.

### `bNumberOfChannels`

The number of channels. For example, 5.1 Dolby AC-3 has six channels.

### `dwReserved`

Reserved.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)