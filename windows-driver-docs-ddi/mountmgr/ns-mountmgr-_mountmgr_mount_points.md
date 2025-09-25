## Description

The **MOUNTMGR_MOUNT_POINTS** structure is used by mount manager to send a client the list of mount points associated with a device.

## Members

### `Size`

Contains the size, in bytes, of the output buffer.

### `NumberOfMountPoints`

Contains the number of mount points that the mount manager is returning.

### `MountPoints`

Contains an array of [**MOUNTMGR_MOUNT_POINT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ns-mountmgr-_mountmgr_mount_point) structures that contain information about each mount point associated with the device.

## Remarks

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[**IOCTL_MOUNTMGR_QUERY_POINTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_query_points)