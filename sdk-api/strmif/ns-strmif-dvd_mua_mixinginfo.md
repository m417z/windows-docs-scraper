# DVD_MUA_MixingInfo structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DVD_MUA_MixingInfo` structure describes the surround sound mixing information for the channels in one audio stream in a specified title.

## Members

### `fMixTo0`

Variable of type BOOL; **TRUE** means the channel is mixed to channel 0.

### `fMixTo1`

Variable of type BOOL; **TRUE** means the channel is mixed to channel 1.

### `fMix0InPhase`

Variable of type BOOL; **TRUE** means the channel is mixed in phase to channel 0.

### `fMix1InPhase`

Variable of type BOOL; **TRUE** means the channel is mixed in phase to channel 1.

### `dwSpeakerPosition`

The speaker for which this channel is intended. See Remarks.

## Remarks

Applications cannot use the information contained in this structure to change the mixing unless they have a way to communicate with a custom audio decoder that has been inserted manually into the filter graph. The default audio decoder handles Linear Pulse Code Modulated (LPCM) audio using the mixing information on the digital video disc (DVD), but applications have no way to instruct the decoder to modify the mixing values. This means that current DVD playback applications should have no need to access the multichannel-related data structures.

The [DVD_MultichannelAudioAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_multichannelaudioattributes) structure contains information about one audio stream in a specified title. An array of up to eight `DVD_MUA_MixingInfo` structures will be populated in this structure, if the following conditions are true.

* DVD_AudioAttributes.AppMode = DVD_AudioMode_Surround
* DVD_AudioAttributes.AudioFormat = DVD_AudioFormat_LPCM
* DVD_AudioAttributes.fHasMultichannelInfo = 1

Possible values for **dwSpeakerPosition** are defined in Ksmedia.h as follows:

| Define | Value |
| --- | --- |
| KSAUDIO_SPEAKER_LEFT | 0x1 |
| KSAUDIO_SPEAKER_RIGHT | 0x2 |
| KSAUDIO_SPEAKER_CENTER | 0x4 |
| KSAUDIO_SPEAKER_SURROUND_LEFT | 0x8 |
| KSAUDIO_SPEAKER_SURROUND_RIGHT | 0x10 |
| KSAUDIO_SPEAKER_SUBWOOFER | 0x20 |
| KSAUDIO_SPEAKER_LEFT_OF_CENTER | 0x40 |
| KSAUDIO_SPEAKER_RIGHT_OF_CENTER | 0x80 |
| KSAUDIO_SPEAKER_SURROUND_MONO | 0x100 |
| KSAUDIO_SPEAKER_SIDE_LEFT | 0x200 |
| KSAUDIO_SPEAKER_SIDE_RIGHT | 0x400 |
| KSAUDIO_SPEAKER_TOP | 0x800 |

## See also

[DVD_AudioAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_audioattributes)

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)