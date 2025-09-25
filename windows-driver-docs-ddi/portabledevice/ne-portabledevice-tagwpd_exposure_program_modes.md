# tagWPD_EXPOSURE_PROGRAM_MODES enumeration

## Description

The **WPD_EXPOSURE_PROGRAM_MODES** enumeration type describes an exposure mode to use when capturing images with a device.

## Constants

### `WPD_EXPOSURE_PROGRAM_MODE_UNDEFINED`

The exposure mode has not been specified.

### `WPD_EXPOSURE_PROGRAM_MODE_MANUAL`

The application should specify all exposure settings.

### `WPD_EXPOSURE_PROGRAM_MODE_AUTO`

Use a device-defined automatic exposure mode.

### `WPD_EXPOSURE_PROGRAM_MODE_APERTURE_PRIORITY`

An automated exposure mode that indicates that the lens aperture value should remain fixed, but shutter speed should be determined by the device.

### `WPD_EXPOSURE_PROGRAM_MODE_SHUTTER_PRIORITY`

An automated exposure mode that indicates that the shutter speed should remain fixed, but that lens aperture should be determined by the device.

### `WPD_EXPOSURE_PROGRAM_MODE_CREATIVE`

An automated exposure mode that tries to maximize the depth of field.

### `WPD_EXPOSURE_PROGRAM_MODE_ACTION`

An automated exposure mode that tries to maximize the shutter speed.

### `WPD_EXPOSURE_PROGRAM_MODE_PORTRAIT`

An automated exposure mode that specifies a relatively shallow depth of field.

## Remarks

Indicates the exposure program mode of the device. This enumeration is used by the [WPD_STILL_IMAGE_EXPOSURE_PROGRAM_MODE](https://learn.microsoft.com/windows/desktop/wpd_sdk/still-image-properties) property.

## See also

[Structures and Enumeration Types](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff597672(v=vs.85))