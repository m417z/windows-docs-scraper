# SFFDISK_DPCMD enumeration

## Description

The SFFDISK_DPCMD enumeration lists the operations performed by an [IOCTL_SFFDISK_DEVICE_PASSWORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/sffdisk/ni-sffdisk-ioctl_sffdisk_device_password) request.

## Constants

### `SFFDISK_DP_IS_SUPPORTED`

The operation requests verification from the card that it supports command class 7.

### `SFFDISK_DP_SET_PASSWORD`

The operation sets the password.

### `SFFDISK_DP_LOCK_DEVICE`

The operation locks the device.

### `SFFDISK_DP_UNLOCK_DEVICE`

The operation unlocks the device.

### `SFFDISK_DP_RESET_DEVICE_ALL_DATA`

The operation resets the device.

## See also

[SFFDISK_DEVICE_PASSWORD_DATA](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff538136(v=vs.85))