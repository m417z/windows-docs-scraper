# D3D11_DEPTH_STENCIL_DESC structure

## Description

Describes depth-stencil state.

## Members

### `DepthEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Enable depth testing.

### `DepthWriteMask`

Type: **[D3D11_DEPTH_WRITE_MASK](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_depth_write_mask)**

Identify a portion of the depth-stencil buffer that can be modified by depth data (see [D3D11_DEPTH_WRITE_MASK](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_depth_write_mask)).

### `DepthFunc`

Type: **[D3D11_COMPARISON_FUNC](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_comparison_func)**

A function that compares depth data against existing depth data. The function options are listed in [D3D11_COMPARISON_FUNC](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_comparison_func).

### `StencilEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Enable stencil testing.

### `StencilReadMask`

Type: **UINT8**

Identify a portion of the depth-stencil buffer for reading stencil data.

### `StencilWriteMask`

Type: **UINT8**

Identify a portion of the depth-stencil buffer for writing stencil data.

### `FrontFace`

Type: **[D3D11_DEPTH_STENCILOP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_depth_stencilop_desc)**

Identify how to use the results of the depth test and the stencil test for pixels whose surface normal is facing towards the camera (see [D3D11_DEPTH_STENCILOP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_depth_stencilop_desc)).

### `BackFace`

Type: **[D3D11_DEPTH_STENCILOP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_depth_stencilop_desc)**

Identify how to use the results of the depth test and the stencil test for pixels whose surface normal is facing away from the camera (see [D3D11_DEPTH_STENCILOP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_depth_stencilop_desc)).

## Remarks

Pass a pointer to **D3D11_DEPTH_STENCIL_DESC** to the [ID3D11Device::CreateDepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createdepthstencilstate) method to create the depth-stencil state object.

Depth-stencil state controls how depth-stencil testing is performed by the output-merger stage.

The following table shows the default values of depth-stencil states.

| State | Default Value |
| --- | --- |
| DepthEnable | TRUE |
| DepthWriteMask | D3D11_DEPTH_WRITE_MASK_ALL |
| DepthFunc | D3D11_COMPARISON_LESS |
| StencilEnable | FALSE |
| StencilReadMask | D3D11_DEFAULT_STENCIL_READ_MASK |
| StencilWriteMask | D3D11_DEFAULT_STENCIL_WRITE_MASK |
| FrontFace.StencilFunc<br><br>and<br><br>BackFace.StencilFunc | D3D11_COMPARISON_ALWAYS |
| FrontFace.StencilDepthFailOp<br><br>and<br><br>BackFace.StencilDepthFailOp | D3D11_STENCIL_OP_KEEP |
| FrontFace.StencilPassOp<br><br>and<br><br>BackFace.StencilPassOp | D3D11_STENCIL_OP_KEEP |
| FrontFace.StencilFailOp<br><br>and<br><br>BackFace.StencilFailOp | D3D11_STENCIL_OP_KEEP |

The formats that support stenciling are DXGI_FORMAT_D24_UNORM_S8_UINT and DXGI_FORMAT_D32_FLOAT_S8X24_UINT.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)