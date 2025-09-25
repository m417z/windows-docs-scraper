# D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE enumeration

## Description

Specifies the type of access that an application is given to the specified resource(s) at the transition into a render pass.

## Constants

### `D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_DISCARD:0`

Indicates that your application doesn't have any dependency on the prior contents of the resource(s). You also shouldn't have any expectations about those contents, because a display driver may return the previously-written contents, or it may return uninitialized data. You can be assured that reading from the resource(s) won't hang the GPU, even if you do get undefined data back.
A read is defined as a traditional read from an unordered access view (UAV), a shader resource view (SRV), a constant buffer view (CBV), a vertex buffer view (VBV), an index buffer view (IBV), an IndirectArg binding/read, or a blend/depth-testing-induced read.

### `D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_PRESERVE`

Indicates that your application has a dependency on the prior contents of the resource(s), so the contents must be loaded from main memory.

### `D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_CLEAR`

Indicates that your application needs the resource(s) to be cleared to a specific value (a value that your application specifies). This clear occurs whether or not you interact with the resource(s) during the render pass. You specify the clear value at
[BeginRenderPass](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-beginrenderpass) time, in the **Clear** member of your [D3D12_RENDER_PASS_BEGINNING_ACCESS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_pass_beginning_access) structure.

### `D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_NO_ACCESS`

Indicates that your application will neither read from nor write to the resource(s) during the render pass. You would most likely use this value to indicate that you won't be accessing the depth/stencil plane for a depth/stencil view (DSV). You must pair this value with [D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_NO_ACCESS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_render_pass_ending_access_type) in the corresponding [D3D12_RENDER_PASS_ENDING_ACCESS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_pass_ending_access) structure.

## See also

[Rendering](https://learn.microsoft.com/windows/desktop/direct3d12/rendering)