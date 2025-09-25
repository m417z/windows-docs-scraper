# IoReadPartitionTable function

## Description

The **IoReadPartitionTable** routine is **obsolete** and is provided only to support existing drivers. New drivers must use [IoReadPartitionTableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontableex). **IoReadPartitionTable** reads a list of partitions on a disk having a specified sector size and creates an entry in the partition list for each recognized partition.

## Parameters

### `DeviceObject` [in]

Pointer to the device object for the disk whose partitions are to be read.

### `SectorSize` [in]

Specifies the size of the sectors on the disk.

### `ReturnRecognizedPartitions` [in]

Indicates whether only recognized partitions or all partition entries should be returned.

### `PartitionBuffer` [out]

Pointer to an uninitialized address. If successful, **IoReadPartitionTable** allocates the memory for this buffer from nonpaged pool and returns the drive layout information in it.

## Return value

This routine returns a value of STATUS_SUCCESS if at least one sector table was read. Otherwise, it returns an error status and sets the pointer at *PartitionBuffer* to **NULL**.

## Remarks

**IoReadPartitionTable** must only be used by disk drivers. Other drivers should use the [IOCTL_DISK_GET_DRIVE_LAYOUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_drive_layout) disk I/O request instead.

Disk device drivers call this routine during driver initialization.

It is the responsibility of the caller to deallocate the *PartitionBuffer* that was allocated by this routine with **ExFreePool**.

The algorithm used by this routine is determined by the Boolean value *ReturnRecognizedPartitions*:

* Read each partition table and, for each valid and recognized partition found, fill in an element in an array of [PARTITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information) entries. The array of partition information entries is pointed to by the **PartitionEntry** member of a [DRIVE_LAYOUT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_drive_layout_information) structure. The DRIVE_LAYOUT_INFORMATION structure is found at the location pointed to by *PartitionBuffer*. Extended partitions are located in order to find other partition tables, but no entries are built for them.

Read each partition table and, for each and every entry, fill in a partition information entry. Extended partitions are located to find each partition on the disk; entries are built for these as well.

## See also

[IOCTL_DISK_GET_DRIVE_LAYOUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_drive_layout)

[IOCTL_DISK_GET_PARTITION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_partition_info)

[IOCTL_DISK_SET_DRIVE_LAYOUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_set_drive_layout)

[IoSetPartitionInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetpartitioninformation)

[IoWritePartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iowritepartitiontable)