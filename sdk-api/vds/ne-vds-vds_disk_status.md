# VDS_DISK_STATUS enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of object status values for a disk.

## Constants

### `VDS_DS_UNKNOWN:0`

The provider failed to get the disk properties from the driver (unknown status, unknown health), or the provider cannot access the disk (unknown status, healthy).

### `VDS_DS_ONLINE:1`

The disk is available. The disk status value can be VDS_DS_ONLINE, even if the status of the containing pack is VDS_PS_OFFLINE.

### `VDS_DS_NOT_READY:2`

The disk is currently not ready to use. For example, if you use ACPI Power Management to request that a disk hibernate (spin down), the disk becomes temporarily unavailable.

### `VDS_DS_NO_MEDIA:3`

The disk is removable media, such as a CD-ROM drive, or contains no media.

### `VDS_DS_FAILED:5`

The disk is unavailable and cannot be used.

### `VDS_DS_MISSING:6`

No physical device is present for the disk object, even though the pack configuration information lists the disk. This status value applies to dynamic disks only.

### `VDS_DS_OFFLINE:4`

The disk is offline.

**Windows Vista and Windows Server 2003:** This flag is not supported.

## Remarks

The [VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop) structure includes a **VDS_DISK_STATUS** value as a member to indicate the current status of a disk.

**Note** Additional constants might be added to the **VDS_DISK_STATUS** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_DISK_STATUS** enumeration constant.

## See also

[IVdsService::QueryUnallocatedDisks](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-queryunallocateddisks)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop)

[VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health)

[VDS_PACK_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_pack_status)