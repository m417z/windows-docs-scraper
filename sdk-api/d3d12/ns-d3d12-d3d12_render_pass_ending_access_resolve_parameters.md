# D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS structure

## Description

Describes a resource to resolve to at the conclusion of a render pass.

## Members

### `pSrcResource`

A pointer to an [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource). The source resource.

### `pDstResource`

A pointer to an [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource). The destination resource.

### `SubresourceCount`

A **UINT**. The number of subresources.

### `pSubresourceParameters`

A pointer to a constant array of [D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_pass_ending_access_resolve_subresource_parameters). These subresources can be a subset of the render target's array slices, but you can't target subresources that aren't part of the render target view (RTV) or the depth/stencil view (DSV).

> [!NOTE]
> This pointer is directly referenced by the command list, and the memory for this array must remain alive and intact until [EndRenderPass](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-endrenderpass) is called.

### `Format`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format). The data format of the resources.

### `ResolveMode`

A [D3D12_RESOLVE_MODE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resolve_mode). The resolve operation.

### `PreserveResolveSource`

A **BOOL**. **TRUE** to preserve the resolve source, otherwise **FALSE**.

## See also

[Rendering](https://learn.microsoft.com/windows/desktop/direct3d12/rendering)