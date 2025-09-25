# MPEG1WAVEFORMAT structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `MPEG1WAVEFORMAT` structure describes the format of MPEG-1 audio data.

## Members

### `wfx`

[WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure that contains information about the audio format. See Remarks.

### `fwHeadLayer`

Specifies the MPEG audio layer, as defined by the following constants:

| Value | Meaning |
| --- | --- |
| **ACM_MPEG_LAYER1** | Layer 1 |
| **ACM_MPEG_LAYER2** | Layer 2 |
| **ACM_MPEG_LAYER3** | Layer 3 |

Some MPEG streams may contain frames from more than one layer. If so, combine the flags with a bitwise **OR**.

### `dwHeadBitrate`

Specifies the bitrate, in bits per second. This value gives the actual bitrate, not the MPEG frame header code. If the bitrate is variable, or is a non-standard bitrate, set this field to zero.

### `fwHeadMode`

Specifies the stream mode, as defined by the following constants:

| Value | Meaning |
| --- | --- |
| **ACM_MPEG_STEREO** | Stereo |
| **ACM_MPEG_JOINTSTEREO** | Joint stereo |
| **ACM_MPEG_DUALCHANNEL** | Dual channel |
| **ACM_MPEG_SINGLECHANNEL** | Single channel |

Some MPEG streams may contain frames with different modes. If so, combine the flags with a bitwise OR.

### `fwHeadModeExt`

Specifies the mode extension for joint-stereo encoding:

| Value | MPEG Frame Header Code | Layers 1 and 2 | Layer 3 |
| --- | --- | --- | --- |
| 0x01 | '00' | Intensity stereo in bands 4 to 31 | Intensity stereo off; Middle/Side (MS) stereo off |
| 0x02 | '01' | Intensity stereo in bands 8 to 31 | Intensity stereo on; MS stereo off |
| 0x04 | '10' | Intensity stereo in bands 12 to 31 | Intensity stereo off; MS stereo on |
| 0x08 | '11' | Intensity stereo in bands 16 to 31 | Intensity stereo off; MS stereo on |

These values may be combined with a bitwise **OR**. In general, encoders will dynamically switch between extension modes according to the characteristics of the signal. Therefore, for normal joint-stereo encoding, set this field to 0x0F (the bitwise OR of all the flags). However, you can use this field to limit the encoder to a set of allowable encoding types.

This field applies only when **fwHeadMode** includes ACM_MPEG_JOINTSTEREO. For other modes, set this field to zero.

### `wHeadEmphasis`

Specifies the de-emphasis required by the decoder:

| Value | MPEG Frame Header | Code De-emphasis Required |
| --- | --- | --- |
| 1 | '00' | None |
| 2 | '01' | 50/15 ms emphasis |
| 3 | '10' | Reserved |
| 4 | '11' | CCITT J.17 |

### `fwHeadFlags`

Specifies a bitwise combination of zero or more of the following flags:

| Value | Meaning |
| --- | --- |
| **ACM_MPEG_PRIVATEBIT** | Set the private bit. |
| **ACM_MPEG_COPYRIGHT** | Set the copyright bit. |
| **ACM_MPEG_ORIGINALHOME** | Set the original/home bit. |
| **ACM_MPEG_PROTECTIONBIT** | Set the protection bit, and insert a 16-bit error protection code into each frame. |
| **ACM_MPEG_ID_MPEG1** | Set the ID bit to 1, defining the stream as an MPEG-1 audio stream. |

An encoder will use these flags to set the corresponding bits in the MPEG audio frame headers.

### `dwPTSLow`

Specifies the least significant 32 bits of the presentation time stamp (PTS) of the first frame of the audio stream.

### `dwPTSHigh`

Specifies the most significant bit of the PTS. The **dwPTSLow** and **dwPTSHigh** fields can be treated as a single 64-bit value.

## Remarks

For MPEG-1 audio, the [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure defined in the **wfx** member must have the following values.

| WAVEFORMATEX Member | Description |
| --- | --- |
| **wFormatTag** | Must be WAVE_FORMAT_MPEG |
| **nChannels** | 1 for mono, 2 for stereo |
| **nSamplesPerSec** | Specifies the sampling frequency, if the sampling frequency is fixed. If it is variable, set this field to zero. |
| **nAvgBytesPerSec** | Specifies the average data rate. If variable bitrate encoding is used under layer 3, the value might not be a legal MPEG-1 bit rate. |
| **nBlockAlign** | For audio streams with a fixed audio frame length, this field specifies the length of the audio frame. If the frame length is variable, set this field to 1.If the sampling frequency is 32 kHz or 48 kHz and the bit rate is constant, the audio frame size is constant. In that case, calculate **nBlockAlign** as follows:<br><br>* Layer 1: `4 * (int)(12 * bitrate / sampling frequency)`<br>* Layers 2 and 3: `(int)(144 * bitrate / sampling frequency)`<br><br>If the bit rate is variable or the sampling frequency is 44.1 kHz, the audio frame size is not constant and **nBlockAlign** should be 1. |
| **wBitsPerSample** | Not used; set to zero. |
| **cbSize** | Specifies the size of the format data after the [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure, in bytes. For the standard **MPEG1WAVEFORMAT** structure, this value is 22 bytes. |

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[MPEG-1 Media Types](https://learn.microsoft.com/windows/desktop/DirectShow/mpeg-1-media-types)