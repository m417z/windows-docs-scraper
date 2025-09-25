## Description

The **ACX_INTERLEAVED_AUDIO_FORMAT_INFORMATION** structure specifies how loopback audio is interleaved with the microphone audio for [KSPROPERTY_INTERLEAVEDAUDIO_FORMATINFORMATION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-interleavedaudio-formatinformation).

## Members

### `Size`

The size of all of the data in the **ACX_INTERLEAVED_AUDIO_FORMAT_INFORMATION** structure in bytes.

### `PrimaryChannelCount`

The number of the primary channels. This is typically the number of microphone elements when interleaving the microphone and loopback audio.

### `PrimaryChannelStartPosition`

The array index of the first channel for the primary audio.

### `PrimaryChannelMask`

The primary channel mask, KSAUDIO_SPEAKER_MONO, KSAUDIO_SPEAKER_STEREO, etc.

### `InterleavedChannelCount`

The number of interleaved channels. This is typically the number of channels for the loopback audio associated with the primary channels.

### `InterleavedChannelStartPosition`

The array index of the first channel for the interleaved audio.

### `InterleavedChannelMask`

The interleaved channel mask, KSAUDIO_SPEAKER_MONO, KSAUDIO_SPEAKER_STEREO, etc.

## Remarks

The data described by this structure is intended only for the Hardware Keyword Spotter pin and provides a way to include loopback audio interleaved with the microphone audio. This is done by interleaving the Hardware Keyword Spotter pin audio and loopback audio together into a single PCM audio stream and then communicating, via this property, the channels containing loopback vs. microphone audio.

The WAVEFORMATEXTENSIBLE returned by the driver reports the channel count as a sum of the primary and loopback audio, with a channel mask appropriate for the total channel count. The primary and interleaved audio must have matching bits per sample, sample rate, etc. This structure communicates all information needed to split the two streams of data.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [KSPROPERTY_INTERLEAVEDAUDIO_FORMATINFORMATION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-interleavedaudio-formatinformation)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)