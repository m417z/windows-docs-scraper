## Description

The MOUNTMGR_TARGET_NAME structure contains the nonpersistent target device name for a device and is used by mount manager clients with the [IOCTL_MOUNTMGR_KEEP_LINKS_WHEN_OFFLINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_keep_links_when_offline) request to tell the mount manager to keep the symbolic link for a device active even after the device has gone offline.

## Members

### `DeviceNameLength`

Contains the length, in bytes, of the device name stored in **DeviceName**.

### `DeviceName`

Contains the nonpersistent target device name.

## Remarks

Nonpersistent target names must contain the full path of a target object name in the system object tree. For example: "\Device\HarddiskVolume1".

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[IOCTL_MOUNTMGR_KEEP_LINKS_WHEN_OFFLINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_keep_links_when_offline)