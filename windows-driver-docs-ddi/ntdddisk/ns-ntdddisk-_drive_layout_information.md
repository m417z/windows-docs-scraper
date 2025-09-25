# _DRIVE_LAYOUT_INFORMATION structure

## Description

The DRIVE_LAYOUT_INFORMATION structure is obsolete and is provided only to support existing drivers. New drivers must use [DRIVE_LAYOUT_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_drive_layout_information_ex).

The DRIVE_LAYOUT_INFORMATION structure is used to report information about a disk drive and its partitions. It is also used to write new drive layout information to the disk.

## Members

### `PartitionCount`

Contains the number of partitions on the drive.

### `Signature`

Contains the disk signature.

### `PartitionEntry`

Contains a variable-length array of [PARTITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information) structures, one for each partition on the drive.

## Remarks

In Windows 2000 and later operating systems, disk drivers should use structures [DRIVE_LAYOUT_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_drive_layout_information_ex) and [PARTITION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information_ex) along with routines **IoReadPartitionTableEx** and [IoSetPartitionInformationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetpartitioninformationex) to read and alter partition information on the disk.

## See also

[IOCTL_DISK_GET_DRIVE_LAYOUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_drive_layout)

[IOCTL_DISK_GET_PARTITION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_partition_info)

[IOCTL_DISK_SET_DRIVE_LAYOUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_set_drive_layout)

[IoReadPartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontable)

[IoReadPartitionTableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontableex)

[IoSetPartitionInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetpartitioninformation)

[IoWritePartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iowritepartitiontable)