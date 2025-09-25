# WAVEFORMAT structure

## Description

The **WAVEFORMAT** structure describes the format of waveform-audio data. Only format information common to all waveform-audio data formats is included in this structure. This structure has been superseded by the [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure.

## Members

### `wFormatTag`

Format type. The following type is defined:

| Name | Description |
| --- | --- |
| **WAVE_FORMAT_PCM** | Waveform-audio data is PCM. |

### `nChannels`

Number of channels in the waveform-audio data. Mono data uses one channel and stereo data uses two channels.

### `nSamplesPerSec`

Sample rate, in samples per second.

### `nAvgBytesPerSec`

Required average data transfer rate, in bytes per second. For example, 16-bit stereo at 44.1 kHz has an average data rate of 176,400 bytes per second (2 channels — 2 bytes per sample per channel — 44,100 samples per second).

### `nBlockAlign`

Block alignment, in bytes. The block alignment is the minimum atomic unit of data. For PCM data, the block alignment is the number of bytes used by a single sample, including data for both channels if the data is stereo. For example, the block alignment for 16-bit stereo PCM is 4 bytes (2 channels — 2 bytes per sample).

## Remarks

For formats that require additional information, this structure is included as a member in another structure along with the additional information.

## See also

[WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85))

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Structures](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-structures)