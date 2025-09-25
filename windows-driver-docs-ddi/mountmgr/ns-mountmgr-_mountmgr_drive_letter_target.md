## Description

The **MOUNTMGR_DRIVE_LETTER_TARGET** structure is used by a mount manager client with an [**IOCTL_MOUNTMGR_NEXT_DRIVE_LETTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_next_drive_letter) request to furnish a nonpersistent target device name to the mount manager.

## Members

### `DeviceNameLength`

Contains the length, in bytes, of device name.

### `DeviceName`

Contains the nonpersistent target device name.

## Remarks

The mount manager responds to the IOCTL_MOUNTMGR_NEXT_DRIVE_LETTER request by furnishing the client with a drive letter for the target device.

Nonpersistent target names must contain the full path of a target object name in the system object tree. For example: "\Device\HarddiskVolume1".

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[**IOCTL_MOUNTMGR_NEXT_DRIVE_LETTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_next_drive_letter)