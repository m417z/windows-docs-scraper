# VDS_STORAGE_POOL_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of [storage pool](https://learn.microsoft.com/windows/desktop/VDS/storage-pool-object) types. These values are used in the [type](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_storage_pool_prop) member of the **VDS_STORAGE_POOL_PROP** structure.

## Constants

### `VDS_SPT_UNKNOWN:0`

The storage pool type is unknown.

### `VDS_SPT_PRIMORDIAL:0x1`

The storage pool type is primordial.

### `VDS_SPT_CONCRETE:0x2`

The storage pool type is concrete (non-primordial).

## Remarks

The terms *primordial storage pool* and *concrete storage pool* are defined in section 5.1.3 of the "Part 3: Block Devices" portion of the [SMI-S v1.5 specification](https://www.snia.org/tech_activities/standards/curr_standards/smi/), which can be downloaded from the [SNIA website](https://www.snia.org/).

A storage area network (SAN) can contain one primordial pool. You can create multiple concrete pools within the primordial pool. The attributes in the [VDS_POOL_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_pool_attributes) structure do not apply to a primordial pool, because it contains all physically available storage on the SAN. For example, suppose you have ten 10-GB SAN drives, five of which are in a concrete pool. In the Disk Management utility, the primordial pool has ten disk drives and a size of 100 GB, because it has a total of 100 GB of storage space available. The concrete pool has only 50 GB of storage space available. But if it is thin-provisioned, the size that the Disk Management utility reports for the concrete pool might be much larger than 50 GB.

**Note** Additional constants might be added to the **VDS_STORAGE_POOL_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_STORAGE_POOL_TYPE** enumeration constant.

## See also

[VDS_STORAGE_POOL_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_storage_pool_prop)