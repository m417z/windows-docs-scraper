# VDS_POOL_ATTRIBUTES structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the attributes of a [storage pool](https://learn.microsoft.com/windows/desktop/VDS/storage-pool-object).

## Members

### `ullAttributeMask`

A mask that specifies the attributes in the structure that are defined by this storage pool.

The list of valid attribute flags is as follows. Each flag corresponds to a member in the **VDS_POOL_ATTRIBUTES** structure. Unused bits are reserved.

| Value | Attribute defined by the storage pool |
| --- | --- |
| **VDS_POOL_ATTRIB_RAIDTYPE**<br><br>0x1L | **raidType** |
| **VDS_POOL_ATTRIB_BUSTYPE**<br><br>0x2L | **busType** |
| **VDS_POOL_ATTRIB_ALLOW_SPINDOWN**<br><br>0x4L | **bSpinDown** |
| **VDS_POOL_ATTRIB_THIN_PROVISION**<br><br>0x8L | **bIsThinProvisioned** |
| **VDS_POOL_ATTRIB_NO_SINGLE_POF**<br><br>0x10L | **bNoSinglePointOfFailure** |
| **VDS_POOL_ATTRIB_DATA_RDNCY_MAX**<br><br>0x20L | **ulDataRedundancyMax** |
| **VDS_POOL_ATTRIB_DATA_RDNCY_MIN**<br><br>0x40L | **ulDataRedundancyMin** |
| **VDS_POOL_ATTRIB_DATA_RDNCY_DEF**<br><br>0x80L | **ulDataRedundancyDefault** |
| **VDS_POOL_ATTRIB_PKG_RDNCY_MAX**<br><br>0x100L | **ulPackageRedundancyDefault** |
| **VDS_POOL_ATTRIB_PKG_RDNCY_MIN**<br><br>0x200L | **ulPackageRedundancyMin** |
| **VDS_POOL_ATTRIB_PKG_RDNCY_DEF**<br><br>0x400L | **ulPackageRedundancyDefault** |
| **VDS_POOL_ATTRIB_STRIPE_SIZE**<br><br>0x800L | **ulStripeSize** |
| **VDS_POOL_ATTRIB_STRIPE_SIZE_MAX**<br><br>0x1000L | **ulStripeSizeMax** |
| **VDS_POOL_ATTRIB_STRIPE_SIZE_MIN**<br><br>0x2000L | **ulStripeSizeMin** |
| **VDS_POOL_ATTRIB_STRIPE_SIZE_DEF**<br><br>0x4000L | **ulDefaultStripeSize** |
| **VDS_POOL_ATTRIB_NUM_CLMNS**<br><br>0x8000L | **ulNumberOfColumns** |
| **VDS_POOL_ATTRIB_NUM_CLMNS_MAX**<br><br>0x10000L | **ulNumberOfColumnsMax** |
| **VDS_POOL_ATTRIB_NUM_CLMNS_MIN**<br><br>0x20000L | **ulNumberOfColumnsMin** |
| **VDS_POOL_ATTRIB_NUM_CLMNS_DEF**<br><br>0x40000L | **ulDefaultNumberofColumns** |
| **VDS_POOL_ATTRIB_DATA_AVL_HINT**<br><br>0x80000L | **ulDataAvailabilityHint** |
| **VDS_POOL_ATTRIB_ACCS_RNDM_HINT**<br><br>0x100000L | **ulAccessRandomnessHint** |
| **VDS_POOL_ATTRIB_ACCS_DIR_HINT**<br><br>0x200000L | **ulAccessDirectionHint** |
| **VDS_POOL_ATTRIB_ACCS_SIZE_HINT**<br><br>0x400000L | **ulAccessSizeHint** |
| **VDS_POOL_ATTRIB_ACCS_LTNCY_HINT**<br><br>0x800000L | **ulAccessLatencyHint** |
| **VDS_POOL_ATTRIB_ACCS_BDW_WT_HINT**<br><br>0x1000000L | **ulAccessBandwidthWeightHint** |
| **VDS_POOL_ATTRIB_STOR_COST_HINT**<br><br>0x2000000L | **ulStorageCostHint** |
| **VDS_POOL_ATTRIB_STOR_EFFCY_HINT**<br><br>0x4000000L | **ulStorageEfficiencyHint** |
| **VDS_POOL_ATTRIB_CUSTOM_ATTRIB**<br><br>0x8000000L | **pPoolCustomAttributes** |

### `raidType`

A [VDS_RAID_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_raid_type) enumeration value that specifies the RAID type of the storage pool. If the storage pool does not have a specific RAID type, set this member to **VDS_RT_UNKNOWN** and clear the **VDS_POOL_ATTRIB_RAIDTYPE** attribute flag in the **ullAttributeMask** member.

### `busType`

