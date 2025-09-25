# CREATE_PARTITION_PARAMETERS structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the partition parameters of a partition style.

## Members

### `style`

### `MbrPartInfo`

Parameters for a Master Boot Record (MBR) disk. Used if **style** is
**VDS_PST_MBR**.

### `MbrPartInfo.partitionType`

Indicates the system-defined MBR partition type. Possible values are as follows:

| Value | Meaning |
| --- | --- |
| **PARTITION_ENTRY_UNUSED**<br><br>0x00 | Unused entry. |
| **PARTITION_FAT_12**<br><br>0x01 | Specifies a partition with 12-bit FAT entries. |
| **PARTITION_XENIX_1**<br><br>0x02 | Specifies a XENIX Type 1 partition. |
| **PARTITION_XENIX_2**<br><br>0x03 | Specifies a XENIX Type 2 partition. |
| **PARTITION_FAT_16**<br><br>0x04 | Specifies a partition with 16-bit FAT entries. |
| **PARTITION_EXTENDED**<br><br>0x05 | Specifies an MS-DOS V4 extended partition. |
| **PARTITION_HUGE**<br><br>0x06 | Specifies an MS-DOS V4 huge partition. This value indicates that there is no Microsoft file system on the partition. Use this value when creating a logical volume. |
| **PARTITION_IFS**<br><br>0x07 | Specifies an NTFS or ExFAT partition. |
| **PARTITION_OS2BOOTMGR**<br><br>0x0A | Specifies an OS/2 Boot Manager, OPUS, or Coherent swap partition. |
| **PARTITION_FAT32**<br><br>0x0B | Specifies a FAT32 partition. |
| **PARTITION_FAT32_XINT13**<br><br>0x0C | This value is not supported. |
| **PARTITION_XINT13**<br><br>0x0E | This value is not supported. |
| **PARTITION_XINT13_EXTENDED**<br><br>0x0F | This value is not supported. |
| **PARTITION_PREP**<br><br>0x41 | Specifies a PowerPC Reference Platform partition. |
| **PARTITION_LDM**<br><br>0x42 | Specifies a logical disk manager partition. |
| **PARTITION_UNIX**<br><br>0x63 | Specifies a UNIX partition. |
| **PARTITION_NTFT**<br><br>0x80 | Specifies an NTFT partition. This value is used in combination (that is, bitwise logically ORed) with the other values in this table. |

### `MbrPartInfo.bootIndicator`

If **TRUE**, the partition is active and can be booted; otherwise the partition
cannot be used to boot the system.

### `GptPartInfo`

Parameters for a GUID Partition Table (GPT) disk. Used if **style** is
**VDS_PST_GPT**.

### `GptPartInfo.partitionType`

A GUID of the partition type.

| Value | Meaning |
| --- | --- |
| **PARTITION_ENTRY_UNUSED_GUID**<br><br>00000000-0000-0000-0000-000000000000 | There is no partition.<br><br>This attribute can be set for basic and dynamic disks. |
| **PARTITION_SYSTEM_GUID**<br><br>c12a7328-f81f-11d2-ba4b-00a0c93ec93b | The partition is an EFI system partition.<br><br>This attribute can be set for basic and dynamic disks. |
| **PARTITION_MSFT_RESERVED_GUID**<br><br>e3c9e316-0b5c-4db8-817d-f92df00215ae | The partition is a Microsoft reserved partition.<br><br>This attribute can be set for basic and dynamic disks. |
| **PARTITION_BASIC_DATA_GUID**<br><br>ebd0a0a2-b9e5-4433-87c0-68b6b72699c7 | The data partition type that is created and recognized by Windows. <br><br>Only partitions of this type can be assigned drive letters, receive volume GUID paths, host mounted folders (also called volume mount points) and be enumerated by calls to [FindFirstVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstvolumew) and [FindNextVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextvolumew).<br><br>This value can be set only for basic disks, with one exception. If both PARTITION_BASIC_DATA_GUID and GPT_ATTRIBUTE_PLATFORM_REQUIRED are set for a partition on a basic disk that is subsequently converted to a dynamic disk, the partition remains a basic partition, even though the rest of the disk is a dynamic disk. This is because the partition is considered to be an OEM partition on a GPT disk. |
| **PARTITION_LDM_METADATA_GUID**<br><br>5808c8aa-7e8f-42e0-85d2-e1e90434cfb3 | The partition is a Logical Disk Manager (LDM) metadata partition on a dynamic disk.<br><br>This value can be set only for dynamic disks. |
| **PARTITION_LDM_DATA_GUID**<br><br>af9b60a0-1431-4f62-bc68-3311714a69ad | The partition is an LDM data partition on a dynamic disk.<br><br>This value can be set only for dynamic disks. |
| **PARTITION_MSFT_RECOVERY_GUID**<br><br>de94bba4-06d1-4d40-a16a-bfd50179d6ac | The partition is a Microsoft recovery partition.<br><br>This attribute can be set for basic and dynamic disks. |

