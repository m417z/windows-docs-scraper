# D3D12_MEMORY_POOL enumeration

## Description

Specifies the memory pool for the heap.

## Constants

### `D3D12_MEMORY_POOL_UNKNOWN:0`

The memory pool is unknown.

### `D3D12_MEMORY_POOL_L0:1`

The memory pool is L0.
L0 is the physical system memory pool.
When the adapter is discrete/NUMA, this pool has greater bandwidth for the CPU and less bandwidth for the GPU.
When the adapter is UMA, this pool is the only one which is valid.

### `D3D12_MEMORY_POOL_L1:2`

The memory pool is L1.
L1 is typically known as the physical video memory pool.
L1 is only available when the adapter is discrete/NUMA, and has greater bandwidth for the GPU and cannot even be accessed by the CPU.
When the adapter is UMA, this pool is not available.

## Remarks

This enum is used by the [D3D12_HEAP_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_heap_properties) structure.

When the adapter is UMA, D3D12_MEMORY_POOL_L0 and DXGI_MEMORY_SEGMENT_GROUP_LOCAL refer to the same memory.

When

 the adapter is not UMA:
D3D12_MEMORY_POOL_L0 and DXGI_MEMORY_SEGMENT_GROUP_NON_LOCAL refer to the same memory.
D3D12_MEMORY_POOL_L1 and DXGI_MEMORY_SEGMENT_GROUP_LOCAL refer to the same memory.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)

[Descriptor Heaps](https://learn.microsoft.com/windows/desktop/direct3d12/descriptor-heaps)