# _CDROM_EXCLUSIVE_LOCK structure

## Description

The CDROM_EXCLUSIVE_LOCK structure is used with the [IOCTL_CDROM_EXCLUSIVE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_exclusive_access) request to lock a CD-ROM device for exclusive access.

## Members

### `Access`

A [CDROM_EXCLUSIVE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_exclusive_access) structure that specifies the type of exclusive access request and the flags that are associated with the request.

### `CallerName`

A **NULL**-terminated string that identifies the application or system component that has a lock on the CD-ROM device. The length of the string must be less than or equal to CDROM_EXCLUSIVE_CALLER_LENGTH bytes, including the **NULL** character at the end of the string. The string must contain alphanumerics (A - Z, a - z, 0 - 9), spaces, periods, commas, colons (:), semi-colons (;), hyphens (-), and underscores (_).

## See also

[CDROM_EXCLUSIVE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_exclusive_access)

[IOCTL_CDROM_EXCLUSIVE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_exclusive_access)