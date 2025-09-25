# DVD_AUDIO_APPMODE enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Indicates the current audio mode as retrieved in a call to [IDvdInfo2::GetAudioAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getaudioattributes).

## Constants

### `DVD_AudioMode_None:0`

No special audio mode. The [DVD Navigator Filter](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) will send the audio to the decoder with no special processing.

### `DVD_AudioMode_Karaoke:1`

The current audio mode is karaoke content.

### `DVD_AudioMode_Surround:2`

The current audio mode is surround sound.

### `DVD_AudioMode_Other:3`

Unrecognized audio mode.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IDvdInfo2::GetAudioAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getaudioattributes)