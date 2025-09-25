# WAVEINCAPS structure

## Description

The **WAVEINCAPS** structure describes the capabilities of a waveform-audio input device.

## Members

### `wMid`

Manufacturer identifier for the device driver for the waveform-audio input device. Manufacturer identifiers are defined in [Manufacturer and Product Identifiers](https://learn.microsoft.com/windows/desktop/Multimedia/manufacturer-and-product-identifiers).

### `wPid`

Product identifier for the waveform-audio input device. Product identifiers are defined in [Manufacturer and Product Identifiers](https://learn.microsoft.com/windows/desktop/Multimedia/manufacturer-and-product-identifiers).

### `vDriverVersion`

Version number of the device driver for the waveform-audio input device. The high-order byte is the major version number, and the low-order byte is the minor version number.

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

Number specifying whether the device supports mono (1) or stereo (2) input.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Structures](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-structures)