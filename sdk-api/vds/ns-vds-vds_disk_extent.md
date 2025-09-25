# VDS_DISK_EXTENT structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties of
a disk extent.

## Members

### `diskId`

The GUID of the disk.

### `type`

A [VDS_DISK_EXTENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_disk_extent_type) enumeration value that specifies the type of the disk extent.

### `ullOffset`

The disk offset, in bytes.

### `ullSize`

The size of the extent, in bytes.

### `volumeId`

The GUID of the volume to which the extent belongs.

### `plexId`

If the extent is from a volume, this member is the GUID of the plex to which the extent belongs.

### `memberIdx`

If the extent is from a volume plex, this member is the zero-based index of the plex member to which the extent belongs.

## Remarks

The *volumeId*, *plexId*, and
*memberIdx* members apply to data and ESP partitions only. If the extent lacks a volume
association, the GUIDs for *volumeId* and *plexId* are GUID_NULL,
and *memberIdx* is zero. The *memberIdx* member is always zero
unless the volume is striped or striped with parity (RAID-5). An extent can also be unallocated or free.

The [IVdsDisk::QueryExtents](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-queryextents) method returns this
structure to report the property details of a disk extent. Likewise, the
[IVdsVolumePlex::QueryExtents](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumeplex-queryextents) method
returns it to report the details of the disk extents allocated to a plex.

A disk extent is a contiguous set of blocks on a single disk or LUN handled by a software provider. A drive
extent is not required to be a contiguous set of blocks.

## See also

[Disk Object](https://learn.microsoft.com/windows/desktop/VDS/disk-object)

[IVdsDisk::QueryExtents](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-queryextents)

[IVdsVolumePlex::QueryExtents](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumeplex-queryextents)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_DISK_EXTENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_disk_extent_type)