## Description

A **D3D12DDI_MEMORY_POOL** value specifies the memory pool for the heap.

## Constants

### `D3D12DDI_MEMORY_POOL_L0:0`

The memory pool is L0, which is the physical system memory pool. When the adapter is discrete/NUMA, this pool has greater bandwidth for the CPU and less bandwidth for the GPU. When the adapter is UMA, this pool is the only one that is valid.

### `D3D12DDI_MEMORY_POOL_L1:1`

The memory pool is L1, which is typically known as the physical (local) video memory pool. L1 is only available when the adapter is discrete/NUMA, and has greater bandwidth for the GPU and cannot even be accessed by the CPU. When the adapter is UMA, this pool is not available.

## Remarks

## See also

[**D3D12DDIARG_CREATEHEAP_0001**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createheap_0001)