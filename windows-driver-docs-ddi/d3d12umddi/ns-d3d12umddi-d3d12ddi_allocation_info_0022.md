# D3D12DDI_ALLOCATION_INFO_0022 structure

## Description

Specifies allocation information.

## Members

### `hAllocation`

The handle of an allocation.

### `pSystemMem`

Pointer to a system memory location that is preallocated. If the allocation uses video memory, specify null.

### `pPrivateDriverData`

Pointer to a buffer that contains optional private driver data.

### `PrivateDriverDataSize`

Size of the private driver data buffer.

### `VidPnSourceId`

A zero-based ID of the video present source in a path of a video present network topology.

### `Flags`

Flags that identify the type of the allocation information as a [D3D12DDI_ALLOCATION_INFO_FLAGS_0022](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_allocation_info_flags_0022) value.

### `GpuVirtualAddress`

A virtual address in the GPU.

### `Priority`

A priority for the allocation.

### `Reserved`

Reserved.

## See also

[D3D12DDI_ALLOCATION_INFO_FLAGS_0022](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_allocation_info_flags_0022)