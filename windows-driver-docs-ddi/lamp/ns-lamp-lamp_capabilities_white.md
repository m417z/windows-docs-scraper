# LAMP_CAPABILITIES_WHITE structure

## Description

This structure is the I/O parameter type of **IOCTL_LAMP_{GET|SET}_INTENSITY_WHITE**.

## Members

### `IsLightIntensityAdjustable`

If this field evaluates **TRUE**, a client can get/set light intensity by calling [IOCTL_LAMP_GET_INTENSITY_WHITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ni-lamp-ioctl_lamp_get_intensity_white) and [IOCTL_LAMP_SET_INTENSITY_WHITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/lamp/ni-lamp-ioctl_lamp_set_intensity_white).