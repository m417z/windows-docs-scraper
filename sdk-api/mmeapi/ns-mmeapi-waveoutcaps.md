# WAVEOUTCAPS structure

## Description

The **WAVEOUTCAPS** structure describes the capabilities of a waveform-audio output device.

## Members

### `wMid`

Manufacturer identifier for the device driver for the device. Manufacturer identifiers are defined in [Manufacturer and Product Identifiers](https://learn.microsoft.com/windows/desktop/Multimedia/manufacturer-and-product-identifiers).

### `wPid`

Product identifier for the device. Product identifiers are defined in [Manufacturer and Product Identifiers](https://learn.microsoft.com/windows/desktop/Multimedia/manufacturer-and-product-identifiers).

### `vDriverVersion`

Version number of the device driver for the device. The high-order byte is the major version number, and the low-order byte is the minor version number.

### `szPname`

Product name in a null-terminated string.

### `dwFormats`

Standard formats that are supported. Can be a combination of the following:

| Format | Description |
| --- | --- |
| WAVE_FORMAT_1M08 | 11.025 kHz, mono, 8-bit |
| WAVE_FORMAT_1M16 | 11.025 kHz, mono, 16-bit |
| WAVE_FORMAT_1S08 | 11.025 kHz, stereo, 8-bit |
| WAVE_FORMAT_1S16 | 11.025 kHz, stereo, 16-bit |
| WAVE_FORMAT_2M08 | 22.05 kHz, mono, 8-bit |
| WAVE_FORMAT_2M16 | 22.05 kHz, mono, 16-bit |
| WAVE_FORMAT_2S08 | 22.05 kHz, stereo, 8-bit |
| WAVE_FORMAT_2S16 | 22.05 kHz, stereo, 16-bit |
| WAVE_FORMAT_4M08 | 44.1 kHz, mono, 8-bit |
| WAVE_FORMAT_4M16 | 44.1 kHz, mono, 16-bit |
| WAVE_FORMAT_4S08 | 44.1 kHz, stereo, 8-bit |
| WAVE_FORMAT_4S16 | 44.1 kHz, stereo, 16-bit |
| WAVE_FORMAT_96M08 | 96 kHz, mono, 8-bit |
| WAVE_FORMAT_96M16 | 96 kHz, mono, 16-bit |
| WAVE_FORMAT_96S08 | 96 kHz, stereo, 8-bit |
| WAVE_FORMAT_96S16 | 96 kHz, stereo, 16-bit |

### `wChannels`

Number specifying whether the device supports mono (1) or stereo (2) output.

### `dwSupport`

Optional functionality supported by the device. The following values are defined:

| Flag | Description |
| --- | --- |
| WAVECAPS_LRVOLUME | Supports separate left and right volume control. |
| WAVECAPS_PITCH | Supports pitch control. |
| WAVECAPS_PLAYBACKRATE | Supports playback rate control. |
| WAVECAPS_SYNC | The driver is synchronous and will block while playing a buffer. |
| WAVECAPS_VOLUME | Supports volume control. |
| WAVECAPS_SAMPLEACCURATE | Returns sample-accurate position information. |

## Remarks

If a device supports volume changes, the WAVECAPS_VOLUME flag will be set for the **dwSupport** member. If a device supports separate volume changes on the left and right channels, both the WAVECAPS_VOLUME and the WAVECAPS_LRVOLUME flags will be set for this member.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Structures](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-structures)