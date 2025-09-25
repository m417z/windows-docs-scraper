# D3D12DDICB_ALLOCATE_0022 structure

## Description

Specifies information for use in an allocation callback function.

## Members

### `pPrivateDriverData`

A pointer to a buffer that contains optional private driver data.

### `PrivateDriverDataSize`

Size of the private driver data.

### `hResource`

The handle of a resource.

### `hKMResource`

Reserved.

### `NumAllocations`

The number of allocations.

### `pAllocationInfo`

Allocation as a [D3D12DDI_ALLOCATION_INFO_0022](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_allocation_info_0022) structure.

## See also

[D3D12DDI_ALLOCATION_INFO_0022](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_allocation_info_0022)