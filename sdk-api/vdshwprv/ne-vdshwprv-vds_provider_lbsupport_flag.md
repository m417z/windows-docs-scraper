# VDS_PROVIDER_LBSUPPORT_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Specifies the set of valid flags for indicating which load balance policies a hardware provider
supports.

## Constants

### `VDS_LBF_FAILOVER:0x1`

The provider supports using one primary path with the other paths being backup paths.

### `VDS_LBF_ROUND_ROBIN:0x2`

The provider supports using all paths in round robin fashion.

### `VDS_LBF_ROUND_ROBIN_WITH_SUBSET:0x4`

The provider supports using primary paths in round robin fashion. The backup paths are used if all of the
primary paths fail.

### `VDS_LBF_DYN_LEAST_QUEUE_DEPTH:0x8`

The provider supports using the path with the least number of active requests.

### `VDS_LBF_WEIGHTED_PATHS:0x10`

The provider supports using the path with the least weight (each path is assigned a weight).

### `VDS_LBF_LEAST_BLOCKS:0x20`

The provider supports using the path with the least blocks.

### `VDS_LBF_VENDOR_SPECIFIC:0x40`

The provider supports a vendor-specific policy.

## Remarks

**Note** Additional constants might be added to the **VDS_PROVIDER_LBSUPPORT_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_PROVIDER_LBSUPPORT_FLAG** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)