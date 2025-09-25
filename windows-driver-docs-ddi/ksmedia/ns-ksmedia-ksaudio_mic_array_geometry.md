# KSAUDIO_MIC_ARRAY_GEOMETRY structure

## Description

The KSAUDIO_MIC_ARRAY_GEOMETRY structure specifies the type and the geometry of the microphone array. The **usNumberOfMicrophones** member indicates the number of microphones in the physical array. The KsMicCoord member is a variable of type [KSAUDIO_MICROPHONE_COORDINATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksaudio_microphone_coordinates) and is an array of structures. The number of entries in this array is given by the value of the **usNumberOfMicrophones** member.

## Members

### `usVersion`

Specifies the version number of the KSAUDIO_MIC_ARRAY_GEOMETRY structure. This member is a BCD value and is currently set to 0x0100, which represents a version number of 1.0.

### `usMicArrayType`

Specifies the type of microphone array in use. This member can be any one of the KSMICARRAY_MICARRAYTYPE enumeration values shown in the following table.

| Value | Microphone array type |
|--|--|
| KSMICARRAY_MICARRAYTYPE_LINEAR | Linear |
| KSMICARRAY_MICARRAYTYPE_PLANAR | Planar |
| KSMICARRAY_MICARRAYTYPE_3D | 3D |

### `wVerticalAngleBegin`

Specifies the vertical angle of the start of the working volume of the microphone array.

### `wVerticalAngleEnd`

Specifies the vertical angle of the end of the working volume of the microphone array.

### `wHorizontalAngleBegin`

Work Volume HorizontalAngle Begin

### `wHorizontalAngleEnd`

Work Volume HorizontalAngle End

### `usFrequencyBandLo`

Specifies the low end of the frequency range for the microphone array.

### `usFrequencyBandHi`

Specifies the high end of the frequency range for the microphone array.

### `usNumberOfMicrophones`

Specifies the number of microphones in the microphone array.

### `KsMicCoord`

Specifies the array of KSAUDIO_MICROPHONE_COORDINATES structures that contains the locations of the microphones in the array.

## Remarks

All angle values are expressed in units of 1/10000th of a radian. For example, 3.1416 radians is expressed as 31416 units. Acceptable values range from -31416 to 31416 units.

All coordinate values are expressed in millimeters. Acceptable values range from -32768 to 32767, inclusive.

Frequency values are expressed in Hertz (Hz).

For more information about how to process a microphone array in Windows, see the [Microphone array support in Windows](https://learn.microsoft.com/previous-versions/windows/hardware/design/dn613960(v=vs.85)) white paper.

## See also

[KSAUDIO_MICROPHONE_COORDINATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksaudio_microphone_coordinates)