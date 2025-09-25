# PCMWAVEFORMAT structure

## Description

The **PCMWAVEFORMAT** structure describes the data format for PCM waveform-audio data. This structure has been superseded by the [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure.

## Members

### `wf`

A [WAVEFORMAT](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-waveformatex) structure containing general information about the format of the data.

### `wBitsPerSample`

Number of bits per sample.

## See also

[WAVEFORMAT](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-waveformatex)

[WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85))

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Structures](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-structures)