A [VDS_STORAGE_BUS_TYPE](https://learn.microsoft.com/windows/desktop/api/vdslun/ne-vdslun-vds_storage_bus_type) enumeration value that specifies the bus type of the drives in the storage pool.

### `pwszIntendedUsage`

A string that specifies the usage of the storage pool. Typically, this may indicate the application that is using the storage pool (for example, "SQL" or "Exchange") or the business function that is using the storage pool (for example, "Finance" or "Human Resources").

### `bSpinDown`

**TRUE** if the drives in the storage pool spin down automatically to reduce power usage, or **FALSE** otherwise.

### `bIsThinProvisioned`

**TRUE** if the storage pool is thin provisioned, or **FALSE** otherwise. If the pool is thin provisioned, the number of bytes in the consumed space of the pool could be less than the number of bytes in the provisioned space of the pool. (The number of bytes in the provisioned space is stored in the **ullProvisionedSpace** member of this structure. The number of bytes in the consumed space is stored in the **ullTotalConsumedSpace** member of the [VDS_STORAGE_POOL_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_storage_pool_prop) structure.) When a hardware provider sets this member to **TRUE**, it must also set the **type** member of the **VDS_STORAGE_POOL_PROP** structure to **VDS_SPT_CONCRETE**.

### `ullProvisionedSpace`

If the pool is thin provisioned, this member specifies the space, in bytes, that is provisioned for the pool. The value of this member must be greater than or equal to the value of the **ullTotalConsumedSpace** member of the [VDS_STORAGE_POOL_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_storage_pool_prop) structure.

### `bNoSinglePointOfFailure`

**TRUE** if there is no single point of failure in the pool, or **FALSE** otherwise.

### `ulDataRedundancyMax`

The maximum number of complete copies of the data that can be maintained in this storage pool.

### `ulDataRedundancyMin`

The minimum number of complete copies of the data that can be maintained in this storage pool.

### `ulDataRedundancyDefault`

The default number of complete copies of the data that are maintained in this storage pool.

### `ulPackageRedundancyMax`

The maximum number of drives that can be used in the storage pool to ensure package redundancy. Package redundancy indicates the number of drives that can fail in the storage pool without resulting in a data loss.

### `ulPackageRedundancyMin`

The minimum number of drives that can be used in the storage pool to ensure package redundancy. Package redundancy indicates the number of drives that can fail in the storage pool without resulting in a data loss.

### `ulPackageRedundancyDefault`

The default number of drives that are used in the storage pool to ensure package redundancy. Package redundancy indicates the number of drives that can fail in the storage pool without resulting in a data loss.

### `ulStripeSize`

The mirror or parity stripe size, in bytes, of the storage pool if the pool is striped (with or without parity).

### `ulStripeSizeMax`

The maximum stripe size, in bytes, that is supported by the storage pool.

### `ulStripeSizeMin`

The minimum stripe size, in bytes, that is supported by the storage pool.

### `ulDefaultStripeSize`

The default stripe size, in bytes, that is supported by the storage pool.

### `ulNumberOfColumns`

The number of columns of the storage pool if the pool is striped (with or without parity).

### `ulNumberOfColumnsMax`

The maximum number of columns supported by the storage pool.

### `ulNumberOfColumnsMin`

The minimum number of columns supported by the storage pool.

### `ulDefaultNumberofColumns`

The default number of columns supported by the storage pool.

### `ulDataAvailabilityHint`

A hint from the client that indicates the importance placed on data availability. Values range from 0 (Not Important) to 10 (Very Important).

### `ulAccessRandomnessHint`

A hint from the client that indicates the randomness of data access. Values range from 0 (Entirely Sequential) to 10 (Entirely Random).

### `ulAccessDirectionHint`

A hint from the client that indicates the direction of data access. Values range from 0 (Entirely Read) to 10 (Entirely Write).

### `ulAccessSizeHint`

A hint from the client that indicates the optimal access size in megabytes.

### `ulAccessLatencyHint`

A hint from the client that indicates the importance of access latency to the client. Values range from 0 (Not Important) to 10 (Very Important).

### `ulAccessBandwidthWeightHint`

A hint from the client that indicates the importance of high bandwidth. Values range from 0 (Not Important) to 10 (Very Important).

### `ulStorageCostHint`

A hint from the client that indicates the importance of storage cost to the client. Values range from 0 (Not Important) to 10 (Very Important). If the storage cost is very important to the client, a value of 10 indicates that the client would prefer to provision the pool using lower cost storage.

### `ulStorageEfficiencyHint`

A hint from the client that indicates the importance of storage efficiency to the client. Values range from 0 (Not Important) to 10 (Very Important).

### `ulNumOfCustomAttributes`

The number of custom attributes defined for the storage pool.

### `pPoolCustomAttributes`

An array of [VDS_POOL_CUSTOM_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_pool_custom_attributes) structures. Each structure contains a custom attribute that is defined for the storage pool.

### `bReserved1`

This member is reserved for future use. Do not use.

### `bReserved2`

This member is reserved for future use. Do not use.

### `ulReserved1`

This member is reserved for future use. Do not use.

### `ulReserved2`

This member is reserved for future use. Do not use.

### `ullReserved1`

This member is reserved for future use. Do not use.

### `ullReserved2`

This member is reserved for future use. Do not use.

## Remarks

If an attribute is set for a storage pool, that attribute setting must apply to all drive extents that make up the pool.

## See also

[IVdsHwProviderStoragePools::QueryStoragePools](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwproviderstoragepools-querystoragepools)

[IVdsStoragePool::GetAttributes](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsstoragepool-getattributes)