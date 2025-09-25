# D3D12DDI_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS structure

## Description

Holds the parameters used in the [D3D12DDI_RENDER_PASS_ENDING_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_ending_access) structure, when the Render Pass is ending access.

## Members

### `hSrcResource`

A handle to the command list structure that the resolve source will be transitioned to at the time the Render Pass ends.

### `hDstResource`

A handle to the command list that the resolve destination will be at the time the Render Pass ends.

### `SubresourceCount`

The count of subresources that are a part of the command list.

### `pSubresourceParameters`

A pointer to a [D3D12DDI_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_ending_access_resolve_subresource_parameters) structure that represents the subresource parameters to resolve while the Render Pass is ending.

### `Format`

The format, represented in DXGI_FORMAT.

### `ResolveMode`

The [resolve mode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resolve_mode) to use while the Render Pass is ending.

## Remarks

## See also