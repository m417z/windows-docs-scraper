## Description

A **D3D12DDI_BUFFER_BARRIER_0088** structure describes access transitions for buffers.

## Members

### `SyncBefore`

A [**D3D12DDI_BARRIER_SYNC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_sync) value that specifies the synchronization scope of all preceding GPU work that must be completed before executing the barrier.

### `SyncAfter`

A [**D3D12DDI_BARRIER_SYNC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_sync) value that specifies the synchronization scope of all subsequent GPU work that must wait until the barrier execution is finished.

### `AccessBefore`

A [**D3D12DDI_BARRIER_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_access) value that specifies the access state of the buffer preceding the barrier execution.

### `AccessAfter`

A [**D3D12DDI_BARRIER_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_access) value that specifies the access state of the buffer upon completion of barrier execution.

### `hResource`

The handle of the buffer resource using the barrier.

## Remarks

See [Enhanced Barriers](https://learn.microsoft.com/windows-hardware/drivers/display/enhanced-barriers) for general information.

## See also

[**D3D12DDI_BARRIER_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_access)

[**D3D12DDI_BARRIER_SYNC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_sync)

[**D3D12DDIARG_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_barrier_0088)

[**PFND3D12DDI_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_barrier_0088)