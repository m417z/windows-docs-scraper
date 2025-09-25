## Description

The **D3D12DDI_TEXTURE_BARRIER_FLAGS_0088** enumeration specifies flags for texture resource barriers.

## Constants

### `D3D12DDI_TEXTURE_BARRIER_FLAG_NONE:0x0`

No flags are specified.

### `D3D12DDI_TEXTURE_BARRIER_FLAG_DISCARD:0x1`

This flag can only be used when [**LayoutBefore**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_texture_barrier_0088) is **D3D12_BARRIER_LAYOUT_UNDEFINED**. Typically, this flag is used to initialize compression metadata as part of a barrier that activates an aliased resource. The [**Subresource**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_texture_barrier_0088) member must indicate all subresources. Without this flag, a full resource Clear, Copy or Discard is required before use.

## Remarks

See [Enhanced Barriers](https://learn.microsoft.com/windows-hardware/drivers/display/enhanced-barriers) for general information.

## See also

[**D3D12DDI_TEXTURE_BARRIER_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_texture_barrier_0088)