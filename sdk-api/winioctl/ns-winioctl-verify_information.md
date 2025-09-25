# VERIFY_INFORMATION structure

## Description

Contains information used to verify a disk extent. It is the output buffer for the
[IOCTL_DISK_VERIFY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_verify) control code.

## Members

### `StartingOffset`

The starting offset of the disk extent.

### `Length`

The length of the disk extent, in bytes.

## See also

[IOCTL_DISK_VERIFY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_verify)