# VDS_STORAGE_POOL_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties of a [storage pool object](https://learn.microsoft.com/windows/desktop/VDS/storage-pool-object).

## Members

### `id`

A [VDS_OBJECT_ID](https://learn.microsoft.com/windows/desktop/VDS/vds-data-types) value that identifies the storage pool object.

### `status`

A [VDS_STORAGE_POOL_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_storage_pool_status) enumeration value that specifies the status of the storage pool.

### `health`

A [VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) enumeration value that specifies the health of the storage pool. The following are the valid values for this member.

**Windows Server 2008, Windows Vista and Windows Server 2003:** **VDS_H_DEGRADED** is not supported.

#### VDS_H_UNKNOWN (0)

#### VDS_H_HEALTHY (1)

#### VDS_H_DEGRADED (11)

### `type`

A [VDS_STORAGE_POOL_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_storage_pool_type) enumeration value that specifies the type of the storage pool.

### `pwszName`

A string that specifies the name of the storage pool.

### `pwszDescription`

A string that contains a description of the storage pool.

### `ullTotalConsumedSpace`

The amount of physical storage backing the storage pool, in bytes. The value of this member must be less than or equal to the value of the **ullProvisionedSpace** member of the [VDS_POOL_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_pool_attributes) structure.

### `ullTotalManagedSpace`

The space, in bytes, in this storage pool that can be allocated to create child storage elements (LUNs or pools), including space that has already been allocated. Depending on the way the storage pool is configured, the value of this member can be much less than the value of the **ullTotalConsumedSpace** member. For example, if the storage pool is configured as a mirrored pool, the value of **ullTotalManagedSpace** is only half as large as the value of the **ullTotalConsumedSpace** member.

### `ullRemainingFreeSpace`

The maximum size that may be used to create new LUNs or child storage pools from this pool, or to expand existing LUNs or child storage pools. To calculate the amount of managed space that has already been allocated to existing LUNs or child storage pools, subtract the value of this member from the value of the **ullTotalManagedSpace** member.

##### - health.VDS_H_DEGRADED (11)

##### - health.VDS_H_HEALTHY (1)

##### - health.VDS_H_UNKNOWN (0)

## Remarks

The [IVdsStoragePool::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsstoragepool-getproperties) returns this structure to report the properties of a [storage pool object](https://learn.microsoft.com/windows/desktop/VDS/storage-pool-object).

The following examples show how the **ullTotalConsumedSpace**, **ullTotalManagedSpace**, and **ullRemainingFreeSpace** members work together.

### Example 1

Suppose you have 2 drives of 1 TB each. Suppose further that you do the following:

1. Create a storage pool as a mirror pool.
2. Create a LUN whose size is 200 GB.

**ullTotalConsumedSpace** = 2 TB. This is the amount of storage pool space that is backed by physical storage or physical disks. Creating LUNs from the pool does not change this number.

**ullTotalManagedSpace** = 1 TB. This is the maximum size of the LUN or storage pool that can be created from this pool. Only 1 TB is available, because the pool type is a mirror with only 2 plexes.

**Note** If the pool type were RAID5, **ullTotalManagedSpace** would be (*N*-1)/*N* * **ullTotalConsumedSpace**, where *N* is the number of columns. For example, with 5 drives and 5 columns, **ullTotalManagedSpace** would be (5-1)/5 * **ullTotalConsumedSpace** or 1.6 TB.

**ullRemainingFreeSpace** = 800 GB (1 TB – 200 GB), because 200GB has already been allocated to a LUN.

(**ullTotalManagedSpace** - **ullRemainingFreeSpace**) is the amount of managed space allocated to LUNs and pools created from this pool. In this example, **ullTotalManagedSpace** - **ullRemainingFreeSpace** = 200 GB.

### Example 2

Suppose you have 2 drives of 1 TB each. Suppose further that you do the following:

1. Create a storage pool as a mirror pool.
2. Create a thin-provisioned LUN whose size is 10 TB.

**ullProvisionedSpace** = 10 TB. This applies only to thin-provisioned pools. This is the total space provisioned for the pool. The total space consumed by the pool is less than or equal to the total space provisioned for the pool.

**ullTotalConsumedSpace** = 2 TB.

**ullTotalManagedSpace** = 1 TB.

**ullRemainingFreeSpace** = 1 TB minus the amount of managed space currently backing the LUN.

**Note** Although the LUN's size is 10 TB, there may be as little as 10 GB of managed space backing the LUN, in which case there would be 20 GB of consumed space backing the mirrored LUN.

## See also

[IVdsStoragePool::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsstoragepool-getproperties)