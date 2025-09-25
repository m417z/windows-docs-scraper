# HEAACWAVEINFO structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Contains format data for an Advanced Audio Coding (AAC) or High-Efficiency Advanced Audio Coding (HE-AAC) stream.

## Members

### `wfx`

A **WAVEFORMATEX** structure that describes the core AAC stream,
without SBR or PS extensions. See Remarks.

### `wPayloadType`

The payload type.

| Value | Meaning |
| --- | --- |
| 0 | The stream contains raw_data_block elements only. |
| 1 | Audio Data Transport Stream (ADTS). The stream contains an adts_sequence, as defined by MPEG-2. |
| 2 | Audio Data Interchange Format (ADIF). The stream contains an adif_sequence, as defined by MPEG-2. |
| 3 | The stream contains an MPEG-4 audio transport stream with a synchronization layer (LOAS) and a multiplex layer (LATM). |

### `wAudioProfileLevelIndication`

Contains the value of the **audioProfileLevelIndication** field, as defined by ISO/IEC 14496-3 (MPEG-4 Audio). If the value is unknown, set this member to zero or 0xFE ("no audio profile specified").

### `wStructType`

Defines the data that follows this structure. Currently the following value is defined.

| Value | Meaning |
| --- | --- |
| 0 | The data that follows the **HEAACWAVEINFO** structure contains the value of AudioSpecificConfig(), as defined by ISO/IEC 14496-3. <br><br>The size of the data is `wfx.cbSize - sizeof(HEAACWAVEINFO) + sizeof(WAVEFORMATEX)`. If the size is greater than zero, you can access the data by casting the **HEAACWAVEINFO** structure to a [HEAACWAVEFORMAT](https://learn.microsoft.com/windows/desktop/api/mmreg/ns-mmreg-heaacwaveformat) structure. |

All other values for this member are reserved.

### `wReserved1`

Reserved. Set to zero.

### `dwReserved2`

Reserved. Set to zero.

## Remarks

This format structure is used to describe MPEG-2 AAC and MPEG-4 HE-AAC streams, including HE-AAC version 1 and HE-AAC version 2.

The **WAVEFORMATEX** structure defined in the **wfx** member contains the following values.

| Member | Description |
| --- | --- |
| **wFormatTag** | Must be **WAVE_FORMAT_MPEG_HEAAC** (0x1610). |
| **nChannels** | The number of channels in the core AAC stream, including the low frequency (LFE) channel, if present. If parametric stereo (PS) is used, the value might differ from the number of channels in the decoded stream. If unknown, set to zero. |
| **nSamplesPerSec** | The sampling rate of the core AAC stream. The value must be one of the supported sampling rates, from 8000 to 96000 Hz, defined in MPEG-2. If spectral band replication (SBR) is used, the value might differ from the sampling rate of the decoded stream. If unknown, set to zero. |
| **nAvgBytesPerSec** | The average bytes per second, calculated from the average bit rate of the compressed stream. If unknown, set to zero. |
| **nBlockAlign** | Set to 1. |
| **wBitsPerSample** | The desired number of bits per sample in the decoded PCM audio stream. If unknown, set to zero. |
| **cbSize** | Specifies the size, in bytes, of the format data after the **WAVEFORMATEX** structure. |