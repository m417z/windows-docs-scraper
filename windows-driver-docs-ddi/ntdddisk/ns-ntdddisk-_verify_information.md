# _VERIFY_INFORMATION structure

## Description

The VERIFY_INFORMATION structure provides information used to verify the existence of a disk extent.

## Members

### `StartingOffset`

Specifies the starting offset, in bytes, of the disk extent.

### `Length`

Indicates the length, in bytes, of the disk extent.

## Remarks

VERIFY_INFORMATION is the output buffer for the [IOCTL_DISK_VERIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_verify) control code.

## See also

[IOCTL_DISK_VERIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_verify)