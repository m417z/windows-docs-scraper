# tagWPD_EXPOSURE_METERING_MODES enumeration

## Description

The **WPD_EXPOSURE_METERING_MODES** enumeration type describes the metering mode to use when estimating exposure for still image capture by a device.

## Constants

### `WPD_EXPOSURE_METERING_MODE_UNDEFINED`

The metering mode is undefined.

### `WPD_EXPOSURE_METERING_MODE_AVERAGE`

Use averaged exposure across the full image.

### `WPD_EXPOSURE_METERING_MODE_CENTER_WEIGHTED_AVERAGE`

Use an averaged exposure, with the center of the image given more weight.

### `WPD_EXPOSURE_METERING_MODE_MULTI_SPOT`

Use a multi-spot averaging technique.

### `WPD_EXPOSURE_METERING_MODE_CENTER_SPOT`

Use a center-spot averaging technique.

## Remarks

Indicates the metering mode of the device. This enumeration is used by the [WPD_STILL_IMAGE_EXPOSURE_METERING_MODE](https://learn.microsoft.com/windows/desktop/wpd_sdk/still-image-properties) property.

## See also

[Structures and Enumeration Types](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff597672(v=vs.85))