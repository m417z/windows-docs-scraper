## Description

The **MOUNTMGR_MOUNT_POINT** structure is used by mount manager clients in conjunction with an [**IOCTL_MOUNTMGR_QUERY_POINTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_query_points) request to query the mount manager for all of the mount points (symbolic links) associated with a device. The mount manager responds by sending an array of **MOUNTMGR_MOUNT_POINT** structures containing the mount points.

## Members

### `SymbolicLinkNameOffset`

Contains an offset, in bytes, into the output buffer where the symbolic link is located.

### `SymbolicLinkNameLength`

Contains the length, in bytes, of the symbolic link.

### `Reserved1`

### `UniqueIdOffset`

Contains an offset, in bytes, into the output buffer where the unique ID is located.

### `UniqueIdLength`

Contains the length, in bytes, of the unique ID.

### `Reserved2`

### `DeviceNameOffset`

Contains an offset, in bytes, into the output buffer where the nonpersistent device name is located.

### `DeviceNameLength`

Contains the length, in bytes, of the nonpersistent device name.

### `Reserved3`

## Remarks

None of the names returned are NULL terminated, nor do the buffers require terminating NULL characters. The caller of [**IOCTL_MOUNTMGR_QUERY_POINTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_query_points) is not required to provide data in all of the members of the MOUNTMGR_MOUNT_POINT structure, but empty members must have an offset of zero.

On input, offsets are from the beginning of the MOUNTMGR_MOUNT_POINT structure. On output offsets are from the beginning of the buffer. This is usually the same as the beginning of the [**MOUNTMGR_MOUNT_POINTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountmgr_mount_points) container structure (as opposed to the embedded MOUNTMGR_MOUNT_POINT array instance).

The [**IOCTL_MOUNTMGR_QUERY_POINTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_query_points) request is available in Windows 2000 and later operating systems.

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[**IOCTL_MOUNTMGR_QUERY_POINTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_query_points)