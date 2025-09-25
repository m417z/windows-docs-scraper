## Description

The **ACX_MIC_ARRAY_GEOMETRY** structure specifies the type and the geometry of the microphone array.

## Members

### `Version`

Specifies the version number of the mic array specification. It is currently set to 0x0100, which represents a version number of 1.0.

### `MicArrayType`

Specifies the type of microphone array in use. This member can be any one of the [ACX_MIC_ARRAY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_mic_array_type) enumeration values.

### `VerticalAngleBegin`

Specifies the vertical angle of the start of the working volume of the microphone array.

### `VerticalAngleEnd`

Specifies the vertical angle of the end of the working volume of the microphone array.

### `HorizontalAngleBegin`

Specifies the work volume horizontal angle begin.

### `HorizontalAngleEnd`

Specifies the work volume horizontal angle end.

### `FrequencyBandLo`

Specifies the low end of the frequency range for the microphone array.

### `FrequencyBandHi`

Specifies the high end of the frequency range for the microphone array.

## Remarks

All angle values are expressed in units of 1/10000th of a radian. For example, 3.1416 radians is expressed as 31416 units. Acceptable values range from -31416 to 31416 units.

All coordinate values are expressed in millimeters. Acceptable values range from -32768 to 32767, inclusive.

Frequency values are expressed in Hertz (Hz).

For more information about how to process a microphone array in Windows, see the [Microphone array support in Windows](https://learn.microsoft.com/previous-versions/windows/hardware/design/dn613960(v=vs.85)) white paper.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_MIC_ARRAY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_mic_array_type)
- [Microphone array support in Windows](https://learn.microsoft.com/previous-versions/windows/hardware/design/dn613960(v=vs.85))
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)