# VDS_VOLUME_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of
valid flags for a volume object.

## Constants

### `VDS_VF_SYSTEM_VOLUME:0x1`

The volume is a system volume.

### `VDS_VF_BOOT_VOLUME:0x2`

The volume is the boot volume.

### `VDS_VF_ACTIVE:0x4`

The volume is active. That is, the *bootIndicator* value of the
underlying partition is set to true.

### `VDS_VF_READONLY:0x8`

The volume has a drive letter and a Mount Manager–assigned volume GUID name, and is enumerated by the **FindFirstVolume** and [FindNextVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextvolumew) functions. However, the volume is read-only. This flag does not apply to CD-ROM or DVD devices.

### `VDS_VF_HIDDEN:0x10`

The volume does not have a drive letter and a Mount Manager–assigned volume GUID name. The volume is not enumerated by the **FindFirstVolume** and [FindNextVolume](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextvolumew) functions. The volume can be opened by using its device name, and the opened volume can be read from or written to. An example of a volume device name is \\?\GLOBALROOT\Device\HarddiskVolumeX. This flag does not apply to CD-ROM or DVD devices.

### `VDS_VF_CAN_EXTEND:0x20`

The volume size can be extended.

### `VDS_VF_CAN_SHRINK:0x40`

The volume size can be reduced.

### `VDS_VF_PAGEFILE:0x80`

The volume contains a pagefile.

### `VDS_VF_HIBERNATION:0x100`

The volume contains a hibernation file.

### `VDS_VF_CRASHDUMP:0x200`

The volume contains the crash dump file.

### `VDS_VF_INSTALLABLE:0x400`

VDS creates a hard partition under a dynamic volume that callers can use to install an operating system. Clearing this flag causes the partition to be deleted. This flag can be set or cleared only for dynamic disks; it is always set for basic disks. This flag does not apply to CD-ROM or DVD devices.

### `VDS_VF_LBN_REMAP_ENABLED:0x800`

VDS can change the position of the volume on the disk dynamically. This flag is not valid for basic
or dynamic volumes and is supported only by some third-party volume managers.

### `VDS_VF_FORMATTING:0x1000`

The volume is being formatted.

### `VDS_VF_NOT_FORMATTABLE:0x2000`

The volume cannot be formatted. This flag applies to small portable memory devices, removable
devices, CDROM devices, and DVD devices. For CD and DVD devices, this is always set when there is media in the
drive, and is not set if there is no media in the drive.

### `VDS_VF_NTFS_NOT_SUPPORTED:0x4000`

The volume does not support NTFS, but can support other file systems. This flag applies to small
portable memory devices, removable devices, CDROM devices, and DVD devices.

### `VDS_VF_FAT32_NOT_SUPPORTED:0x8000`

The volume does not support FAT32. This flag applies to small portable memory devices, removable
devices, CDROM devices, and DVD devices.

### `VDS_VF_FAT_NOT_SUPPORTED:0x10000`

The volume does not support FAT. This flag applies to small portable memory devices, removable
devices, CDROM devices, and DVD devices.

### `VDS_VF_NO_DEFAULT_DRIVE_LETTER:0x20000`

The operating system does not assign a drive letter automatically the next time the volume is added to the computer.
If cleared, the operating system assigns a drive letter to the volume under some conditions. For basic GPT
volumes, assigning or removing a drive letter will toggle this flag. This flag does not apply to CD-ROM or DVD devices.

**Windows Server 2003:** On dynamic volumes, this flag is always set and cannot be cleared. On basic volumes, it is cleared by default and can be set or cleared only by calling the [IVdsVolume::SetFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-setflags) or [IVdsVolume::ClearFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-clearflags) method.

### `VDS_VF_PERMANENTLY_DISMOUNTED:0x40000`

The volume is offline. Volume open will succeed on an offline volume. However, I/O against an offline volume will fail. Assigning an access path, such as a drive letter, to an offline volume causes it to become online. To set this flag, call the [IVdsVolumeMF::Dismount](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-dismount)
method, setting the *bForce* and *bPermanent* parameters to
**TRUE**. This flag does not apply to CD-ROM or DVD devices.

