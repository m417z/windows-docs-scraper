# D3D11_RENDER_TARGET_BLEND_DESC structure

## Description

Describes the blend state for a render target.

## Members

### `BlendEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Enable (or disable) blending.

### `SrcBlend`

Type: **[D3D11_BLEND](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_blend)**

This [blend option](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_blend) specifies the operation to perform on the RGB value that the pixel shader outputs. The **BlendOp** member defines how to combine the **SrcBlend** and **DestBlend** operations.

### `DestBlend`

Type: **[D3D11_BLEND](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_blend)**

This [blend option](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_blend) specifies the operation to perform on the current RGB value in the render target. The **BlendOp** member defines how to combine the **SrcBlend** and **DestBlend** operations.

### `BlendOp`

Type: **[D3D11_BLEND_OP](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_blend_op)**

This [blend operation](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_blend_op) defines how to combine the **SrcBlend** and **DestBlend** operations.

### `SrcBlendAlpha`

Type: **[D3D11_BLEND](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_blend)**

This [blend option](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_blend) specifies the operation to perform on the alpha value that the pixel shader outputs. Blend options that end in _COLOR are not allowed. The **BlendOpAlpha** member defines how to combine the **SrcBlendAlpha** and **DestBlendAlpha** operations.

### `DestBlendAlpha`

Type: **[D3D11_BLEND](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_blend)**

This [blend option](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_blend) specifies the operation to perform on the current alpha value in the render target. Blend options that end in _COLOR are not allowed. The **BlendOpAlpha** member defines how to combine the **SrcBlendAlpha** and **DestBlendAlpha** operations.

### `BlendOpAlpha`

Type: **[D3D11_BLEND_OP](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_blend_op)**

This [blend operation](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_blend_op) defines how to combine the **SrcBlendAlpha** and **DestBlendAlpha** operations.

### `RenderTargetWriteMask`

Type: **UINT8**

A write mask.

## Remarks

You specify an array of **D3D11_RENDER_TARGET_BLEND_DESC** structures in the **RenderTarget** member of the [D3D11_BLEND_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_blend_desc) structure to describe the blend states for render targets; you can bind up to eight render targets to the [output-merger stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) at one time.

For info about how blending is done, see the [output-merger stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage).

Here are the default values for blend state.

| State | Default Value |
| --- | --- |
| BlendEnable | FALSE |
| SrcBlend | D3D11_BLEND_ONE |
| DestBlend | D3D11_BLEND_ZERO |
| BlendOp | D3D11_BLEND_OP_ADD |
| SrcBlendAlpha | D3D11_BLEND_ONE |
| DestBlendAlpha | D3D11_BLEND_ZERO |
| BlendOpAlpha | D3D11_BLEND_OP_ADD |
| RenderTargetWriteMask | D3D11_COLOR_WRITE_ENABLE_ALL |

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)