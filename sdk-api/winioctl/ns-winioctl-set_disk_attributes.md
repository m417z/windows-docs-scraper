# SET_DISK_ATTRIBUTES structure

## Description

Specifies the attributes to be set on a disk device. Passed as the input buffer to the
[IOCTL_DISK_SET_DISK_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_set_disk_attributes) control
code.

## Members

### `Version`

Set to `sizeof(GET_DISK_ATTRIBUTES)`.

### `Persist`

If **TRUE**, these settings are persisted across reboots.

### `Reserved1`

 Reserved. Must be set to **FALSE** (0).

### `Attributes`

 Specifies attributes.

| Value | Meaning |
| --- | --- |
| **DISK_ATTRIBUTE_OFFLINE**<br><br>0x0000000000000001 | The disk is offline. |
| **DISK_ATTRIBUTE_READ_ONLY**<br><br>0x0000000000000002 | The disk is read-only. |

### `AttributesMask`

Indicates which attributes are being changed.

| Value | Meaning |
| --- | --- |
| **DISK_ATTRIBUTE_OFFLINE**<br><br>0x0000000000000001 | The offline attribute is being changed. |
| **DISK_ATTRIBUTE_READ_ONLY**<br><br>0x0000000000000002 | The read-only attribute is being changed. |

### `Reserved2`

Reserved. Must be set to 0.

## See also

[Disk Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-structures)

[GET_DISK_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-get_disk_attributes)

[IOCTL_DISK_SET_DISK_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_set_disk_attributes)