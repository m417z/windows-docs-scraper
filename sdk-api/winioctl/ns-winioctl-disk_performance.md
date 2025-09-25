# DISK_PERFORMANCE structure

## Description

Provides disk performance information. It is used by the
[IOCTL_DISK_PERFORMANCE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_performance) control code.

## Members

### `BytesRead`

The number of bytes read.

### `BytesWritten`

The number of bytes written.

### `ReadTime`

The time it takes to complete a read.

### `WriteTime`

The time it takes to complete a write.

### `IdleTime`

The idle time.

### `ReadCount`

The number of read operations.

### `WriteCount`

The number of write operations.

### `QueueDepth`

The depth of the queue.

### `SplitCount`

The cumulative count of I/Os that are associated I/Os.

An associated I/O is a fragmented I/O, where multiple I/Os to a disk are required to fulfill the original logical I/O request. The most common example of this scenario is a file that is fragmented on a disk. The multiple I/Os are counted as split I/O counts.

### `QueryTime`

The system time stamp when a query for this structure is returned.

Use this member to synchronize between the file system driver and a caller.

### `StorageDeviceNumber`

The unique number for a device that identifies it to the storage manager that is indicated in the **StorageManagerName** member.

### `StorageManagerName`

The name of the storage manager that controls this device.

Examples of storage managers are "PhysDisk," "FTDISK," and "DMIO".

## See also

[IOCTL_DISK_PERFORMANCE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_performance)