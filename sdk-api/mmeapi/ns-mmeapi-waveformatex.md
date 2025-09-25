# WAVEFORMATEX structure

## Description

The **WAVEFORMATEX** structure defines the format of waveform-audio data. Only format information common to all waveform-audio data formats is included in this structure. For formats that require additional information, this structure is included as the first member in another structure, along with the additional information.

Formats that support more than two channels or sample sizes of more than 16 bits can be described in a [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/windows/desktop/api/mmreg/ns-mmreg-waveformatextensible) structure, which includes the [WAVEFORMAT](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-waveformatex) structure.

## Members

### `wFormatTag`

Waveform-audio format type. Format tags are registered with Microsoft Corporation for many compression algorithms. A complete list of format tags can be found in the Mmreg.h header file. For one- or two-channel PCM data, this value should be WAVE_FORMAT_PCM. When this structure is included in a [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/windows/desktop/api/mmreg/ns-mmreg-waveformatextensible) structure, this value must be WAVE_FORMAT_EXTENSIBLE.

### `nChannels`

Number of channels in the waveform-audio data. Monaural data uses one channel and stereo data uses two channels.

### `nSamplesPerSec`

Sample rate, in samples per second (hertz). If **wFormatTag** is WAVE_FORMAT_PCM, then common values for **nSamplesPerSec** are 8.0 kHz, 11.025 kHz, 22.05 kHz, and 44.1 kHz. For non-PCM formats, this member must be computed according to the manufacturer's specification of the format tag.

### `nAvgBytesPerSec`

Required average data-transfer rate, in bytes per second, for the format tag. If **wFormatTag** is WAVE_FORMAT_PCM, **nAvgBytesPerSec** should be equal to the product of **nSamplesPerSec** and **nBlockAlign**. For non-PCM formats, this member must be computed according to the manufacturer's specification of the format tag.

### `nBlockAlign`

Block alignment, in bytes. The block alignment is the minimum atomic unit of data for the **wFormatTag** format type. If **wFormatTag** is WAVE_FORMAT_PCM or WAVE_FORMAT_EXTENSIBLE, **nBlockAlign** must be equal to the product of **nChannels** and **wBitsPerSample** divided by 8 (bits per byte). For non-PCM formats, this member must be computed according to the manufacturer's specification of the format tag.

Software must process a multiple of **nBlockAlign** bytes of data at a time. Data written to and read from a device must always start at the beginning of a block. For example, it is illegal to start playback of PCM data in the middle of a sample (that is, on a non-block-aligned boundary).

### `wBitsPerSample`

Bits per sample for the **wFormatTag** format type. If **wFormatTag** is WAVE_FORMAT_PCM, then **wBitsPerSample** should be equal to 8 or 16. For non-PCM formats, this member must be set according to the manufacturer's specification of the format tag. If **wFormatTag** is WAVE_FORMAT_EXTENSIBLE, this value can be any integer multiple of 8 and represents the container size, not necessarily the sample size; for example, a 20-bit sample size is in a 24-bit container. Some compression schemes cannot define a value for **wBitsPerSample**, so this member can be 0.

### `cbSize`

Size, in bytes, of extra format information appended to the end of the **WAVEFORMATEX** structure. This information can be used by non-PCM formats to store extra attributes for the **wFormatTag**. If no extra information is required by the **wFormatTag**, this member must be set to 0. For WAVE_FORMAT_PCM formats (and only WAVE_FORMAT_PCM formats), this member is ignored. When this structure is included in a [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/windows/desktop/api/mmreg/ns-mmreg-waveformatextensible) structure, this value must be at least 22.

## Remarks

An example of a format that uses extra information is the Microsoft Adaptive Delta Pulse Code Modulation (MS-ADPCM) format. The **wFormatTag** for MS-ADPCM is WAVE_FORMAT_ADPCM. The **cbSize** member will typically be set to 32. The extra information stored for WAVE_FORMAT_ADPCM is coefficient pairs required for encoding and decoding the waveform-audio data.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Structures](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-structures)