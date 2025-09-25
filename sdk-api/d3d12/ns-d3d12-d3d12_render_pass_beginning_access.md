## Description

Describes the access to resource(s) that is requested by an application at the transition into a render pass.

## Members

### `Type`

A [D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_render_pass_beginning_access_type). The type of access being requested.

### `Clear`

A [D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_render_pass_beginning_access_clear_parameters). Appropriate when **Type** is [D3D12_RENDER_PASS_BEGINNING_ACCESS_TYPE_CLEAR](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_render_pass_beginning_access_type). The clear value to which resource(s) should be cleared.

## See also

[Rendering](https://learn.microsoft.com/windows/win32/direct3d12/rendering)