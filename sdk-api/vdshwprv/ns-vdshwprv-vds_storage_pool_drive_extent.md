# VDS_STORAGE_POOL_DRIVE_EXTENT structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines a drive extent that could be used by a [storage pool](https://learn.microsoft.com/windows/desktop/VDS/storage-pool-object).

## Members

### `id`

A [VDS_OBJECT_ID](https://learn.microsoft.com/windows/desktop/VDS/vds-data-types) value that identifies the [drive object](https://learn.microsoft.com/windows/desktop/VDS/drive-object).

### `ullSize`

Size, in bytes, of the drive extent.

### `bUsed`

**TRUE** if the drive extent is currently being used by the storage pool, **FALSE** otherwise.

## See also

[IVdsStoragePool::QueryDriveExtents](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsstoragepool-querydriveextents)

[VDS_DRIVE_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_prop)