# D3D12_RENDER_PASS_ENDING_ACCESS_TYPE enumeration

## Description

Specifies the type of access that an application is given to the specified resource(s) at the transition out of a render pass.

## Constants

### `D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_DISCARD:0`

Indicates that your application won't have any future dependency on any data that you wrote to the resource(s) during this render pass. For example, a depth buffer that won't be textured from before it's written to again.

### `D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_PRESERVE`

Indicates that your application will have a dependency on the written contents of the resource(s) in the future, and so they must be preserved.

### `D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_RESOLVE`

Indicates that the resource(s)—for example, a multi-sample anti-aliasing (MSAA) surface—should be directly resolved to a separate resource at the conclusion of the render pass. For a tile-based deferred renderer (TBDR), this should ideally happen while the MSAA contents are still in the tile cache. You should ensure that the resolve destination is in the [D3D12_RESOURCE_STATE_RESOLVE_DEST](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states) resource state when the render pass ends. The resolve source is left in its initial resource state at the time the render pass ends. A resolve operation submitted by a render pass doesn't implicitly change the state of any resource.

### `D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_NO_ACCESS`

Indicates that your application will neither read from nor write to the resource(s) during the render pass. You would most likely use this value to indicate that you won't be accessing the depth/stencil plane for a depth/stencil view (DSV). You must pair this value with [D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_NO_ACCESS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_render_pass_beginning_access_type) in the corresponding [D3D12_RENDER_PASS_BEGINNING_ACCESS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_pass_beginning_access) structure.

## See also

[Rendering](https://learn.microsoft.com/windows/desktop/direct3d12/rendering)