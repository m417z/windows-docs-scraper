# D3D10_DEPTH_STENCIL_DESC structure

## Description

Describes depth-stencil state.

## Members

### `DepthEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A Boolean value that enables depth testing. The default value is **TRUE**.

### `DepthWriteMask`

Type: **[D3D10_DEPTH_WRITE_MASK](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_depth_write_mask)**

A member of the [D3D10_DEPTH_WRITE_MASK](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_depth_write_mask) enumerated type that identifies a portion of the depth-stencil buffer that can be modified by depth data. The default value is **D3D10_DEPTH_WRITE_MASK_ALL**.

### `DepthFunc`

Type: **[D3D10_COMPARISON_FUNC](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_comparison_func)**

A member of the [D3D10_COMPARISON_FUNC](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_comparison_func) enumerated type that defines how depth data is compared against existing depth data. The default value is **D3D10_COMPARISON_LESS**

### `StencilEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A Boolean value that enables stencil testing. The default value is **FALSE**.

### `StencilReadMask`

Type: **UINT8**

A value that identifies a portion of the depth-stencil buffer for reading stencil data. The default value is **D3D10_DEFAULT_STENCIL_READ_MASK**.

### `StencilWriteMask`

Type: **UINT8**

A value that identifies a portion of the depth-stencil buffer for writing stencil data. The default value is **D3D10_DEFAULT_STENCIL_WRITE_MASK**.

### `FrontFace`

Type: **[D3D10_DEPTH_STENCILOP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_depth_stencilop_desc)**

A [D3D10_DEPTH_STENCILOP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_depth_stencilop_desc) structure that identifies how to use the results of the depth test and the stencil test for pixels whose surface normal is facing toward the camera.

### `BackFace`

Type: **[D3D10_DEPTH_STENCILOP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_depth_stencilop_desc)**

A [D3D10_DEPTH_STENCILOP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_depth_stencilop_desc) structure that identifies how to use the results of the depth test and the stencil test for pixels whose surface normal is facing away from the camera.

## Remarks

Depth-stencil state controls how [depth-stencil](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) testing is performed by the [output-merger](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) stage.

The formats that support stenciling are DXGI_FORMAT_D24_UNORM_S8_UINT and DXGI_FORMAT_D32_FLOAT_S8X24_UINT.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-structures)