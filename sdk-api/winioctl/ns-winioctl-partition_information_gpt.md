# PARTITION_INFORMATION_GPT structure

## Description

Contains **GUID** partition table (GPT) partition information.

## Members

### `PartitionType`

A **GUID** that identifies the partition type.

Each partition type that the EFI specification supports is identified by its own
**GUID**, which is published by the developer of the partition.

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PARTITION_BASIC_DATA_GUID**<br><br>ebd0a0a2-b9e5-4433-87c0-68b6b72699c7 | The data partition type that is created and recognized by Windows.<br><br>Only partitions of this type can be assigned drive letters, receive volume **GUID** paths, host mounted folders (also called volume mount points), and be enumerated by calls to [FindFirstVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstvolumew) and [FindNextVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextvolumew).<br><br>This value can be set only for basic disks, with one exception. If both **PARTITION_BASIC_DATA_GUID** and **GPT_ATTRIBUTE_PLATFORM_REQUIRED** are set for a partition on a basic disk that is subsequently converted to a dynamic disk, the partition remains a basic partition, even though the rest of the disk is a dynamic disk. This is because the partition is considered to be an OEM partition on a GPT disk. |
| **PARTITION_ENTRY_UNUSED_GUID**<br><br>00000000-0000-0000-0000-000000000000 | There is no partition.<br><br>This value can be set for basic and dynamic disks. |
| **PARTITION_SYSTEM_GUID**<br><br>c12a7328-f81f-11d2-ba4b-00a0c93ec93b | The partition is an EFI system partition.<br><br>This value can be set for basic and dynamic disks. |
| **PARTITION_MSFT_RESERVED_GUID**<br><br>e3c9e316-0b5c-4db8-817d-f92df00215ae | The partition is a Microsoft reserved partition.<br><br>This value can be set for basic and dynamic disks. |
| **PARTITION_LDM_METADATA_GUID**<br><br>5808c8aa-7e8f-42e0-85d2-e1e90434cfb3 | The partition is a Logical Disk Manager (LDM) metadata partition on a dynamic disk.<br><br>This value can be set only for dynamic disks. |
| **PARTITION_LDM_DATA_GUID**<br><br>af9b60a0-1431-4f62-bc68-3311714a69ad | The partition is an LDM data partition on a dynamic disk.<br><br>This value can be set only for dynamic disks. |
| **PARTITION_MSFT_RECOVERY_GUID**<br><br>de94bba4-06d1-4d40-a16a-bfd50179d6ac | The partition is a Microsoft recovery partition.<br><br>This value can be set for basic and dynamic disks. |

### `PartitionId`

The GUID of the partition.

### `Attributes`

The Extensible Firmware Interface (EFI) attributes of the partition.

This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **GPT_ATTRIBUTE_PLATFORM_REQUIRED**<br><br>0x0000000000000001 | If this attribute is set, the partition is required by a computer to function properly.<br><br>For example, this attribute must be set for OEM partitions. Note that if this attribute is set, you can use the [DiskPart.exe](https://learn.microsoft.com/windows-server/administration/windows-commands/diskpart) utility to perform partition operations such as deleting the partition. However, because the partition is not a volume, you cannot use the [DiskPart.exe](https://learn.microsoft.com/windows-server/administration/windows-commands/diskpart) utility to perform volume operations on the partition.<br><br>This attribute can be set for basic and dynamic disks. If it is set for a partition on a basic disk and the disk is converted to a dynamic disk, the partition remains a basic partition, even though the rest of the disk is a dynamic disk. This is because the partition is considered to be an OEM partition on a GPT disk. |
| **GPT_BASIC_DATA_ATTRIBUTE_NO_DRIVE_LETTER**<br><br>0x8000000000000000 | If this attribute is set, the partition does not receive a drive letter by default when the disk is moved to another computer or when the disk is seen for the first time by a computer.<br><br>This attribute is useful in storage area network (SAN) environments.<br><br>Despite its name, this attribute can be set for basic and dynamic disks. |
| **GPT_BASIC_DATA_ATTRIBUTE_HIDDEN**<br><br>0x4000000000000000 | If this attribute is set, the partition is not detected by the Mount Manager.<br><br>As a result, the partition does not receive a drive letter, does not receive a volume **GUID** path, does not host mounted folders (also called volume mount points), and is not enumerated by calls to [FindFirstVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstvolumew) and [FindNextVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextvolumew). This ensures that applications such as Disk Defragmenter do not access the partition. The Volume Shadow Copy Service (VSS) uses this attribute.<br><br>Despite its name, this attribute can be set for basic and dynamic disks. |
| **GPT_BASIC_DATA_ATTRIBUTE_SHADOW_COPY**<br><br>0x2000000000000000 | If this attribute is set, the partition is a shadow copy of another partition.<br><br>VSS uses this attribute. This attribute is an indication for file system filter driver-based software (such as antivirus programs) to avoid attaching to the volume.<br><br>An application can use the attribute to differentiate a shadow copy volume from a production volume. An application that does a fast recovery, for example, will break a shadow copy LUN and clear the read-only and hidden attributes and this attribute. This attribute is set when the shadow copy is created and cleared when the shadow copy is broken.<br><br>Despite its name, this attribute can be set for basic and dynamic disks.<br><br>**Windows Server 2003:** This attribute is not supported before Windows Server 2003 with SP1. |
| **GPT_BASIC_DATA_ATTRIBUTE_READ_ONLY**<br><br>0x1000000000000000 | If this attribute is set, the partition is read-only.<br><br>Writes to the partition will fail. [IOCTL_DISK_IS_WRITABLE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_is_writable) will fail with the **ERROR_WRITE_PROTECT** Win32 error code, which causes the file system to mount as read only, if a file system is present.<br><br>VSS uses this attribute.<br><br>Do not set this attribute for dynamic disks. Setting it can cause I/O errors and prevent the file system from mounting properly. |

### `Name`

A wide-character string that describes the partition.

## Remarks

The GPT partition format is required for disks that are used to boot computers that use
Extended Firmware Interface (EFI) firmware. GPT data disks can reside on x86, x64, and Itanium-based
architectures.

Starting with
Windows Server 2003 with SP1, GPT is supported on all Windows platforms, not only platforms that use
EFI.

## See also

[File System Recognition](https://learn.microsoft.com/windows/desktop/FileIO/file-system-recognition)

[IOCTL_DISK_GET_PARTITION_INFO_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_get_partition_info_ex)

[IOCTL_DISK_SET_PARTITION_INFO_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_set_partition_info_ex)

[PARTITION_INFORMATION_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-partition_information_ex)