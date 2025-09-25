## Description

The **D3D12DDI_GLOBAL_BARRIER_0088** structure describes a resource memory access barrier. This barrier is used by global, texture, and buffer barriers to indicate when resource memory must be made visible for a specific access type.

## Members

### `SyncBefore`

A [**D3D12DDI_BARRIER_SYNC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_sync) value that specifies the synchronization scope of all preceding GPU work that must be completed before executing the barrier.

### `SyncAfter`

A [**D3D12DDI_BARRIER_SYNC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_sync) value that specifies the synchronization scope of all subsequent GPU work that must wait until the barrier execution is finished.

### `AccessBefore`

A [**D3D12DDI_BARRIER_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_access) value that specifies the write accesses that must be flushed and finished before the barrier is executed.

### `AccessAfter`

A [**D3D12DDI_BARRIER_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_access) value that specifies the accesses that must be available for data written via **AccessBefore** after the barrier is executed.

## Remarks

See [Enhanced Barriers](https://learn.microsoft.com/windows-hardware/drivers/display/enhanced-barriers) for general information.

## See also

[**D3D12DDI_BARRIER_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_access)

[**D3D12DDI_BARRIER_SYNC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_sync)

[**D3D12DDIARG_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_barrier_0088)

[**PFND3D12DDI_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_barrier_0088)