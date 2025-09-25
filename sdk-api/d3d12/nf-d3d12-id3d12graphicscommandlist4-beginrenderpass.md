## Description

Marks the beginning of a render pass by binding a set of output resources for the duration of the render pass. These bindings are to one or more render target views (RTVs), and/or to a depth stencil view (DSV).

## Parameters

### `NumRenderTargets`

A **UINT**. The number of render targets being bound.

### `pRenderTargets`

A pointer to a constant [D3D12_RENDER_PASS_RENDER_TARGET_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_render_pass_render_target_desc), which describes bindings (fixed for the duration of the render pass) to one or more render target views (RTVs), as well as their beginning and ending access characteristics.

### `pDepthStencil`

A pointer to a constant [D3D12_RENDER_PASS_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_render_pass_depth_stencil_desc), which describes a binding (fixed for the duration of the render pass) to a depth stencil view (DSV), as well as its beginning and ending access characteristics.

### `Flags`

A [D3D12_RENDER_PASS_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_render_pass_flags). The nature/requirements of the render pass; for example, whether it is a suspending or a resuming render pass, or whether it wants to write to unordered access view(s).

## See also

[EndRenderPass](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-endrenderpass)

[ID3D12GraphicsCommandList4](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12graphicscommandlist4)

[Rendering](https://learn.microsoft.com/windows/win32/direct3d12/rendering)