# D3D12DDI_RESOURCE_RANGED_BARRIER_0022 structure

## Description

Describes a resource ranged barrier.

## Members

### `hResource`

The handle of a resource. A null value means that the entire GPU cache must be flushed or invalidated. A non-null value means that the flush or invalidate action affects a smaller subset of the cache that can contain data for that resource.

### `Subresource`

A subresource. If the *Subresource* value is -1 or _ALL_SUBRESOURCES, then a flush or invalidate action need only affect the part of the cache where the entire *hResource* may reside. If *Subresource* is not _ALL_SUBRESOURCES, a valid subresource index is specified and the *Range* may further constrain the impact of the operation.

### `Range`

A range as a [D3D12DDI_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_range) structure. If the resource is a texture with an adapter-dependent layout, the range must be (0, UINT64_MAX), because only the driver knows where a particular subresource resides. When the resource is a buffer or texture with well-specified layout, the range fits within the subresource extent. Empty ranges are never passed.

## See also

[D3D12DDI_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_range)