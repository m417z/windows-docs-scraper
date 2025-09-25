## Description

The **D3D12DDI_RANGED_BARRIER_0088** structure describes a resource ranged barrier. This structure replaces the legacy [**D3D12DDI_RESOURCE_RANGED_BARRIER_0022**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_resource_ranged_barrier_0022) structure.

## Members

### `SyncBefore`

A [**D3D12DDI_BARRIER_SYNC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_sync) value that specifies the synchronization scope of all preceding GPU work that must be completed before executing the barrier.

### `SyncAfter`

A [**D3D12DDI_BARRIER_SYNC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_sync) value that specifies the synchronization scope of all subsequent GPU work that must wait until the barrier execution is finished.

### `AccessBefore`

A [**D3D12DDI_BARRIER_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_access) value that specifies the write accesses that must be flushed and finished before the barrier is executed.

### `AccessAfter`

A [**D3D12DDI_BARRIER_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_access) value that specifies the accesses that must be available for data written via **AccessBefore** after the barrier is executed.

### `Flags`

A [**D3D12DDI_RANGED_BARRIER_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_ranged_barrier_flags) value that specifies flags for the ranged barrier.

### `hResource`

The handle of the resource using the barrier. A NULL value means that the entire GPU cache must be flushed or invalidated. A non-NULL value means that the flush or invalidate action affects a smaller subset of the cache that can contain data for that resource.

### `Subresources`

A [**D3D12DDI_BARRIER_SUBRESOURCE_RANGE_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_barrier_subresource_range_0088) structure that specifies the range of subresources being barriered.

### `Range`

A [**D3D12DDI_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_range) structure that describes a memory range.

## Remarks

Enhanced barriers fully deprecate the legacy ResourceBarrier DDIs. This includes the ranged barriers used internally by AtomicCopy commands.

See [Enhanced Barriers](https://learn.microsoft.com/windows-hardware/drivers/display/enhanced-barriers) for general information.

## See also

[**D3D12DDI_BARRIER_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_access)

[**D3D12DDI_BARRIER_SYNC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_sync)

[**D3D12DDI_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_range)

[**D3D12DDIARG_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_barrier_0088)

[**PFND3D12DDI_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_barrier_0088)