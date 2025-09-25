# WAVEFORMATEXTENSIBLE structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WAVEFORMATEXTENSIBLE** structure defines the format of waveform-audio data for formats having more than two channels or higher sample resolutions than allowed by [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)). It can also be used to define any format that can be defined by **WAVEFORMATEX**.

## Members

### `wFormatTag`

### `nChannels`

### `nSamplesPerSec`

### `nAvgBytesPerSec`

### `nBlockAlign`

### `wBitsPerSample`

### `cbSize`

### `wValidBitsPerSample`

### `dwChannelMask`

Bitmask specifying the assignment of channels in the stream to speaker positions.

### `SubFormat`

Subformat of the data, such as KSDATAFORMAT_SUBTYPE_PCM. The subformat information is similar to that provided by the tag in the [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure's **wFormatTag** member.

### `Format`

[WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure that specifies the basic format. The **wFormatTag** member must be WAVE_FORMAT_EXTENSIBLE. The **cbSize** member must be at least 22.

### `Samples`

A union describing the sample format.

### `Samples.wValidBitsPerSample`

Number of bits of precision in the signal. Usually equal to **WAVEFORMATEX.wBitsPerSample**. However, **wBitsPerSample** is the container size and must be a multiple of 8, whereas **wValidBitsPerSample** can be any value not exceeding the container size. For example, if the format uses 20-bit samples, **wBitsPerSample** must be at least 24, but **wValidBitsPerSample** is 20.

### `Samples.wSamplesPerBlock`

Number of samples contained in one compressed block of audio data. This value is used in buffer estimation. This value is used with compressed formats that have a fixed number of samples within each block. This value can be set to 0 if a variable number of samples is contained in each block of compressed audio data. In this case, buffer estimation and position information needs to be obtained in other ways.

### `Samples.wReserved`

Reserved for internal use by operating system. Set to 0.

## Remarks

**WAVEFORMATEXTENSIBLE** can describe any format that can be described by [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)), but provides additional support for more than two channels, for greater precision in the number of bits per sample, and for new compression schemes.

**WAVEFORMATEXTENSIBLE** can safely be cast to **WAVEFORMATEX**, because it simply configures the extra bytes specified by **WAVEFORMATEX.cbSize**.

The **dwChannelMask** member specifies which channels are present in the multichannel stream. The least significant bit corresponds with the front left speaker, the next least significant bit corresponds to the front right speaker, and so on. The bits, in order of significance, are defined as follows.

| Speaker position | Flag bit |
| --- | --- |
| SPEAKER_FRONT_LEFT | 0x1 |
| SPEAKER_FRONT_RIGHT | 0x2 |
| SPEAKER_FRONT_CENTER | 0x4 |
| SPEAKER_LOW_FREQUENCY | 0x8 |
| SPEAKER_BACK_LEFT | 0x10 |
| SPEAKER_BACK_RIGHT | 0x20 |
| SPEAKER_FRONT_LEFT_OF_CENTER | 0x40 |
| SPEAKER_FRONT_RIGHT_OF_CENTER | 0x80 |
| SPEAKER_BACK_CENTER | 0x100 |
| SPEAKER_SIDE_LEFT | 0x200 |
| SPEAKER_SIDE_RIGHT | 0x400 |
| SPEAKER_TOP_CENTER | 0x800 |
| SPEAKER_TOP_FRONT_LEFT | 0x1000 |
| SPEAKER_TOP_FRONT_CENTER | 0x2000 |
| SPEAKER_TOP_FRONT_RIGHT | 0x4000 |
| SPEAKER_TOP_BACK_LEFT | 0x8000 |
| SPEAKER_TOP_BACK_CENTER | 0x10000 |
| SPEAKER_TOP_BACK_RIGHT | 0x20000 |

The channels specified in **dwChannelMask** must be present in the prescribed order (from least significant bit up). For example, if only SPEAKER_FRONT_LEFT and SPEAKER_FRONT_RIGHT are specified, then the samples for the front left speaker must come first in the interleaved stream. The number of bits set in **dwChannelMask** should be the same as the number of channels specified in **WAVEFORMATEX.nChannels**.

For backward compatibility, any wave format that can be specified by a stand-alone [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure can also be defined by a **WAVEFORMATEXTENSIBLE** structure. Thus, every wave-format tag in mmreg.h has a corresponding **SubFormat** GUID. The following table shows some typical wave-format tags and their corresponding **SubFormat** GUIDs. These GUIDs are defined in Ksmedia.h.

| Wave-Format Tag | SubFormat GUID |
| --- | --- |
| WAVE_FORMAT_PCM | KSDATAFORMAT_SUBTYPE_PCM |
| WAVE_FORMAT_IEEE_FLOAT | KSDATAFORMAT_SUBTYPE_IEEE_FLOAT |
| WAVE_FORMAT_DRM | KSDATAFORMAT_SUBTYPE_DRM |
| WAVE_FORMAT_ALAW | KSDATAFORMAT_SUBTYPE_ALAW |
| WAVE_FORMAT_MULAW | KSDATAFORMAT_SUBTYPE_MULAW |
| WAVE_FORMAT_ADPCM | KSDATAFORMAT_SUBTYPE_ADPCM |

Because **WAVEFORMATEXTENSIBLE** is an extended version of [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)), it can describe additional formats that cannot be described by **WAVEFORMATEX** alone. Vendors are free to define their own **SubFormat** GUIDs to identify proprietary formats for which no wave-format tags exist.

The following structures, for particular extended formats, are defined as **WAVEFORMATEXTENSIBLE**.

| Definition | Value of SubFormat |
| --- | --- |
| **WAVEFORMATIEEEFLOATEX** | KSDATAFORMAT_SUBTYPE_IEEE_FLOAT |
| **WAVEFORMATPCMEX** | KSDATAFORMAT_SUBTYPE_PCM |

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Structures](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-structures)