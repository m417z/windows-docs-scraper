# DEVICE_DATA_SET_LB_PROVISIONING_STATE structure

## Description

Output structure for the **DeviceDsmAction_Allocation** action of the
[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)
control code.

## Members

### `Size`

The size of this structure, including the bitmap, in bytes.

### `Version`

The version of this structure.

### `SlabSizeInBytes`

The size of a slab, in bytes.

### `SlabOffsetDeltaInBytes`

If the range specified is not aligned to the **OptimalUnmapGranularity** as returned
in [DEVICE_LB_PROVISIONING_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_lb_provisioning_descriptor)
structure then the data represented in the **SlabAllocationBitMap** is offset from the
specified range by this amount.

### `SlabAllocationBitMapBitCount`

The number of relevant bits in the bitmap.

### `SlabAllocationBitMapLength`

The number of **DWORD**s in the bitmap array.

### `SlabAllocationBitMap`

The allocation bitmap containing one bit for each slab. If a bit is set then the corresponding slab is allocated. Otherwise, if a bit is clear, the corresponding slab is unallocated.

## Remarks

Provisioning state information is returned when the **Action** member of the
[DEVICE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_manage_data_set_attributes)
structure is set to **DeviceDsmAction_Allocation**. The caller should include only one data
set range in the system buffer at **DataSetRangesOffset**.

On return, the system buffer contains a
[DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_manage_data_set_attributes)
structure followed by the
**DEVICE_DATA_SET_LB_PROVISIONING_STATE**
structure. The
**DEVICE_DATA_SET_LB_PROVISIONING_STATE**
structure begins at an offset from the beginning of the system buffer specified by
**OutputBlockOffset** in
**DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT**.

Each bit in the allocation bitmap represents a slab mapping within the data set range requested. The bits
correspond directly to the slabs in the data set range. This means that bit 0 in the bitmap marks the first slab
in the range. A slab is mapped if the bit value = 1 and unmapped if the bit value = 0.

Space for **SlabAllocationBitMap** should be allocated based on the number of possible
slabs in the requested data set range. The **SlabAllocationBitMapLength** of the bitmap
returned is
`(number_of_slabs / 32) + ((number_of_slabs MOD 32) > 0 ? 1 : 0)`.

Slab size is determined by the **OptimalUnmapGranularity** member of
the [DEVICE_LB_PROVISIONING_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_lb_provisioning_descriptor)
structure returned from an
[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property)
control code. The length of the data set range provided should be a multiple of
**OptimalUnmapGranularity**. When the range length is not a multiple of
**OptimalUnmapGranularity**, it is reduced to be a multiple.

If the starting offset in the data set range is not aligned on a slab boundary, a multiple of
**OptimalUnmapGranularity**, the offset will be adjusted to the next boundary. The
difference between the requested offset and the adjusted offset is returned in
**SlabOffsetDeltaInBytes**.

If the slab allocation total returned in **SlabAllocationBitMapBitCount** is not as
expected because of data set range alignment or length adjustments, an additional request may be submitted with a
data set range modified according to the values in both **SlabAllocationBitMapBitCount**
and **SlabOffsetDeltaInBytes**. The new range will properly select the slabs left out of
the bitmap returned by the previous request.

If the requested slab size is too large (for example if it is larger than the maximum transfer length of the
HBA) then the
[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)
can fail with **ERROR_INVALID_PARAMETER**.

## See also

[DEVICE_LB_PROVISIONING_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_lb_provisioning_descriptor)

[Device Management Structures](https://learn.microsoft.com/windows/desktop/DevIO/device-management-structures)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)