# KSDATARANGE_AUDIO structure

## Description

The KSDATARANGE_AUDIO structure specifies a range of audio formats.

## Members

### `DataRange`

Specifies the MajorFormat and SubFormat GUIDs as well as the Specifier GUID for the audio data. This member is an initialized [KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85)) structure.

### `MaximumChannels`

Specifies the maximum number of channels supported. A value of (ULONG)-1 for this member means that the number of channels has no explicit limit, although the number of channels might be practically limited by the availability of resources such as memory or processing power.

### `MinimumBitsPerSample`

Specifies the minimum bits per sample supported.

### `MaximumBitsPerSample`

Specifies the maximum bits per sample supported.

### `MinimumSampleFrequency`

Specifies the minimum frequency allowed.

### `MaximumSampleFrequency`

Specifies the maximum frequency allowed.

## Remarks

For examples of data ranges that use the KSDATARANGE_AUDIO structure, see [PCM Stream Data Range](https://learn.microsoft.com/windows-hardware/drivers/audio/pcm-stream-data-range), [DirectSound Stream Data Range](https://learn.microsoft.com/windows-hardware/drivers/audio/directsound-stream-data-range), and [Specifying AC-3 Data Ranges](https://learn.microsoft.com/windows-hardware/drivers/audio/specifying-ac-3-data-ranges).

For information about data ranges and intersection handling, see [Data-Intersection Handlers](https://learn.microsoft.com/windows-hardware/drivers/audio/data-intersection-handlers).

## See also

[KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85))