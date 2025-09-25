# D3D12_RENDER_PASS_ENDING_ACCESS structure

## Description

Describes the access to resource(s) that is requested by an application at the transition out of a render pass.

## Members

### `Type`

A [D3D12_RENDER_PASS_ENDING_ACCESS_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_render_pass_ending_access_type). The type of access being requested.

### `Resolve`

A [D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_pass_ending_access_resolve_parameters). Appropriate when **Type** is [D3D12_RENDER_PASS_ENDING_ACCESS_TYPE_RESOLVE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_render_pass_ending_access_type). Description of the resource to resolve to.

## See also

[Rendering](https://learn.microsoft.com/windows/desktop/direct3d12/rendering)