# GET_DISK_ATTRIBUTES structure

## Description

Contains the attributes of a disk device. Returned as the output buffer from the
[IOCTL_DISK_GET_DISK_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_disk_attributes) control
code.

## Members

### `Version`

Set to `sizeof(GET_DISK_ATTRIBUTES)`.

### `Reserved1`

Reserved.

### `Attributes`

Contains attributes.

| Value | Meaning |
| --- | --- |
| **DISK_ATTRIBUTE_OFFLINE**<br><br>0x0000000000000001 | The disk is offline. |
| **DISK_ATTRIBUTE_READ_ONLY**<br><br>0x0000000000000002 | The disk is read-only. |

## See also

[Disk Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-structures)

[IOCTL_DISK_GET_DISK_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_disk_attributes)

[SET_DISK_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-set_disk_attributes)