# WAVEFORMATEX structure

## Description

The WAVEFORMATEX structure specifies the data format of a wave audio stream.

## Members

### `wFormatTag`

Specifies the waveform audio format type. For more information, see the following Remarks section.

### `nChannels`

Specifies the number of channels of audio data. For monophonic audio, set this member to 1. For stereo, set this member to 2.

### `nSamplesPerSec`

Specifies the sample frequency at which each channel should be played or recorded. If **wFormatTag** = WAVE_FORMAT_PCM, then common values for **nSamplesPerSec** are 8.0 kHz, 11.025 kHz, 22.05 kHz, and 44.1 kHz. For example, to specify a sample frequency of 11.025 kHz, set **nSamplesPerSec** to 11025. For non-PCM formats, this member should be computed according to the manufacturer's specification of the format tag.

### `nAvgBytesPerSec`

Specifies the required average data transfer rate in bytes per second. This value is useful for estimating buffer size.

### `nBlockAlign`

Specifies the block alignment in bytes. The block alignment is the size of the minimum atomic unit of data for the **wFormatTag** format type. If **wFormatTag** = WAVE_FORMAT_PCM or **wFormatTag** = WAVE_FORMAT_IEEE_FLOAT, set **nBlockAlign** to `(nChannels*wBitsPerSample)/8`, which is the size of a single audio frame. For non-PCM formats, this member should be computed according to the manufacturer's specification for the format tag.

Playback and record software should process a multiple of **nBlockAlign** bytes of data at a time. Data written to and read from a device should always start at the beginning of a block.

### `wBitsPerSample`

Specifies the number of bits per sample for the format type specified by **wFormatTag**. If **wFormatTag** = WAVE_FORMAT_PCM, then **wBitsPerSample** should be set to either 8 or 16. If **wFormatTag** = WAVE_FORMAT_IEEE_FLOAT, **wBitsPerSample** should be set to 32. For non-PCM formats, set the value of this member according to the manufacturer's specification for the format tag. Some compression schemes cannot define a value for **wBitsPerSample**. In this case, set **wBitsPerSample** to zero.

### `cbSize`

Specifies the size, in bytes, of extra format information appended to the end of the WAVEFORMATEX structure. This information can be used by non-PCM formats to store extra attributes for the **wFormatTag**. If no extra information is required by the **wFormatTag**, set this member to zero. For WAVE_FORMAT_PCM formats, clients should ignore this member (its value is implicitly zero). Because all clients might not follow this rule, we recommend that you initialize **cbSize** to zero for WAVE_FORMAT_PCM formats.

## Remarks

The WAVEFORMATEX structure can describe only a subset of the formats that can be described by the [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-waveformatextensible) structure. For example, WAVEFORMATEX can describe mono or (two-channel) stereo pulse-code modulated (PCM) streams with 8-bit or 16-bit integer sample values, or with 32-bit floating-point sample values. In addition, WAVEFORMATEX can describe popular non-PCM formats such as AC-3 and WMA Pro.

WAVEFORMATEX can unambiguously describe mono or stereo PCM formats for which the number of valid bits per sample is the same as the sample container size. To describe a PCM format with more than two channels requires WAVEFORMATEXTENSIBLE, which has a channel mask to specify the speaker configuration (that is, the mapping of channels to physical speaker positions). To describe a PCM format for which the number of valid bits per sample is less than the sample container size (for example, a 20-bit sample stored in a three-byte container) requires WAVEFORMATEXTENSIBLE, which specifies both the number of valid sample bits and the sample container size.

WAVEFORMATEX can describe non-PCM formats for which 16-bit format tags are defined in header file Mmreg.h (for example, WAVE_FORMAT_MPEG). The **wFormatTag** member of WAVEFORMATEX contains the format tag. Specify a non-PCM format for which a format tag is not defined in Mmreg.h by a WAVEFORMATEXTENSIBLE structure, which contains a GUID that identifies the format. If necessary, a hardware vendor can independently generate a GUID value to identify a new format. Registering the GUID with Microsoft is unnecessary.

For more information about the differences between WAVEFORMATEX and WAVEFORMATEXTENSIBLE, see [Extensible Wave-Format Descriptors](https://learn.microsoft.com/windows-hardware/drivers/audio/extensible-wave-format-descriptors).

The **wFormatTag** member is set to one of the wave format tags that are defined in Mmreg.h. Tags for some of the more common nonproprietary formats are listed in the following table.

| wFormatTag Value | Meaning |
| --- | --- |
| WAVE_FORMAT_PCM | PCM (pulse-code modulated) data in integer format. |
| WAVE_FORMAT_IEEE_FLOAT | PCM data in IEEE floating-point format. |
| WAVE_FORMAT_DRM | DRM-encoded format (for digital-audio content protected by Microsoft [Digital Rights Management](https://learn.microsoft.com/windows-hardware/drivers/audio/digital-rights-management)). |
| WAVE_FORMAT_EXTENSIBLE | Extensible WAVEFORMATEX structure (see [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-waveformatextensible)). |
| WAVE_FORMAT_ALAW | A-law-encoded format. |
| WAVE_FORMAT_MULAW | Mu-law-encoded format. |
| WAVE_FORMAT_ADPCM | ADPCM (adaptive differential pulse-code modulated) data. |
| WAVE_FORMAT_MPEG | MPEG-1 data format (stream conforms to ISO 11172-3 Audio specification). |
| WAVE_FORMAT_DOLBY_AC3_SPDIF | AC-3 (aka Dolby Digital) over S/PDIF. |
| WAVE_FORMAT_WMASPDIF | Windows Media Audio (WMA) Pro over S/PDIF. |

See Mmreg.h for the complete list of WAVE_FORMAT_*Xxx* formats.

WAVEFORMATEX is nearly identical to the PCMWAVEFORMAT structure, which is an obsolete structure used to specify PCM formats. The only difference is that WAVEFORMATEX contains a **cbSize** member and PCMWAVEFORMAT does not. By convention, **cbSize** should be ignored when **wFormatTag** = WAVE_FORMAT_PCM (because **cbSize** is implicitly zero). This convention allows driver software to treat the WAVEFORMATEX and PCMWAVEFORMAT structures identically in the case of a PCM format. For more information about PCMWAVEFORMAT, see the Microsoft Windows SDK documentation.

If **wFormatTag** = WAVE_FORMAT_PCM or **wFormatTag** = WAVE_FORMAT_IEEE_FLOAT, set **cbSize** to zero. For all other values of **wFormatTag**, **cbSize** specifies how many bytes of additional format data are appended to the WAVEFORMATEX structure.

If **wFormatTag** = WAVE_FORMAT_EXTENSIBLE, set **cbSize** to `sizeof(WAVEFORMATEXTENSIBLE)-sizeof(WAVEFORMATEX)` plus the size of any format-specific data that is appended to the WAVEFORMATEXTENSIBLE structure.

## See also

[WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-waveformatextensible)