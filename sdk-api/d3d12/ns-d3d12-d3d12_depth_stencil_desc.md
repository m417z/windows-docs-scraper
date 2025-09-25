# D3D12_DEPTH_STENCIL_DESC structure

## Description

Describes depth-stencil state.

## Members

### `DepthEnable`

Specifies whether to enable depth testing. Set this member to **TRUE** to enable depth testing.

### `DepthWriteMask`

A [D3D12_DEPTH_WRITE_MASK](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_depth_write_mask)-typed value that identifies a portion of the depth-stencil buffer that can be modified by depth data.

### `DepthFunc`

A [D3D12_COMPARISON_FUNC](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_comparison_func)-typed value that identifies a function that compares depth data against existing depth data.

### `StencilEnable`

Specifies whether to enable stencil testing. Set this member to **TRUE** to enable stencil testing.

### `StencilReadMask`

Identify a portion of the depth-stencil buffer for reading stencil data.

### `StencilWriteMask`

Identify a portion of the depth-stencil buffer for writing stencil data.

### `FrontFace`

A [D3D12_DEPTH_STENCILOP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencilop_desc) structure that describes how to use the results of the depth test and the stencil test for pixels whose surface normal is facing towards the camera.

### `BackFace`

A [D3D12_DEPTH_STENCILOP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencilop_desc) structure that describes how to use the results of the depth test and the stencil test for pixels whose surface normal is facing away from the camera.

## Remarks

A [D3D12_GRAPHICS_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc) object contains a depth-stencil-state structure that controls how depth-stencil testing is performed by the output-merger stage.

This table shows the default values of depth-stencil states.

| State | Default Value |
| --- | --- |
| DepthEnable | TRUE |
| DepthWriteMask | D3D12_DEPTH_WRITE_MASK_ALL |
| DepthFunc | D3D12_COMPARISON_FUNC_LESS |
| StencilEnable | FALSE |
| StencilReadMask | D3D12_DEFAULT_STENCIL_READ_MASK |
| StencilWriteMask | D3D12_DEFAULT_STENCIL_WRITE_MASK |
| FrontFace.StencilFailOp<br><br>and<br><br>BackFace.StencilFailOp | D3D12_STENCIL_OP_KEEP |
| FrontFace.StencilDepthFailOp<br><br>and<br><br>BackFace.StencilDepthFailOp | D3D12_STENCIL_OP_KEEP |
| FrontFace.StencilPassOp<br><br>and<br><br>BackFace.StencilPassOp | D3D12_STENCIL_OP_KEEP |
| FrontFace.StencilFunc<br><br>and<br><br>BackFace.StencilFunc | D3D12_COMPARISON_FUNC_ALWAYS |

The formats that support stenciling are DXGI_FORMAT_D24_UNORM_S8_UINT and DXGI_FORMAT_D32_FLOAT_S8X24_UINT.

## See also

[CD3DX12_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-depth-stencil-desc)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)