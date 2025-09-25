# D3D12DDI_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS_0053 structure

## Description

Used in the [D3D12DDI_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_render_pass_ending_access_resolve_parameters_0053) structure, to specify the subresource to resolve while the Render Pass is ending access.

## Members

### `SrcSubresource`

A handle to the command list structure that the resolve subresource will be transitioned to at the time the Render Pass ends.

### `DstSubresource`

A handle to the command list that the resolve subresource destination will be at the time the Render Pass ends.

### `DstX`

The X coordinate of the left-most edge of the destination region. The width of the destination region is the same as the width of the source rectangle.

### `DstY`

The Y coordinate of the top-most edge of the destination region. The height of the destination region is the same as the height of the source rectangle.

### `SrcRect`

Specifies the rectangular region of the source subresource to be resolved.

## Remarks

## See also