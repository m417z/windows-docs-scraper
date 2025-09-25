## Description

The **MOUNTDEV_NAME** structure holds the name of a device.

## Members

### `NameLength`

Contains the length of the name, in bytes.

### `Name`

Contains a variable-sized array of wide characters that holds the name of the device mount point. The name may be a nonpersistent target name such as "\Device\HarddiskVolume1", a persistent symbolic link name such as a drive letter, "\DosDevices\D:", or a mount point such as "\DosDevices\E:\FilesysD\mnt".

## Remarks

As a best practice, the implementer must not thread-synchronize and must not make blocking and/or Interprocess Communication (IPC) function calls.

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[IOCTL_MOUNTDEV_LINK_CREATED](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountdev/ni-mountdev-ioctl_mountdev_link_created)

[IOCTL_MOUNTDEV_LINK_DELETED](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountdev/ni-mountdev-ioctl_mountdev_link_deleted)

[IOCTL_MOUNTDEV_QUERY_DEVICE_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountmgr/ni-mountmgr-ioctl_mountdev_query_device_name)