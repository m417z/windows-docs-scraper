# D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE structure

## Description

Represents a GPU virtual address and indexing stride.

## Members

### `StartAddress`

The beginning of the virtual address range.

### `StrideInBytes`

Defines indexing stride, such as for vertices. Only the bottom 32 bits are used. The field is 64 bits to make alignment of containing structures consistent everywhere.