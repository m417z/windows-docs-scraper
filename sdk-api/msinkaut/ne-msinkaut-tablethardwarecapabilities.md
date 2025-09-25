# TabletHardwareCapabilities enumeration

## Description

Specifies the hardware capabilities of the Tablet PC.

## Constants

### `THWC_Integrated:0x1`

The digitizer is integrated with the display.

### `THWC_CursorMustTouch:0x2`

The cursor must be in physical contact with the device to report position.

### `THWC_HardProximity:0x4`

The device can generate in-air packets when the cursor is in the physical detection range (proximity) of the device.

### `THWC_CursorsHavePhysicalIds:0x8`

The device can uniquely identify the active cursor.

## Remarks

In C++, explicit casting is required when trying to set more than one flag at a time. A compilation error occurs if explicit casting is not used.

The value is 0 if the tablet device cannot provide this information.

This enumeration is a flag.

## See also

[HardwareCapabilities Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinktablet-get_hardwarecapabilities)

[IInkTablet Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet)