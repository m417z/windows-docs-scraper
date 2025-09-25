# _DVD_DISK_KEY_DESCRIPTOR structure

## Description

The DVD_DISK_KEY_DESCRIPTOR structure is used in conjunction with the [IOCTL_DVD_READ_STRUCTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_read_structure) request to retrieve a DVD disc key descriptor.

## Members

### `DiskKeyData`

Pointer to a buffer containing the disc key data obfuscated by the bus key.

## See also

[IOCTL_DVD_READ_STRUCTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_read_structure)