### `GptPartInfo.partitionId`

If ID of the partition. If set to GUID_NULL (0) on creation, a unique value will be generated.

### `GptPartInfo.attributes`

Attributes of the partition. This can be one or more of the following values:

| Value | Meaning |
| --- | --- |
| **GPT_ATTRIBUTE_PLATFORM_REQUIRED**<br><br>0x0000000000000001 | If this attribute is set, the partition is required by a computer to function properly.<br><br>For example, this attribute must be set for OEM partitions. Note that if this attribute is set, you can use the DiskPart.exe utility to perform partition operations such as deleting the partition. However, because the partition is not a volume, you cannot use the DiskPart.exe utility to perform volume operations on the partition.<br><br>This attribute can be set for basic and dynamic disks. If it is set for a partition on a basic disk and the disk is converted to a dynamic disk, the partition remains a basic partition, even though the rest of the disk is a dynamic disk. This is because the partition is considered to be an OEM partition on a GPT disk. |
| **GPT_BASIC_DATA_ATTRIBUTE_NO_DRIVE_LETTER**<br><br>0x8000000000000000 | If this attribute is set, the partition does not receive a drive letter by default when the disk is moved to another computer or when the disk is seen for the first time by a computer. <br><br>This attribute is useful in storage area network (SAN) environments.<br><br>Despite its name, this attribute can be set for basic and dynamic disks. |
| **GPT_BASIC_DATA_ATTRIBUTE_HIDDEN**<br><br>0x4000000000000000 | If this attribute is set, the partition is not detected by the Mount Manager. <br><br>As a result, the partition does not receive a drive letter, does not receive a volume GUID path, does not host mounted folders (also called volume mount points), and is not enumerated by calls to [FindFirstVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstvolumew) and [FindNextVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextvolumew). This ensures that applications such as Disk Defragmenter do not access the partition. The Volume Shadow Copy Service (VSS) uses this attribute.<br><br>Despite its name, this attribute can be set for basic and dynamic disks. |
| **GPT_BASIC_DATA_ATTRIBUTE_SHADOW_COPY**<br><br>0x2000000000000000 | If this attribute is set, the partition is a shadow copy of another partition. <br><br>This attribute is used by the Volume Shadow Copy service (VSS). This attribute is an indication for file system filter driver-based software (such as antivirus programs) to avoid attaching to the volume.<br><br>An application can use the attribute to differentiate a shadow copy volume from a production volume. For example, an application that performs a fast recovery will break a shadow copy LUN by clearing the read-only and hidden attributes and this attribute. This attribute is set when the shadow copy is created and cleared when the shadow copy is broken.<br><br>Despite its name, this attribute can be set for basic and dynamic disks.<br><br>**Windows Server 2003:** This attribute is not supported before Windows Server 2003 with SP1. |
| **GPT_BASIC_DATA_ATTRIBUTE_READ_ONLY**<br><br>0x1000000000000000 | If this attribute is set, the partition is read-only. <br><br>All requests to write to the partition will fail. [IOCTL_DISK_IS_WRITABLE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_is_writable) will fail with the ERROR_WRITE_PROTECT Win32 error code, which causes the file system to mount as read-only, if a file system is present. <br><br>VSS uses this attribute.<br><br>Do not set this attribute for dynamic disks. Setting it can cause I/O errors and prevent the file system from mounting properly. |

### `GptPartInfo.name`

Null-terminated Unicode string that specifies the name of the partition.

## Remarks

The
[IVdsAdvancedDisk::CreatePartition](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-createpartition)
method passes this structure as an argument to specify a set of parameters.

## See also

[IVdsAdvancedDisk::CreatePartition](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-createpartition)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_PARTITION_STYLE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_partition_style)