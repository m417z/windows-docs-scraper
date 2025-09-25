## Description

The **ACX_MICROPHONE_CONFIG** structure is used to configure a microphone.

## Members

### `Size`

The size of all of the data in the **ACX_MICROPHONE_CONFIG** structure in bytes.

### `Flags`

A combination of values from the [ACX_MICROPHONE_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_microphone_config_flags) enum that describe the microphone.

### `MicrophoneSnrDB`

A 16.16 fixed point decibel (dB) value specifying the microphone's signal-to-noise ratio. Setting this to LONG_MIN_VALUE means that this field is unsupported.

### `MicrophoneSensitivityDB`

A 16.16 fixed point decibel (dB) value specifying the microphone's sensitivity. Setting this to LONG_MIN_VALUE means that this field is unsupported.

### `MicArrayGeometry`

An optional [ACX_MIC_ARRAY_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_mic_array_geometry) structure that describes the geometry of the microphone if it is a microphone array.

### `InterleavedFormat`

An optional pointer to an [ACX_INTERLEAVED_AUDIO_FORMAT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_interleaved_audio_format_information) structure that specifies how loopback audio is interleaved with the microphone audio.

## Remarks

The ACX_MICROPHONE_CONFIG structure should be assigned to the MicrophoneConfig member of the [ACX_PIN_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_pin_config) structure and AcxPinConfigMicrophoneConfigSpecified should be included in the Flags member of the ACX_PIN_CONFIG structure.

To initialize an ACX_MICROPHONE_CONFIG structure, your driver should call [ACX_MICROPHONE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nf-acxpin-acx_microphone_config_init).

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_MICROPHONE_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_microphone_config_flags)
- [ACX_MIC_ARRAY_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_mic_array_geometry)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)