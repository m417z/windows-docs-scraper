# _EXCLUSIVE_ACCESS_REQUEST_TYPE enumeration

## Description

The EXCLUSIVE_ACCESS_REQUEST_TYPE enumeration is used to report the exclusive access state of a CD-ROM device.

## Constants

### `ExclusiveAccessQueryState`

A query for the access state of a CD-ROM device.

### `ExclusiveAccessLockDevice`

A request for the CD-ROM class driver to lock a CD-ROM device for exclusive access by the caller.

### `ExclusiveAccessUnlockDevice`

A request for the CD-ROM class driver to unlock a CD-ROM device that was previously locked for exclusive access.

## Remarks

The EXCLUSIVE_ACCESS_REQUEST_TYPE enumeration is used with the [IOCTL_CDROM_EXCLUSIVE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_exclusive_access) request to query the access state of a CD-ROM device or to lock or unlock the device for exclusive access.

## See also

[IOCTL_CDROM_EXCLUSIVE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_exclusive_access)