# D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS structure

## Description

Describes the subresources involved in resolving at the conclusion of a render pass.

## Members

### `SrcSubresource`

A **UINT**. The source subresource.

### `DstSubresource`

A **UINT**. The destination subresource.

### `DstX`

A **UINT**. The x coordinate within the destination subresource.

### `DstY`

A **UINT**. The y coordinate within the destination subresource.

### `SrcRect`

A [D3D12_RECT](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-rect). The rectangle within the source subresource.

## See also

[Rendering](https://learn.microsoft.com/windows/desktop/direct3d12/rendering)