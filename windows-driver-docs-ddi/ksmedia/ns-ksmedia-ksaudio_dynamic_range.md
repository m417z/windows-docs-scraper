# KSAUDIO_DYNAMIC_RANGE structure

## Description

The KSAUDIO_DYNAMIC_RANGE structure specifies the dynamic range of an audio stream. This structure is used to get or set the data value for the [KSPROPERTY_AUDIO_DYNAMIC_RANGE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-dynamic-range) property.

## Members

### `QuietCompression`

Specifies the compression level for soft sounds. This value ranges from 0 to 100 percent (represented as 0xFFFFFFFF) of the linear range compression for soft sounds. The higher this value, the higher the volume of soft sounds.

### `LoudCompression`

Specifies the compression level for loud sounds. This value ranges from 0 to 100 percent (represented as 0xFFFFFFFF) of the linear range compression for loud sounds. The higher this value, the lower the volume of loud sounds.

## Remarks

By default, both structure members are set to zero percent, which reproduces the full dynamic range of the audio stream.

## See also

[KSPROPERTY_AUDIO_DYNAMIC_RANGE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-dynamic-range)