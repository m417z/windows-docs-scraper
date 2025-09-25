# _CDROM_EXCLUSIVE_LOCK_STATE structure

## Description

The CDROM_EXCLUSIVE_LOCK_STATE structure is used by the CD-ROM class driver to report the exclusive access state of a CD-ROM device.

## Members

### `LockState`

A Boolean value that indicates whether the CD-ROM device is locked for exclusive access. If **TRUE**, the device is locked. If **FALSE**, the device is not locked.

### `CallerName`

A **NULL**-terminated string that identifies the application or system component that has a lock on the CD-ROM device. The length of the string must be less than or equal to CDROM_EXCLUSIVE_CALLER_LENGTH bytes, including the **NULL** character at the end of the string. The string must contain alphanumerics (A - Z, a - z, 0 - 9), spaces, periods, commas, colons (:), semi-colons (;), hyphens (-), and underscores (_).

## Remarks

The CD-ROM class driver reports the exclusive access state of a CD-ROM device in response to the [IOCTL_CDROM_EXCLUSIVE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_exclusive_access) request.

## See also

[IOCTL_CDROM_EXCLUSIVE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_exclusive_access)