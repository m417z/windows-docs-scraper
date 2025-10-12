# _PARTITION_INFORMATION structure

## Description

The PARTITION_INFORMATION structure contains partition information for a partition with a traditional AT-style Master Boot Record (MBR).

## Members

### `StartingOffset`

Specifies the offset in bytes on drive where the partition begins.

### `PartitionLength`

Specifies the length in bytes of the partition.

### `HiddenSectors`

Specifies the number of hidden sectors.

### `PartitionNumber`

Specifies the number of the partition.

### `PartitionType`

Possible values are as follows:

|Partition Type|Meaning|
|----|----|
|PARTITION_ENTRY_UNUSED|Unused entry|
|PARTITION_FAT_12|Specifies a partition with 12-bit FAT entries|
|PARTITION_XENIX_1|Specifies a XENIX Type 1 partition|
|PARTITION_XENIX_2|Specifies a XENIX Type 2 partition|
|PARTITION_FAT_16|Specifies a partition with 16-bit FAT entries.|
|PARTITION_EXTENDED|Specifies an MS-DOS V4 extended partition|
|PARTITION_HUGE|Specifies an MS-DOS V4 huge partition|
|PARTITION_IFS|Specifies an IFS partition|
|PARTITION_FAT32|Specifies a FAT32 partition|
|PARTITION_FAT32_XINT13|Windows 95/98: Specifies a partition that uses extended INT 13 services|
|PARTITION_XINT13_EXTENDED|Windows 95/98: Same as PARTITION_EXTENDED, but uses extended INT 13 services|
|PARTITION_PREP|Specifies a PowerPC Reference Platform partition|
|PARTITION_LDM|Specifies a logical disk manager partition|
|PARTITION_UNIX|Specifies a UNIX partition|
|PARTITION_NTFT|Specifies an NTFT partition. This value is used in combination (that is, bitwise logically ORed) with the other values in this table|

### `BootIndicator`

Indicates, when **TRUE**, that this partition is a bootable (active) partition for this device. When **FALSE**, this partition is not bootable. This member is set according to the partition list entry boot indicator returned by [IoReadPartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontable).

### `RecognizedPartition`

Indicates, when **TRUE**, that the system recognized the type of the partition. When **FALSE**, the system did not recognize the type of the partition.

### `RewritePartition`

Indicates, when **TRUE**, that the partition information has changed. When **FALSE**, the partition information has not changed. This member has a value of **TRUE** when the partition has changed as a result of an [IOCTL_DISK_SET_DRIVE_LAYOUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_set_drive_layout) IOCTL. This informs the system that the partition information needs to be rewritten.

## Remarks

The partition entry data in PARTITION_INFORMATION forms part of the drive layout information reported by the legacy routine [IoReadPartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontable) in the [DRIVE_LAYOUT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_drive_layout_information) structure. DRIVE_LAYOUT_INFORMATION contains an array of PARTITION_INFORMATION structures pointed to by its **PartitionEntry** member. Each partition entry contains information for a partition on the drive. PARTITION_INFORMATION is also used with the legacy routine [IoSetPartitionInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetpartitioninformation) to change the properties of the partition, such as its type, recorded on the disk.

Disk drivers should now use structures [DRIVE_LAYOUT_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_drive_layout_information_ex) and [PARTITION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information_ex) along with routines [IoReadPartitionTableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontableex) and [IoSetPartitionInformationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetpartitioninformationex) to read and alter partition information on the disk.

## See also

[DRIVE_LAYOUT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_drive_layout_information)

[DRIVE_LAYOUT_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_drive_layout_information_ex)

[IoReadPartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontable)

[IoReadPartitionTableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontableex)

[IoSetPartitionInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetpartitioninformation)

[IoSetPartitionInformationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetpartitioninformationex)

[PARTITION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information_ex)