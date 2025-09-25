# IoReadPartitionTableEx function

## Description

The **IoReadPartitionTableEx** routine reads a list of partitions on a disk having a specified sector size and creates an entry in the partition list for each recognized partition.

## Parameters

### `DeviceObject` [in]

Pointer to the device object for the disk whose partitions are to be read.

### `DriveLayout`

Pointer to an uninitialized address. If successful, **IoReadPartitionTableEx** allocates the memory for this buffer from nonpaged pool and returns the drive layout information in it.

## Return value

This routine returns a value of STATUS_SUCCESS if at least one sector table was read. Otherwise, it returns an error status value and sets the pointer at *PartitionBuffer* to **NULL**.

## Remarks

**IoReadPartitionTableEx** must only be used by disk drivers. Other drivers should use the [IOCTL_DISK_GET_DRIVE_LAYOUT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_drive_layout_ex) disk I/O request instead.

**IoReadPartitionTableEx** is able to read partition table information from GUID Partition Table (GPT) disks as well as legacy Master Boot Record (MBR) disks. Disk device drivers call this routine during driver initialization.

It is the responsibility of the caller to deallocate the *PartitionBuffer* that was allocated by this routine with **ExFreePool**.

Note that disk drivers also return and set partition information in response to IRP_MJ_DEVICE_CONTROL requests with the following I/O control codes:

IOCTL_DISK_GET_PARTITION_INFO_EX

IOCTL_DISK_SET_PARTITION_INFO_EX

IOCTL_DISK_GET_DRIVE_LAYOUT_EX

IOCTL_DISK_SET_DRIVE_LAYOUT_EX

IOCTL_DISK_GET_DRIVE_GEOMETRY

## See also

[DRIVE_LAYOUT_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_drive_layout_information_ex)

[IOCTL_DISK_GET_DRIVE_GEOMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_drive_geometry)

[IOCTL_DISK_GET_DRIVE_LAYOUT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_drive_layout_ex)

[IOCTL_DISK_GET_PARTITION_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_partition_info_ex)

[IOCTL_DISK_SET_DRIVE_LAYOUT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_set_drive_layout_ex)

[IOCTL_DISK_SET_PARTITION_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_set_partition_info_ex)

[IoSetPartitionInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetpartitioninformation)

[IoWritePartitionTableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iowritepartitiontableex)

[PARTITION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information_ex)