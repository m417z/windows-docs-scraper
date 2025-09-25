# DIOBJECTCALIBRATION structure

## Description

The DIOBJECTCALIBRATION structure describes the information contained in the "Calibration" value of the registry key for each axis on a device.

## Members

### `lMin`

Specifies the logical value for the axis minimum position.

### `lCenter`

Specifies the logical value for the axis center position.

### `lMax`

Specifies the logical value for the axis maximum position.

## Remarks

If the "Calibration" value is absent, then the calibration information is taken from the joystick [JOYREGHWVALUES](https://learn.microsoft.com/windows/win32/api/mmddk/ns-mmddk-joyreghwvalues) configuration structure.

Only HID joysticks have a "Calibration" value.