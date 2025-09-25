## Description

The **ACX_MICROPHONE_COORDINATES** structure specifies the 3D location of the microphone in X, Y, and Z coordinates.

## Members

### `Type`

A value from the [ACX_MICROPHONE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_microphone_type) enum that identifies the pickup pattern of the microphone.

### `XCoord`

The X coordinate of the microphone, in millimeters. Acceptable values range from -32768 to 32767, inclusive.

### `YCoord`

The Y coordinate of the microphone, in millimeters. Acceptable values range from -32768 to 32767, inclusive.

### `ZCoord`

The Z coordinate of the microphone, in millimeters. Acceptable values range from -32768 to 32767, inclusive.

### `VerticalAngle`

Specifies a value between -15708 and +15708. When divided by 10,000, it gives a radian angle measurement.

### `HorizontalAngle`

Specifies a value between -31416 and +31416. When divided by 10,000, it gives a radian angle measurement.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_MICROPHONE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_microphone_type)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)