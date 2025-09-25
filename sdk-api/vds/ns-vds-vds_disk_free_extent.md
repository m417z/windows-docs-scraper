# VDS_DISK_FREE_EXTENT structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Describes a free extent on a disk.

## Members

### `diskId`

The [VDS_OBJECT_ID](https://learn.microsoft.com/windows/desktop/VDS/vds-data-types) of the disk.

### `ullOffset`

The disk offset, in bytes, of the free extent.

### `ullSize`

The size, in bytes, of the free extent.

## See also

[IVdsDisk3::QueryFreeExtents](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk3-queryfreeextents)