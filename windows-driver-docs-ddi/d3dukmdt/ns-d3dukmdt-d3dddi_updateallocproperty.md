# D3DDDI_UPDATEALLOCPROPERTY structure

## Description

The **D3DDDI_UPDATEALLOCPROPERTY** structure is used to update properties of a memory allocation.

## Members

### `hPagingQueue`

[in] A Handle to the paging queue used to synchronize paging operations for this call.

### `hAllocation`

[in] A handle to the allocation that will be updated.

### `SupportedSegmentSet`

[in] An index for the new supported segment set. If the current supported segment set is the same, then this will be ignored.

### `PreferredSegment`

[in] An index for the new preferred segment set. If the current preferred segment set is the same, then this will be ignored.

### `Flags`

[in] The flags that will be used to update the allocation.

### `PagingFenceValue`

[out] The paging fence value that will be synchronized with before using the new allocation. Applies to the monitored fence synchronization object associated with hPagingQueue.

### `SetAccessedPhysically`

[in] When set, the driver will update the [**AccessedPhysically**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_updateallocproperty_flags) property of the allocation.

[in] Specifies whether the allocation is accessed by its physical address.

### `SetSupportedSegmentSet`

[in] Specifies whether the supported segment is set to a new value.

### `SetPreferredSegment`

[in] Specifies whether the preferred segment is set to a new value.

### `SetUnmoveable`

[in] When set, the driver will update the [**Unmoveable**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_updateallocproperty_flags) property of the allocation to indicate that the allocation is unmoveable.

### `Reserved`

This member is reserved and should be set to zero.

### `PropertyMaskValue`

[in] A member in the union that is contained in D3DDDI_UPDATEALLOCPROPERTY that can hold one 32-bit value that identifies how to update an allocation.

## See also

[**D3DDDI_UPDATEALLOCPROPERTY_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_updateallocproperty_flags)

[**D3DKMTUpdateAllocationProperty**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtupdateallocationproperty)