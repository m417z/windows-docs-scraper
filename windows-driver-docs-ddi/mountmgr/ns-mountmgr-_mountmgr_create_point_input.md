## Description

The **MOUNTMGR_CREATE_POINT_INPUT** structure is used by the mount manager to send a symbolic link name to a client that has requested symbolic link name by means of an [**IOCTL_MOUNTMGR_CREATE_POINT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_create_point) request.

## Members

### `SymbolicLinkNameOffset`

Contains an offset in bytes into the output buffer where the symbolic link name is located.

### `SymbolicLinkNameLength`

Contains the length in bytes of the symbolic link name stored in the output buffer.

### `DeviceNameOffset`

Contains an offset in bytes into the output buffer where the nonpersistent (target) device name is located.

### `DeviceNameLength`

Contains the length in bytes of the nonpersistent (target) device name.

## Remarks

The name given for purposes of identifying the volume can be of any type: a unique volume name, a symbolic link name, or a nonpersistent device name.

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[**IOCTL_MOUNTMGR_CREATE_POINT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_create_point)