**Windows Server 2003:** Offlining dynamic volumes is not supported.

When a volume is offline, this flag is set in the **ulFlags** member of the [VDS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop) structure, and the **VDS_VS_OFFLINE** flag is also set in the **status** member of the **VDS_VOLUME_PROP** or [VDS_VOLUME_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop2) structure.**Windows Server 2008, Windows Vista and Windows Server 2003:** The **VDS_VS_OFFLINE** flag is not supported.

### `VDS_VF_PERMANENT_DISMOUNT_SUPPORTED:0x80000`

The volume can be taken offline.

### `VDS_VF_SHADOW_COPY:0x100000`

The volume is a shadow copy of another volume. This flag is set when the shadow copy is created. It is
cleared when the shadow copy is broken from the original volume. The **VDS_VF_SHADOW_COPY**
flag is an indication for file system filter driver-based software (such as
antivirus programs) to avoid attaching to the
volume. The attribute can be used by applications to differentiate shadow copy volumes from production volumes. Applications that
perform a Fast Recovery where a shadow copy LUN is made into a non-shadow copy by clearing the read-only and hidden
bit will need to clear this bit as well. This flag does not apply to CD-ROM or DVD devices.

**Windows Server 2003:** This flag is not supported before Windows Server 2003 with SP1.

### `VDS_VF_FVE_ENABLED:0x200000`

The volume is protected by BitLocker full-volume encryption. This flag does not apply to CD-ROM or DVD devices.

**Windows Server 2003:** This flag is not supported.

### `VDS_VF_DIRTY:0x400000`

The volume's dirty bit is set.

**Windows Server 2003:** This flag is not supported.

### `VDS_VF_REFS_NOT_SUPPORTED:0x800000`

### `VDS_VF_BACKS_BOOT_VOLUME:0x1000000`

### `VDS_VF_BACKED_BY_WIM_IMAGE:0x2000000`

## Remarks

On an MBR basic disk, volume flags can be set only for the entire disk, not for individual volumes.

If the **VDS_VF_NO_DEFAULT_DRIVE_LETTER** flag is set on an MBR disk, any existing drive letters are preserved, but no new drive letters will be assigned to volumes on the disk.

This enumeration provides values for the **ulFlags** member of the
[VDS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop) structure and the *ulFlags* parameter of the [IVdsVolume::SetFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-setflags) and [IVdsVolume::ClearFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-clearflags) methods.

The following table compares the behavior of the VDS_VF_NO_DEFAULT_DRIVE_LETTER flag on MBR basic disks, GPT basic disks, and dynamic disks.

| Feature | MBR basic disks | GPT basic disks | MBR or GPT dynamic disks |
| --- | --- | --- | --- |
| The VDS_VF_NO_DEFAULT_DRIVE_LETTER flag is cleared by default. However, this flag can be set by calling [IVdsVolume::SetFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-setflags). | Yes. | Yes. | Yes.**Windows Server 2003:** This flag is always set for dynamic disks and cannot be cleared. |
| Assigning or removing a drive letter toggles the VDS_VF_NO_DEFAULT_DRIVE_LETTER flag setting. | No, because this flag is set or cleared for the entire disk. | Yes, because this flag is set or cleared for individual volumes. | Yes.**Windows Server 2003:** This flag is always set for dynamic disks and cannot be cleared. |

To create a boot volume on a dynamic disk, you must set the **VDS_VF_INSTALLABLE** flag for the volume and then format the volume by calling the [IVdsVolumeMF::Format](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-format) method.

**Note** Additional constants might be added to the **VDS_VOLUME_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_VOLUME_FLAG** enumeration constant.

## See also

[IVdsVolume::ClearFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-clearflags)

[IVdsVolume::SetFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-setflags)

[IVdsVolumeMF::Dismount](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-dismount)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_PARTITION_INFO_MBR](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_info_mbr)

[VDS_SAN_POLICY](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_san_policy)

[VDS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop)