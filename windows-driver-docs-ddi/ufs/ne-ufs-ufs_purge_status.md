# UFS_PURGE_STATUS enumeration

## Description

Specifies the current status of a purge operation.

## Constants

### `UFS_PurgeStatusIdle`

The status of the purge operation has already been read but was not returned.

### `UFS_PurgeStatusInProgress`

The purge operation is currently in progress.

### `UFS_PurgeStatusInterrupted`

The current purge operation was interrupted.

### `UFS_PurgeStatusSuccess`

The current purge operation was successful.

### `UFS_PurgeStatusQueueNotEmpty`

The current purge operation failed due to the logical queue being not empty.

### `UFS_PurgeStatusFailure`

The current purge operation failed.

## Remarks

When the **UFS_PURGE_STATUS** is equal to
the values 2, 3, 4, or 5, the
**UFS_PURGE_STATUS** is automatically
cleared to **UFS_PurgeStatusIdle** the first time
that it is read.

## See also

[UFS_ATTRIBUTES_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufs/ne-ufs-ufs_attributes_descriptor)