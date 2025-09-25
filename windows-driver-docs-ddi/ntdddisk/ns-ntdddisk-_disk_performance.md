# DISK_PERFORMANCE structure

## Description

The DISK_PERFORMANCE structure is used in conjunction with the [**IOCTL_DISK_PERFORMANCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_performance) request to collect summary disk statistics for purposes of measuring disk performance.

## Members

### `BytesRead`

Contains a cumulative count of bytes read from the disk since the performance counters were enabled.

### `BytesWritten`

Contains a cumulative count of bytes written to the disk since the performance counters were enabled.

### `ReadTime`

Contains a cumulative time, expressed in increments of 100 nanoseconds, spent on disk reads since the performance counters were enabled.

### `WriteTime`

Contains a cumulative time, expressed in increments of 100 nanoseconds, spent on disk reads since the performance counters were enabled.

### `IdleTime`

Contains a cumulative time, expressed in increments of 100 nanoseconds, since the performance counters were enabled in which there was no disk activity.

### `ReadCount`

Contains the number of disk accesses for reads since the performance counters were enabled.

### `WriteCount`

Contains the number of disk accesses for writes since the performance counters were enabled.

### `QueueDepth`

Contains a snapshot of the number of queued disk I/O requests at the time that the query for performance statistics was performed.

### `SplitCount`

Contains the number of disk accesses by means of an associated IRP since the performance counters were enabled.

### `QueryTime`

Contains a timestamp indicating the system time at the moment that the query took place. System time is a count of 100-nanosecond intervals since January 1, 1601. System time is typically updated approximately every ten milliseconds. For more information about system time, see[**KeQuerySystemTime**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerysystemtime).

### `StorageDeviceNumber`

Contains a unique number assigned to every disk or volume across a particular storage type. The storage types are *disk.sys*, *ftdisk.sys*, and *dmio.sys*.

### `StorageManagerName`

Contains an 8-character string that indicates which device driver provided the performance statistics.

* In Windows 2000, this can be either "LogiDisk" for the driver *logidisk.sys* or "PhysDisk" for the driver *physdisk.sys*. These drivers collect performance statistics for devices and physical disks respectively.

* In Windows XP and later operating systems, this can be any of the following three strings: "FTDISK" for the driver *ftdisk.sys*, "DMIO" for the driver *dmio.sys*, or "PARTMGR" for the driver *partmgr.sys*. These three drivers collect performance statistics for basic disk volumes, dynamic disk volumes, and physical disks respectively. Note that these strings are 8-character case-sensitive strings with blank fill. For example, in the case of the string "FTDISK", the **StorageManagerName** character array should contain two trailing blanks ("FTDISK  "), and in the case of the string "DMIO", the array should contain four trailing blanks ("DMIO    ").

## Remarks

Counting halts whenever the performance counters are disabled, but the counters are not reset, so the cumulative values assigned to the structure members might potentially reflect disk activity across several enablings and disablings of the counters.

## See also

[**IOCTL_DISK_PERFORMANCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_performance)

[**IOCTL_DISK_PERFORMANCE_OFF**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_performance_off)