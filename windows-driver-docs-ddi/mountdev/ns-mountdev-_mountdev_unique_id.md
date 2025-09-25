## Description

The **MOUNTDEV_UNIQUE_ID** structure contains a unique volume ID that a mount manager client provides to the mount manager in response to an [IOCTL_MOUNTDEV_QUERY_UNIQUE_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountdev/ni-mountdev-ioctl_mountdev_query_unique_id) request.

## Members

### `UniqueIdLength`

The length of the unique volume ID, in bytes.

### `UniqueId`

Array of bytes that specify the unique volume ID.

## Remarks

For a discussion of unique volume IDs and how the mount manager uses them, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

As a best practice, the implementer must not thread synchronize and must not make blocking and/or Interprocess Communication (IPC) function calls.

## See also

[IOCTL_MOUNTDEV_QUERY_UNIQUE_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountdev/ni-mountdev-ioctl_mountdev_query_unique_id)