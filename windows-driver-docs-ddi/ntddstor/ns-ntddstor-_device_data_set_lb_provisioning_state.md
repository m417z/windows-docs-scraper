# _DEVICE_DATA_SET_LB_PROVISIONING_STATE structure

## Description

The DEVICE_DATA_SET_LB_PROVISIONING_STATE structure is returned by an [IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes) request when requesting logical block provisioning information for a data set range.

## Members

### `Size`

The size of this structure, including the slab allocation bitmap, in bytes.

### `Version`

The version of this structure.

### `SlabSizeInBytes`

The size, in bytes, of a slab.

### `SlabOffsetDeltaInBytes`

The difference, in bytes, from the offset specified in the data set range to the starting slab position.

### `SlabAllocationBitMapBitCount`

The number of bits in the allocation bitmap mapping slabs for the data set range.

### `SlabAllocationBitMapLength`

The number of **ULONG** array values containing the slab allocation bitmap.

### `SlabAllocationBitMap`

A bitmap of slab allocations.

## Remarks

Provisioning state information is returned when the **Action** member of [DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes) is set to **DeviceDsmAction_Allocation**. The caller should include only one data set range in the system buffer at **DataSetRangesOffset**.

On return, the system buffer contains a [DEVICE_DSM_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes_output) structure followed by the DEVICE_DATA_SET_LB_PROVISIONING_STATE structure. The DEVICE_DATA_SET_LB_PROVISIONING_STATE structure begins at an offset from the beginning of the system buffer specified by **OutputBlockOffset** in DEVICE_DSM_OUTPUT.

Each bit in the allocation bitmap represents a slab mapping within the data set range requested. The bits correspond directly to the slabs in the data set range. This means that bit 0 in the bitmap marks the first slab in the range. A slab is mapped if the bit value = 1 and unmapped if the bit value = 0.

Space for **SlabAllocationBitMap** should be allocated based on the number of possible slabs in the requested data set range. The **SlabAllocationBitMapLength** of the bitmap returned is (*number of slabs* / 32) + ((*number of slabs* MOD 32) > 0 ? 1 : 0).

Slab size is determined by the **OptimalUnmapGranularity** member of [DEVICE_LB_PROVISIONING_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_lb_provisioning_descriptor) returned from an [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request. The length of the data set range provided should be a multiple of **OptimalUnmapGranularity**. When the range length is not a multiple of **OptimalUnmapGranularity**, it is reduced to be a multiple.

If the starting offset in the data set range is not aligned on a slab boundary, a multiple of **OptimalUnmapGranularity**, the offset will be adjusted to the next boundary. The difference between the requested offset and the adjusted offset is returned in **SlabOffsetDeltaInBytes**.

If the slab allocation total returned in **SlabAllocationBitMapBitCount** is not as expected because of data set range alignment or length adjustments, an additional request may be submitted with a data set range modified according to the values in both **SlabAllocationBitMapBitCount** and **SlabOffsetDeltaInBytes**. The new range will properly select the slabs left out of the bitmap returned by the previous request.

## See also

[DEVICE_DSM_ACTION Descriptions](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions)

[DEVICE_DSM_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_manage_data_set_attributes)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_manage_data_set_attributes)

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)