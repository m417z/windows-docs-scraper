## Description

The **MOUNTMGR_CHANGE_NOTIFY_INFO** structure is used by the mount manager to send epic numbers to its clients and vice versa.

## Members

### `EpicNumber`

Contains the value of a counter used by the mount manager to determine if a client has up-to-date information concerning changes in mount manager's persistent ID database.

## Remarks

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[IOCTL_MOUNTMGR_CHANGE_NOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountmgr_change_notify)