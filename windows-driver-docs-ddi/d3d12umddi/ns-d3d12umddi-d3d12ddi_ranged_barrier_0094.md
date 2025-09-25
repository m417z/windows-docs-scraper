## Description

The **D3D12DDI_RANGED_BARRIER_0094** structure describes a resource ranged barrier. This structure replaces the legacy [**D3D12DDI_RESOURCE_RANGED_BARRIER_0022**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_resource_ranged_barrier_0022) structure.

## Members

### `Flags`

A [**D3D12DDI_RANGED_BARRIER_FLAGS_0094**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_ranged_barrier_flags_0094) value that specifies flags for the ranged barrier.

### `hResource`

The handle of the resource using the barrier. A NULL value means that the entire GPU cache must be flushed or invalidated. A non-NULL value means that the flush or invalidate action affects a smaller subset of the cache that can contain data for that resource.

### `Subresource`

A [**D3D12DDI_BARRIER_SUBRESOURCE_RANGE_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_barrier_subresource_range_0088) structure that specifies the range of subresources being barriered.

### `Range`

A [**D3D12DDI_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_range) structure that describes a memory range.

## Remarks

Enhanced barriers fully deprecate the legacy ResourceBarrier DDIs. This includes the ranged barriers used internally by AtomicCopy commands.

See [Enhanced Barriers](https://learn.microsoft.com/windows-hardware/drivers/display/enhanced-barriers) for general information.

## See also

[**D3D12DDI_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_range)

[**D3D12DDIARG_BARRIER_0094**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_barrier_0094)

[**PFND3D12DDI_BARRIER_0094**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_barrier_0094)