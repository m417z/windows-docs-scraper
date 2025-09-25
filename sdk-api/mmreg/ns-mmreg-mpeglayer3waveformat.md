# MPEGLAYER3WAVEFORMAT structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **MPEGLAYER3WAVEFORMAT** structure describes an MPEG Audio Layer-3 (MP3) audio format.

## Members

### `wfx`

[WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure that specifies the basic audio format. The **wFormatTag** member must be **WAVE_FORMAT_MPEGLAYER3**. The **cbSize** member must be at least 12. (For **cbSize**, you can use the constant **MPEGLAYER3_WFX_EXTRA_BYTES**, defined in the Mmreg.h.)

### `wID`

Set this structure member to **MPEGLAYER3_ID_MPEG**.

### `fdwFlags`

Indicates whether padding is used to adjust the average bitrate to the sampling rate. Use one of the following values:

| Value | Meaning |
| --- | --- |
| **MPEGLAYER3_FLAG_PADDING_ISO**<br><br>0x00000000 | Insert padding as needed to achieve the stated average bitrate. |
| **MPEGLAYER3_FLAG_PADDING_ON**<br><br>0x00000001 | Always insert padding. The average bit rate may be higher than stated. |
| **MPEGLAYER3_FLAG_PADDING_OFF**<br><br>0x00000002 | Never insert padding. The average bit rate may be lower than stated. |

### `nBlockSize`

Block size in bytes. This value equals the frame length in bytes x **nFramesPerBlock**. For MP3 audio, the frame length is calculated as follows: 144 x (bitrate / sample rate) + padding.

### `nFramesPerBlock`

Number of audio frames per block.

### `nCodecDelay`

Encoder delay in samples. If you do not know this value, set this structure member to zero.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)