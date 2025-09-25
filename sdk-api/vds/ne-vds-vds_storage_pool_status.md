# VDS_STORAGE_POOL_STATUS enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of object status values for a [storage pool](https://learn.microsoft.com/windows/desktop/VDS/storage-pool-object).

## Constants

### `VDS_SPS_UNKNOWN:0`

The provider failed to get the storage pool properties or could not access the storage pool.

### `VDS_SPS_ONLINE:1`

The storage pool is available.

### `VDS_SPS_NOT_READY:2`

The storage pool is busy.

### `VDS_SPS_OFFLINE:4`

The storage pool is not available.

## Remarks

The [VDS_STORAGE_POOL_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_storage_pool_prop) structure uses a **VDS_STORAGE_POOL_STATUS** value in the [status](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_storage_pool_prop) member to indicate the current status of the storage pool.

**Note** Additional constants might be added to the **VDS_STORAGE_POOL_STATUS** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_STORAGE_POOL_STATUS** enumeration constant.

## See also

[VDS_STORAGE_POOL_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_storage_pool_prop)