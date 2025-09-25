# LAMP_CAPABILITIES_COLOR structure

## Description

This structure is the I/O parameter type of **IOCTL_LAMP_{GET|SET}_INTENSITY_COLOR**.

## Members

### `IsSupported`

**TRUE** if the device can emit color light; **FALSE** otherwise.

### `IsLightIntensityAdjustable`

If **IsSupported** evaluates to **TRUE** (the driver is capable of emitting color light) and this field evaluates to **TRUE**, a client can get/set light intensity of a color lamp by calling [IOCTL_LAMP_GET_INTENSITY_COLOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ni-lamp-ioctl_lamp_get_intensity_color) and [IOCTL_LAMP_SET_INTENSITY_COLOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ni-lamp-ioctl_lamp_set_intensity_color).