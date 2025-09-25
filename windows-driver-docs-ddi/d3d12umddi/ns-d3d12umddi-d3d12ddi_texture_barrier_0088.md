## Description

A **D3D12DDI_TEXTURE_BARRIER_0088** structure describes access transitions for textures.

## Members

### `SyncBefore`

A [**D3D12DDI_BARRIER_SYNC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_sync) value that specifies the synchronization scope of all preceding GPU work that must be completed before executing the barrier.

### `SyncAfter`

A [**D3D12DDI_BARRIER_SYNC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_sync) value that specifies the synchronization scope of all subsequent GPU work that must wait until the barrier execution is finished.

### `AccessBefore`

A [**D3D12DDI_BARRIER_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_access) value that specifies the access state of the texture preceding the barrier execution.

### `AccessAfter`

A [**D3D12DDI_BARRIER_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_access) value that specifies the access state of the texture upon completion of barrier execution.

### `LayoutBefore`

A [**D3D12DDI_BARRIER_LAYOUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_layout) value that specifies the layout of the texture preceding the barrier execution.

### `LayoutAfter`

A [**D3D12DDI_BARRIER_LAYOUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_layout) value that specifies the layout of the texture upon completion of barrier execution.

### `hResource`

The handle of the texture resource using the barrier.

### `Subresources`

A [**D3D12DDI_BARRIER_SUBRESOURCE_RANGE_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_barrier_subresource_range_0088) structure that specifies the range of texture subresources being barriered.

### `Flags`

A [**D3D12DDI_TEXTURE_BARRIER_FLAGS_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_texture_barrier_flags_0088) value that specifies optional flags.

## Remarks

See [Enhanced Barriers](https://learn.microsoft.com/windows-hardware/drivers/display/enhanced-barriers) for general information.

### Synchronization

Graphics processors are designed to execute as much work in parallel as possible. Any GPU work that depends on previous GPU work must be synchronized before accessing dependent data. The **SyncBefore** and **SyncAfter** values are logical bitfield masks that identify any work to synchronize.

A Barrier must wait for all preceding command **SyncBefore** scopes to complete before executing the barrier. Similarly, a Barrier must block all subsequent **SyncAfter** scopes until the barrier completes.

### Layout transitions

Texture subresources can use different layouts for various access methods. For example, textures are often compressed when used as a render target or depth stencil and are often uncompressed for shader read or copy commands. Texture Barriers use **LayoutBefore** and **LayoutAfter** to describe layout transitions.

Layout transitions are only needed for textures, therefore they are expressed only in this data structure.

Both **LayoutBefore** and **LayoutAfter** must be compatible with the type of queue performing the barrier. For example, a compute queue cannot transition a subresource into or out of **D3D12_BARRIER_LAYOUT_RENDER_TARGET**.

To provide well-defined barrier ordering, the layout of a subresource after completing a sequence of barriers is the final **LayoutAfter** in the sequence.

## See also

[**D3D12DDI_BARRIER_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_access)

[**D3D12DDI_BARRIER_LAYOUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_layout)

[**D3D12DDI_BARRIER_SUBRESOURCE_RANGE_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_barrier_subresource_range_0088)

[**D3D12DDI_BARRIER_SYNC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_barrier_sync)

[**D3D12DDI_TEXTURE_BARRIER_FLAGS_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_texture_barrier_flags_0088)

[**D3D12DDIARG_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_barrier_0088)

[**PFND3D12DDI_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_barrier_0088)