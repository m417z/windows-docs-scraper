# CHANGE_ATTRIBUTES_PARAMETERS structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the partition parameters of a partition style.

## Members

### `style`

Determines the partition parameters. Supported values are **VDS_PST_MBR** or
**VDS_PST_GPT**.

### `MbrPartInfo`

Used if **style** is **VDS_PST_MBR**. Parameters for a Master
Boot Record (MBR) disk.

### `MbrPartInfo.bootIndicator`

If **TRUE**, the partition is active and can be booted; otherwise the partition
cannot be used to boot the system.

### `GptPartInfo`

Used if **style** is **VDS_PST_GPT**. Parameters for a GUID
Partition Table (GPT) disk.

### `GptPartInfo.attributes`

Attributes of the partition. This can be one or more of the following values:

| Value | Meaning |
| --- | --- |
| **GPT_ATTRIBUTE_PLATFORM_REQUIRED**<br><br>0x0000000000000001 | If this attribute is set, the partition is required by a computer to function properly. <br><br>For example, this attribute must be set for OEM partitions. Note that if this attribute is set, you can use the DiskPart.exe utility to perform partition operations such as deleting the partition. However, because the partition is not a volume, you cannot use the DiskPart.exe utility to perform volume operations on the partition.<br><br>This attribute can be set for basic and dynamic disks. If it is set for a partition on a basic disk and the disk is converted to a dynamic disk, the partition remains a basic partition, even though the rest of the disk is a dynamic disk. This is because the partition is considered to be an OEM partition on a GPT disk. |
| **GPT_BASIC_DATA_ATTRIBUTE_NO_DRIVE_LETTER**<br><br>0x8000000000000000 | If this attribute is set, the partition does not receive a drive letter by default when the disk is moved to another computer or the disk is seen for the first time by a computer. <br><br>This attribute is useful in SAN environments.<br><br>Despite its name, this attribute can be set for basic and dynamic disks. |
| **GPT_BASIC_DATA_ATTRIBUTE_HIDDEN**<br><br>0x4000000000000000 | If this attribute is set, the partition is not detected by the Mount Manager. <br><br>As a result, the partition does not receive a drive letter, does not receive a volume GUID path, does not host mounted folders (also called volume mount points), and is not enumerated by calls to [FindFirstVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstvolumew) and [FindNextVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextvolumew). This ensures that applications such as Disk Defragmenter do not access the partition. The Volume Shadow Copy Service (VSS) uses this attribute.<br><br>Despite its name, this attribute can be set for basic and dynamic disks. |
| **GPT_BASIC_DATA_ATTRIBUTE_SHADOW_COPY**<br><br>0x2000000000000000 | If this attribute is set, the partition is a shadow copy of another partition. <br><br>This attribute is used by the Volume Shadow Copy service (VSS). This attribute is an indication for file system filter driver-based software (such as antivirus programs) to avoid attaching to the volume.<br><br>An application can use the attribute to differentiate a shadow copy volume from a production volume. An application that performs a fast recovery, for example, will break a shadow copy LUN by clearing the read-only and hidden attributes and this attribute. This attribute is set when the shadow copy is created and cleared when the shadow copy is broken.<br><br>Despite its name, this attribute can be set for basic and dynamic disks.<br><br>**Windows Server 2003:** This attribute is not supported before Windows Server 2003 with SP1. |
| **GPT_BASIC_DATA_ATTRIBUTE_READ_ONLY**<br><br>0x1000000000000000 | If this attribute is set, the partition is read-only. <br><br>All requests to write to the partition will fail. [IOCTL_DISK_IS_WRITABLE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_is_writable) will fail with the ERROR_WRITE_PROTECT Win32 error code, which causes the file system to mount as read-only, if a file system is present.<br><br>VSS uses this attribute.<br><br>Do not set this attribute for dynamic disks. Setting it can cause I/O errors and prevent the file system from mounting properly. |

## Remarks

The
[IVdsAdvancedDisk::ChangeAttributes](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-changeattributes)
method takes this structure as a parameter.

## See also

[IVdsAdvancedDisk::ChangeAttributes](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-changeattributes)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)