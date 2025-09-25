# DVD_DECODER_CAPS structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DVD_DECODER_CAPS` structure indicates the capabilities of a DVD decoder.

## Members

### `dwSize`

Size of this structure.

### `dwAudioCaps`

Bitwise **OR** of flags indicating which audio formats are supported. The following flags are defined.

| Value | Meaning |
| --- | --- |
| **DVD_AUDIO_CAPS_AC3**<br><br>0x00000001 | Dolby Digital (AC3). |
| **DVD_AUDIO_CAPS_MPEG2**<br><br>0x00000002 | MPEG-2 audio. |
| **DVD_AUDIO_CAPS_LPCM**<br><br>0x00000004 | Linear pulse code modulation (LPCM). |
| **DVD_AUDIO_CAPS_DTS**<br><br>0x00000008 | DTS audio. |
| **DVD_AUDIO_CAPS_SDDS**<br><br>0x00000010 | Sony Dynamic Digital Sound (SDDS) audio. |

### `dFwdMaxRateVideo`

Maximum video data rate in forward direction.

### `dFwdMaxRateAudio`

Maximum audio data rate in forward direction.

### `dFwdMaxRateSP`

Maximum subpicture data rate in forward direction.

### `dBwdMaxRateVideo`

Maximum video data rate in reverse direction. (0 if decoder does not support the smooth reverse mechanism.)

### `dBwdMaxRateAudio`

Maximum audio data rate in reverse direction. (0 if decoder does not support the smooth reverse mechanism.)

### `dBwdMaxRateSP`

Maximum subpicture data rate in reverse direction. (0 if decoder does not support the smooth reverse mechanism.)

### `dwRes1`

Reserved for future use.

### `dwRes2`

Reserved for future use.

### `dwRes3`

Reserved for future use.

### `dwRes4`

Reserved for future use.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[IDvdInfo2::GetDecoderCaps](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getdecodercaps)