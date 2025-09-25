# D3D10_RENDER_TARGET_BLEND_DESC1 structure

## Description

Describes the blend state for a render target for a Direct3D 10.1 device

## Members

### `BlendEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Enable (or disable) blending.

### `SrcBlend`

Type: **[D3D10_BLEND](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_blend)**

This [blend option](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_blend) specifies the first RGB data source and includes an optional pre-blend operation.

### `DestBlend`

Type: **[D3D10_BLEND](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_blend)**

This [blend option](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_blend) specifies the second RGB data source and includes an optional pre-blend operation.

### `BlendOp`

Type: **[D3D10_BLEND_OP](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_blend_op)**

This [blend operation](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_blend_op) defines how to combine the RGB data sources.

### `SrcBlendAlpha`

Type: **[D3D10_BLEND](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_blend)**

This [blend option](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_blend) specifies the first alpha data source and includes an optional pre-blend operation. Blend options that end in _COLOR are not allowed.

### `DestBlendAlpha`

Type: **[D3D10_BLEND](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_blend)**

This [blend option](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_blend) specifies the second alpha data source and includes an optional pre-blend operation. Blend options that end in _COLOR are not allowed.

### `BlendOpAlpha`

Type: **[D3D10_BLEND_OP](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_blend_op)**

This [blend operation](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_blend_op) defines how to combine the alpha data sources.

### `RenderTargetWriteMask`

Type: **UINT8**

A write mask.

## Remarks

To see how blending is done, see [Output-Merger Stage (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage).

These are the default values for blend state.

| State | Default Value |
| --- | --- |
| BlendEnable | FALSE |
| SrcBlend | D3D10_BLEND_ONE |
| DestBlend | D3D10_BLEND_ZERO |
| BlendOp | D3D10_BLEND_OP_ADD |
| SrcBlendAlpha | D3D10_BLEND_ONE |
| DestBlendAlpha | D3D10_BLEND_ZERO |
| BlendOpAlpha | D3D10_BLEND_OP_ADD |
| RenderTargetWriteMask | D3D10_COLOR_WRITE_ENABLE_ALL |

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-structures)