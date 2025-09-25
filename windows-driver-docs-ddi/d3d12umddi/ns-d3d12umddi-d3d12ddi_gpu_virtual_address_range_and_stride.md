# D3D12DDI_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE structure

## Description

Describes the GPU virtual address range and stride.

## Members

### `StartAddress`

The beginning of a virtual address range.

### `SizeInBytes`

The size of the virtual address, in bytes.

### `StrideInBytes`

Defines indexing stride, such as for vertices. Only the bottom 32 bits get used. The field is 64-bits purely to make alignment of containing structures clean/obvious everywhere.

## Remarks

Used in the [D3D12DDIARG_DISPATCH_RAYS_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_dispatch_rays_0054) structure.

## See also