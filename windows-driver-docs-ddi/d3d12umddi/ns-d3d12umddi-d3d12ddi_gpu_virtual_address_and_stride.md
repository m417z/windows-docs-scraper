# D3D12DDI_GPU_VIRTUAL_ADDRESS_AND_STRIDE structure

## Description

Describes the GPU virtual address and stride.

## Members

### `StartAddress`

The beginning of a virtual address range.

### `StrideInBytes`

Defines the indexing stride in bytes, such as for vertices. Only the bottom 32 bits get used. The field is 64 bits purely to make alignment of containing structures clean and obvious everywhere.

## Remarks

## See also