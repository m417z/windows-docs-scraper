## Description

The MOUNTMGR_VOLUME_MOUNT_POINT structure is used in conjunction with the [IOCTL_MOUNTMGR_VOLUME_MOUNT_POINT_CREATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_volume_mount_point_created) request to inform the mount manager that a volume mount point has been created.

## Members

### `SourceVolumeNameOffset`

Contains an offset, in bytes, into the output buffer where the name of the mount point is located.

### `SourceVolumeNameLength`

Contains the length, in bytes, of the mount point name.

### `TargetVolumeNameOffset`

Contains an offset, in bytes, into the output buffer where the unique (persistent) volume name of the target device is located.

### `TargetVolumeNameLength`

Contains the length, in bytes, of the target name.

## Remarks

Mount point names must contain the full path of a mount point object name in the system object tree. For example: "\DosDevices\E:\FilesysD\mnt".

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[IOCTL_MOUNTMGR_VOLUME_MOUNT_POINT_CREATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_volume_mount_point_created)