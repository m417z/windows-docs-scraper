# VDS_DISK_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid flags for a disk object.

**Note** Except for **VDS_DF_READ_ONLY**, these flags cannot be set by using the [IVdsDisk::SetFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-setflags) method or cleared by using the [IVdsDisk::ClearFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-clearflags) method.

## Constants

### `VDS_DF_AUDIO_CD:0x1`

The media in a CDROM or DVD drive is an audio CD.

### `VDS_DF_HOTSPARE:0x2`

The disk is reserved for use only as hot spare.

### `VDS_DF_RESERVE_CAPABLE:0x4`

This flag is reserved for future use. Do not use.

### `VDS_DF_MASKED:0x8`

The disk is masked.

### `VDS_DF_STYLE_CONVERTIBLE:0x10`

The partition style on disk can be converted between MBR and GPT.

### `VDS_DF_CLUSTERED:0x20`

The disk is clustered.

### `VDS_DF_READ_ONLY:0x40`

This flag indicates that the disk's read-only attribute, which is maintained by the Windows operating system, is set. This attribute can be set by using the [IVdsDisk::SetFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-setflags) method and cleared by using the [IVdsDisk::ClearFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-clearflags) method. This flag and the corresponding attribute do not necessarily reflect the actual read-only state of the disk, which is indicated by the **VDS_DF_CURRENT_READ_ONLY** flag.

**Windows Vista and Windows Server 2003:** Not supported before Windows Vista with SP1 and Windows Server 2008.

### `VDS_DF_SYSTEM_DISK:0x80`

The disk hosts the current system volume. If the disk is dynamic and the volume is a mirror, the flag is set on the disk that holds the plex that was used as the system volume at startup.

**Windows Vista and Windows Server 2003:** Not supported before Windows Vista with SP1 and Windows Server 2008.

### `VDS_DF_BOOT_DISK:0x100`

The disk hosts the current boot volume.

**Windows Vista and Windows Server 2003:** Not supported before Windows Vista with SP1 and Windows Server 2008.

### `VDS_DF_PAGEFILE_DISK:0x200`

The disk contains a pagefile.

**Windows Vista and Windows Server 2003:** Not supported before Windows Vista with SP1 and Windows Server 2008.

### `VDS_DF_HIBERNATIONFILE_DISK:0x400`

The disk contains the hibernation volume.

**Windows Vista and Windows Server 2003:** Not supported before Windows Vista with SP1 and Windows Server 2008.

### `VDS_DF_CRASHDUMP_DISK:0x800`

The disk contains the crashdump volume.

**Windows Vista and Windows Server 2003:** Not supported before Windows Vista with SP1 and Windows Server 2008.

### `VDS_DF_HAS_ARC_PATH:0x1000`

The disk is visible to the computer at startup. For GPT, this flag is set for all disks. For MBR, it is set only for disks that are visible to the computer's BIOS firmware. (This is generally the first 12 disks that are connected to the computer and visible to the BIOS at startup.)

**Windows Vista and Windows Server 2003:** Not supported before Windows Vista with SP1 and Windows Server 2008.

### `VDS_DF_DYNAMIC:0x2000`

The disk is a dynamic disk.

**Windows Vista and Windows Server 2003:** Not supported before Windows Vista with SP1 and Windows Server 2008.

### `VDS_DF_BOOT_FROM_DISK:0x4000`

This flag is set on the hard disk from which the computer is configured to start.

On computers that use the BIOS firmware, this is the first hard disk that the firmware detects when the computer starts up (device 80H, or 81H if 80H is assigned to a USB flash device). If the user plugs a USB flash device into the computer before startup, this may cause device 80H to be assigned to the USB device and may cause 81H to be assigned the first hard disk detected by the firmware. Note that in that case, this flag is not set on the USB flash device.

On computers that use the Extended Firmware Interface (EFI), this flag is set on the disk that contains the EFI System Partition (ESP) that was used to start the computer. Note that if none of the disks contain an ESP, or if there are multiple ESPs, this flag is not set on any of the disks.**Windows Server 2008, Windows Vista and Windows Server 2003:** This flag is not supported.

### `VDS_DF_CURRENT_READ_ONLY:0x8000`

This flag indicates that the disk is in a read-only state. If it is not set, the disk is read/write. Unlike the **VDS_DF_READ_ONLY** flag, which is used to change the disk's read-only attribute maintained by the Windows operating system, this flag reflects the actual disk state. This flag cannot be set by using the [IVdsDisk::SetFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-setflags) method or cleared by using the [IVdsDisk::ClearFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-clearflags) method.

The disk will be in a read-only state if its read-only attribute is set. However, a disk can be in a read-only state even if its read-only attribute is not set, if the underlying hardware is read-only. For example, if the LUN is in read-only state, or if the disk is a virtual hard disk that resides on a volume that is read-only, the underlying hardware is read-only, and therefore the disk is in a read-only state.**Windows Server 2008, Windows Vista and Windows Server 2003:** This flag is not supported.

### `VDS_DF_REFS_NOT_SUPPORTED:0x10000`

## Remarks

This enumeration provides the values for the **ulFlags** member of the [VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop) and [VDS_DISK_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop2) structures. The **VDS_DISK_PROP** structure is returned by the [IVdsDisk::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-getproperties) method. The **VDS_DISK_PROP2** structure is returned by the [IVdsDisk3::GetProperties2](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk3-getproperties2) method.

All of the **VDS_DISK_FLAG** flag values are set by the VDS service; they cannot be set by applications. An exception is the **VDS_DF_READ_ONLY** flag, which can be set by using the [IVdsDisk::SetFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-setflags) method and cleared by using the [IVdsDisk::ClearFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-clearflags) method.

USB disks and CD-ROMs have the following restrictions and capabilities:

* Dynamic disks are not supported on USB disks (including USB removable hard disks and USB flash drives).
* A removable USB disk cannot be used as a boot disk.
* You can [create a bootable WinPE RAM disk on a USB flash drive or CD-ROM](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-vista/cc766195(v=ws.10)).**Windows Server 2003:** Not supported.
* A USB flash drive can have only one partition. The partition type can be MBR or GPT.

**Note** Additional constants might be added to the **VDS_DISK_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_DISK_FLAG** enumeration constant.

## See also

[IVdsDisk3::GetProperties2](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk3-getproperties2)

[IVdsDisk::ClearFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-clearflags)

[IVdsDisk::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-getproperties)

[IVdsDisk::SetFlags](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-setflags)

[VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop)

[VDS_DISK_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop2)