# D3D10_BLEND_DESC structure

## Description

Describes the blend state.

## Members

### `AlphaToCoverageEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Determines whether or not to use [alpha-to-coverage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-blend-state) as a multisampling technique when setting a pixel to a rendertarget.

### `BlendEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Enable (or disable) blending. There are eight elements in this array; these correspond to the eight rendertargets that can be set to output-merger stage at one time.

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

A per-pixel write mask that allows control over which components can be written (see [D3D10_COLOR_WRITE_ENABLE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_color_write_enable)).

## Remarks

To see how blending is done, see [Output-Merger Stage (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage).

These are the default values for blend state.

| State | Default Value |
| --- | --- |
| AlphaToCoverageEnable | FALSE |
| BlendEnable[8] | FALSE (for all 8) |
| SrcBlend | D3D10_BLEND_ONE |
| DestBlend | D3D10_BLEND_ZERO |
| BlendOp | D3D10_BLEND_OP_ADD |
| SrcBlendAlpha | D3D10_BLEND_ONE |
| DestBlendAlpha | D3D10_BLEND_ZERO |
| BlendOpAlpha | D3D10_BLEND_OP_ADD |
| RenderTargetWriteMask[8] | D3D10_COLOR_WRITE_ENABLE_ALL (for all 8) |

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-structures)